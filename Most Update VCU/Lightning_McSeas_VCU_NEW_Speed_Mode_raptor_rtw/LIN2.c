/*****************************************************************************
   LIN2.c
   Generated By:
   Raptor 2021b_1.0.14409 (6115)
   Matlab (R2021b) 9.11

   Copyright (c) 2018 New Eagle Products, Inc.
   All rights reserved.

   Code Generated at: Mon Apr 17 16:36:42 2023
 *****************************************************************************/

#include "lin.h"
#include "LIN2_common.h"

uint8_t Lin_Buf_Node1_Rd_LIN2[7U];
uint8_t Lin_Buf_Node2_Rd_LIN2[5U];
uint8_t Lin_Buf_Node1_Control_LIN2[3U];
uint8_t Lin_Buf_Node2_Control_LIN2[3U];

#define LIN2_NUM_FRAMES                4U
#define LIN2_NUM_SCHEDULES             2U

LIN_Frame_Entry_t LIN2_Frame_List[4] = {
  /* frame 0 */
  {
    0x21,
    LIN_RECEIVE,
    LIN_ENHANCED_CHECKSUM,
    7U,
    &Lin_Buf_Node1_Rd_LIN2[0],
    NULL,
  },

  /* frame 1 */
  {
    0x22,
    LIN_RECEIVE,
    LIN_ENHANCED_CHECKSUM,
    5U,
    &Lin_Buf_Node2_Rd_LIN2[0],
    NULL,
  },

  /* frame 2 */
  {
    0x11,
    LIN_TRANSMIT,
    LIN_ENHANCED_CHECKSUM,
    3U,
    &Lin_Buf_Node1_Control_LIN2[0],
    NULL,
  },

  /* frame 3 */
  {
    0x12,
    LIN_TRANSMIT,
    LIN_ENHANCED_CHECKSUM,
    3U,
    &Lin_Buf_Node2_Control_LIN2[0],
    NULL,
  },
};

LIN_Schedule_Entry_t LIN2_Entry_Schedule_Read_Schedule[4] = {
  {
    4U,                                /* delay to next slot in ticks */
    0,                                 /* frame index */
  },

  {
    4U,                                /* delay to next slot in ticks */
    1,                                 /* frame index */
  },

  {
    2U,                                /* delay to next slot in ticks */
    2,                                 /* frame index */
  },

  {
    2U,                                /* delay to next slot in ticks */
    3,                                 /* frame index */
  },
};

LIN_Schedule_List_t LIN2_Schedule_Read_Schedule = {
  LIN2_Entry_Schedule_Read_Schedule, 4 };

LIN_Schedule_List_t * pLIN2_Schedule_Entry_List[LIN2_NUM_SCHEDULES] = {
  NULL,
  &LIN2_Schedule_Read_Schedule,
};

LIN_Master_Config_t LIN2_Master_Config = {
  10400,                               // baudrate
  LIN2_NUM_SCHEDULES,                  // uint8_t max_schedule_list_idx
  LIN2_NUM_FRAMES,                     // uint8_t max_frame_idx
  FLEXLIN0,
  &LIN2_Frame_List[0],                 // LIN_Frame_Entry_t *frame_entries_ptr
  &pLIN2_Schedule_Entry_List[0],       // LIN_Schedule_List_t *schedule_list_ptr
};

// This is the full channel definition
LIN_Master_Channel_t LIN2_Channel_Def = {
  0,
  0,
  0,                                   // uint8_t current_schedule_entry_idx
  0,                             // uint8_t current_schedule_entry_location_idx;
  0,                                 // uint8_t current_schedule_minor_step_idx;
  &LIN2_Master_Config,         // LIN_Master_Config_t *master_configuration_ptr;
};

// API for LIN2
void LIN2_SetSchedule(uint8_t sched_idx)
{
  LIN_SetSchedule(&LIN2_Channel_Def, sched_idx);
}

uint8_t LIN2_GetSchedule(void)
{
  return(LIN_GetSchedule(&LIN2_Channel_Def));
}

int16_t LIN2_GetStatus(uint8_t node_idx, uint32_t * tx_counts, uint32_t *
  rx_counts)
{
  return(LIN_GetMasterStatus(&LIN2_Channel_Def, node_idx, tx_counts, rx_counts));
}
