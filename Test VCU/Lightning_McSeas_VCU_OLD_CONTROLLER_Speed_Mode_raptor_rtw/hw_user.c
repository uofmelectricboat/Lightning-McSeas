/*****************************************************************************
   hw_user.c
   Generated By:
   Raptor 2021b_1.0.14409 (6115)
   Matlab (R2021b) 9.11

   Copyright (c) 2018 New Eagle Products, Inc.
   All rights reserved.

   Code Generated at: Mon Apr 17 16:47:54 2023
 *****************************************************************************/

#include "Lightning_McSeas_VCU_OLD_CONTROLLER_Speed_Mode.h"
#include "Lightning_McSeas_VCU_OLD_CONTROLLER_Speed_Mode_private.h"

//#include "sdk_system.h"
#include "sdk_can.h"
#include "can.h"
#include "hw_user.h"
#include "sdk_scheduler.h"
#include "sdk_interface.h"
#include "sdk_io_dictionary.h"

/*****************************************************************************
   DEFINES
 *****************************************************************************/
#define CAN_FREQUENCY                  10                        // ms
#define TIMESUB(A,B)                   ((A >= B) ? (A-B):(0xFFFFFFFF-B+1+A))

/*****************************************************************************
   CONSTANTS
 *****************************************************************************/
uint8_t app_is_in_shutdown = 0;

/*****************************************************************************
   THREAD INDEXES
 *****************************************************************************/
uint8_t g_Thread_Foreground_Idx;
uint8_t g_Thread_Background_Idx;

/*****************************************************************************
   CAN QUEUE DEFINITONS
 *****************************************************************************/
extern void CANFrame_Queue_Create(CANFrame_Queue_t* queue, CANFrame_t data[],
  uint8_t queueSize);

/* Create global TX Queue for CAN1 */
CANFrame_t CAN1_TxQueue_data[20];
CANFrame_Queue_t g_CAN1_TxQueue;
CANFrame_t CAN1_RxQueue_data[16];
CANFrame_Queue_t g_CAN1_RxQueue;

/* Create global TX Queue for CAN2 */
CANFrame_t CAN2_TxQueue_data[20];
CANFrame_Queue_t g_CAN2_TxQueue;
CANFrame_t CAN2_RxQueue_data[16];
CANFrame_Queue_t g_CAN2_RxQueue;

/* Create global TX Queue for CAN3 */
CANFrame_t CAN3_TxQueue_data[1];
CANFrame_Queue_t g_CAN3_TxQueue;
CANFrame_t CAN3_RxQueue_data[1];
CANFrame_Queue_t g_CAN3_RxQueue;

/* Create global TX Queue for CAN4 */
CANFrame_t CAN4_TxQueue_data[1];
CANFrame_Queue_t g_CAN4_TxQueue;
CANFrame_t CAN4_RxQueue_data[1];
CANFrame_Queue_t g_CAN4_RxQueue;

/* Create global TX Queue for CAN5 */
CANFrame_t CAN5_TxQueue_data[1];
CANFrame_Queue_t g_CAN5_TxQueue;
CANFrame_t CAN5_RxQueue_data[1];
CANFrame_Queue_t g_CAN5_RxQueue;

/* Create global TX Queue for CAN6 */
CANFrame_t CAN6_TxQueue_data[1];
CANFrame_Queue_t g_CAN6_TxQueue;
CANFrame_t CAN6_RxQueue_data[1];
CANFrame_Queue_t g_CAN6_RxQueue;

/*****************************************************************************
   TIMER CALLBACK FUNCTIONS
 *****************************************************************************/
void Thread_ModelStep()
{
  if (!app_is_in_shutdown) {
    Lightning_McSeas_VCU_OLD_CONTROLLER_Speed_Mode_step();

    /* Get model outputs here */
  }
}

void Thread_Foreground()
{
  {                                    /* Line 1193 */
    if (!app_is_in_shutdown) {
      Timer_ooqlV();
    }                                  /* Line 1220 */

    Timed_Trigger_XCP();
  }

  Thread_ModelStep();
}

void Thread_Background()
{
  Timer_BGND_9AY_V();
}

extern void ClearLongestTaskRun( uint16_t task_id );
void ClearLongestRunTimers()
{
  extern uint8_t g_Thread_Foreground_Idx;
  ClearLongestTaskRun( g_Thread_Foreground_Idx );
  extern uint8_t g_Thread_Background_Idx;
  ClearLongestTaskRun( g_Thread_Background_Idx );
}

/*****************************************************************************
   APPLICATION CALLBACK FUNCTIONS
 *****************************************************************************/
void App_Startup(void)
{
  app_is_in_shutdown = 0;
}

void App_Shutdown(void)
{
  app_is_in_shutdown = 1;
}

void application_int(void)
{
  initRAMVariables(&RAMVariables);
  initCONSTVariables(&CONSTVariables);

  {
    extern void App_EE_Init(void);
    App_EE_Init();
  }

  Lightning_McSeas_VCU_OLD_CONTROLLER_Speed_Mode_initialize();

  /* CAN Bus Initializations */
  CANFrame_Queue_Create(&g_CAN1_TxQueue, CAN1_TxQueue_data, (20));
  CANFrame_Queue_Create(&g_CAN1_RxQueue, CAN1_RxQueue_data, (16));
  pre_start_CAN_2019__0012();          /* <Root>/raptor_can_def */
  CANFrame_Queue_Create(&g_CAN2_TxQueue, CAN2_TxQueue_data, (20));
  CANFrame_Queue_Create(&g_CAN2_RxQueue, CAN2_RxQueue_data, (16));
  pre_start_CAN_2020__0012();          /* <Root>/raptor_can_def1 */

  /* start_CAN(); */
  post_start_CAN_2019__0012();         /* <Root>/raptor_can_def */
  post_start_CAN_2020__0012();         /* <Root>/raptor_can_def1 */
  Xcp_Initialize();

  {
    extern void Raptor_LIN_Init(void);
    Raptor_LIN_Init();
  }

  /* Spawn Threads for timed triggers, always spawn foreground */
  extern uint8_t g_Thread_Foreground_Idx;
  g_Thread_Foreground_Idx = add_task(&Thread_Foreground, 10000, TRUE_TIMED);
  extern uint8_t g_Thread_Background_Idx;
  g_Thread_Background_Idx = add_task(&Thread_Background, 50000, TRUE_TIMED);

  /* Init AnalogInput WAKE_INPUT1 */
  AnalogInputInit(KEYSW);

  /* Init AnalogInput AN7 */
  AnalogInputInit(AN7);

  /* Init AnalogInput AN8 */
  AnalogInputInit(AN8);

  /* Set LSO_EN to Enabled */
  {
    extern void discrete_output_init(E_HW_OUTPUTS out);
    discrete_output_init(LSO_EN);
    set_hw_discrete_output(LSO_EN, 1);
  }
}
