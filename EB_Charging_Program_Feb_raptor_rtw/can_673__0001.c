/*****************************************************************************
   can_673__0001.c
   Generated By:
   Raptor 2021b_1.0.14409 (6115)
   Matlab (R2021b) 9.11

   Copyright (c) 2018 New Eagle Products, Inc.
   All rights reserved.

   Code Generated at: Mon Apr 10 15:44:35 2023
 *****************************************************************************/

/* CAN interface: CAN1 */
/*   HW Resource: CAN1 */
#include "EB_Charging_Program_Feb.h"
#include "can_673__0001.h"
#include "sdk_can.h"
#include "can.h"
#define MAX_AGE                        65535

int started_673__0001 = 0;
void uds_request_trigger(void)
{
  uint16_T age;
  uint32_T id;
  uint8_T extended;
  uint8_T data[8];
  uint16_T length = 8;
  extern void App_Shutdown(void);
  length = can_get_uds_receive(&age, &id, &extended, data, length);
  if (length >= 3 && data[1] == 0x10 && data[2] == 0x02) {
    uint8_T data[] = { 2U, 80U, 2U, 0U, 0U, 0U, 0U, 255U };

    can_send_uds_send(UDSClientAddr_RAM_Data() & 0x1FFFFFFF,
                      (UDSClientAddr_RAM_Data() > 0x1FFFFFFF), 8, data);
    for (age = 0; age < 1000; age++) {
    }

    App_Shutdown();

    {
      extern void Reset_BootRequest( uint32_T bootaddr, uint32_T tooladdress,
        uint8_t canBus );
      Reset_BootRequest( UDSServerAddr_RAM_Data(), UDSClientAddr_RAM_Data(),
                        CAN1) ;
    }
  }
}

const uint32_T CAN_CAN1_baud_rate = 500000;
uint32_T CAN_CAN1_get_baud_rate(void)
{
  return(CAN_CAN1_baud_rate);
}

/* Message Receive data storage */
/* Block: <S4>/raptor_can_rxmsg */
void rxFn_135__0002(unsigned int id, uint8_T len, uint8_T* data);
uint8_T rxBuf_135__0002[1U][8];
uint8_T rxLen_135__0002[1U];
uint16_T rxAge_135__0002;
uint32_T rxID_135__0002[1U];
uint8_T rxQHead_135__0002 = 0;
uint8_T rxQTail_135__0002 = 0;

/* Block: <S4>/raptor_can_rxmsg1 */
void rxFn_136__0002(unsigned int id, uint8_T len, uint8_T* data);
uint8_T rxBuf_136__0002[1U][8];
uint8_T rxLen_136__0002[1U];
uint16_T rxAge_136__0002;
uint32_T rxID_136__0002[1U];
uint8_T rxQHead_136__0002 = 0;
uint8_T rxQTail_136__0002 = 0;

/* Block: <S5>/raptor_can_rxmsg */
void rxFn_216__0002(unsigned int id, uint8_T len, uint8_T* data);
uint8_T rxBuf_216__0002[1U][8];
uint8_T rxLen_216__0002[1U];
uint16_T rxAge_216__0002;
uint32_T rxID_216__0002[1U];
uint8_T rxQHead_216__0002 = 0;
uint8_T rxQTail_216__0002 = 0;

/* Block: <S3>/raptor_xcp_update */
void rxFn_RxTrig_XCP_BC_CAN1(unsigned int id, uint8_T len, uint8_T* data);
uint8_T rxBuf_RxTrig_XCP_BC_CAN1[1][8];
uint8_T rxLen_RxTrig_XCP_BC_CAN1[1];
uint16_T rxAge_RxTrig_XCP_BC_CAN1;
uint32_T rxID_RxTrig_XCP_BC_CAN1[1];
uint8_T rxQHead_RxTrig_XCP_BC_CAN1 = 0;
uint8_T rxQTail_RxTrig_XCP_BC_CAN1 = 0;

/* Block: <S3>/raptor_xcp_update */
void rxFn_RxTrig_XCP_CMD_CAN1(unsigned int id, uint8_T len, uint8_T* data);
uint8_T rxBuf_RxTrig_XCP_CMD_CAN1[1][8];
uint8_T rxLen_RxTrig_XCP_CMD_CAN1[1];
uint16_T rxAge_RxTrig_XCP_CMD_CAN1;
uint32_T rxID_RxTrig_XCP_CMD_CAN1[1];
uint8_T rxQHead_RxTrig_XCP_CMD_CAN1 = 0;
uint8_T rxQTail_RxTrig_XCP_CMD_CAN1 = 0;

/* Block: UDS_receive */
void rxFn_uds_receive(unsigned int id, uint8_T len, uint8_T* data);
uint8_T rxBuf_uds_receive[1][8];
uint8_T rxLen_uds_receive[1];
uint16_T rxAge_uds_receive;
uint32_T rxID_uds_receive[1];
uint8_T rxQHead_uds_receive = 0;
uint8_T rxQTail_uds_receive = 0;

/* Transmit CAN Object Declarations */
/* <S4>/raptor_can_txmsg */
uint8_T txData_137__0002[1U][8U];
uint32_T txID_137__0002[1U];
uint8_T txExt_137__0002[1U];
uint8_T txLen_137__0002[1U];
uint8_T txQHead_137__0002 = 0;
uint8_T txQTail_137__0002 = 0;

/* <S4>/raptor_can_txmsg1 */
uint8_T txData_138__0002[1U][8U];
uint32_T txID_138__0002[1U];
uint8_T txExt_138__0002[1U];
uint8_T txLen_138__0002[1U];
uint8_T txQHead_138__0002 = 0;
uint8_T txQTail_138__0002 = 0;

/* <S5>/raptor_can_txmsg */
uint8_T txData_217__0002[1U][4U];
uint32_T txID_217__0002[1U];
uint8_T txExt_217__0002[1U];
uint8_T txLen_217__0002[1U];
uint8_T txQHead_217__0002 = 0;
uint8_T txQTail_217__0002 = 0;

/* <S3>/raptor_xcp_update */
uint8_T txData_Tx_XCP_CAN1[1][8];
uint32_T txID_Tx_XCP_CAN1[1];
uint8_T txExt_Tx_XCP_CAN1[1];
uint8_T txLen_Tx_XCP_CAN1[1];
uint8_T txQHead_Tx_XCP_CAN1 = 0;
uint8_T txQTail_Tx_XCP_CAN1 = 0;

/* UDS_send */
uint8_T txData_uds_send[1][8];
uint32_T txID_uds_send[1];
uint8_T txExt_uds_send[1];
uint8_T txLen_uds_send[1];
uint8_T txQHead_uds_send = 0;
uint8_T txQTail_uds_send = 0;

/* Functions */
void pre_start_CAN_673__0001(void)
{
}                                      // end pre_start_CAN_673__0001

void rxFn_135__0002(unsigned int id, uint8_T length, uint8_T* data)
{
  uint8_T i;
  uint8_T* b = data;
  if ((length == 8U) ) {
    for (i = 0; i < length; i++) {
      rxBuf_135__0002[rxQHead_135__0002][i] = b[i];
    }

    rxLen_135__0002[rxQHead_135__0002] = length;
    rxID_135__0002[rxQHead_135__0002] = id;
    if ((rxQHead_135__0002 == rxQTail_135__0002) && (rxAge_135__0002 == 0))
      rxQTail_135__0002 = (rxQTail_135__0002 + 1) % 1U;
    if ((rxQHead_135__0002 == (rxQTail_135__0002 + 1)% 1U) && (rxAge_135__0002
         != 0))
      rxQTail_135__0002 = (rxQTail_135__0002 + 1) % 1U;
    rxQHead_135__0002 = (rxQHead_135__0002 + 1 ) % 1U;
    rxAge_135__0002 = 0;
  }
}

uint8_T can_get_135__0002(uint16_T *age, uint32_T* id, uint8_T* extended,
  uint8_T *data, uint8_T length)
{
  uint8_T i;
  if (age != NULL)
    *age = rxAge_135__0002;
  if (id != NULL)
    *id = rxID_135__0002[rxQTail_135__0002];
  if (extended != NULL)
    *extended = 0U;
  if (length > 8)
    length = 8;
  if (length > rxLen_135__0002[rxQTail_135__0002])
    length = rxLen_135__0002[rxQTail_135__0002];
  if (data != NULL)
    for (i = 0; i < length; i++)
      data[i] = rxBuf_135__0002[rxQTail_135__0002][i];
  if ((rxQHead_135__0002 != (rxQTail_135__0002 + 1)% 1U) && (rxAge_135__0002 ==
       0))
    rxQTail_135__0002 = (rxQTail_135__0002 + 1) % 1U;
  else if (rxAge_135__0002 < MAX_AGE)
    rxAge_135__0002++;
  return length;
}

void rxFn_136__0002(unsigned int id, uint8_T length, uint8_T* data)
{
  uint8_T i;
  uint8_T* b = data;
  if ((length == 8U) ) {
    for (i = 0; i < length; i++) {
      rxBuf_136__0002[rxQHead_136__0002][i] = b[i];
    }

    rxLen_136__0002[rxQHead_136__0002] = length;
    rxID_136__0002[rxQHead_136__0002] = id;
    if ((rxQHead_136__0002 == rxQTail_136__0002) && (rxAge_136__0002 == 0))
      rxQTail_136__0002 = (rxQTail_136__0002 + 1) % 1U;
    if ((rxQHead_136__0002 == (rxQTail_136__0002 + 1)% 1U) && (rxAge_136__0002
         != 0))
      rxQTail_136__0002 = (rxQTail_136__0002 + 1) % 1U;
    rxQHead_136__0002 = (rxQHead_136__0002 + 1 ) % 1U;
    rxAge_136__0002 = 0;
  }
}

uint8_T can_get_136__0002(uint16_T *age, uint32_T* id, uint8_T* extended,
  uint8_T *data, uint8_T length)
{
  uint8_T i;
  if (age != NULL)
    *age = rxAge_136__0002;
  if (id != NULL)
    *id = rxID_136__0002[rxQTail_136__0002];
  if (extended != NULL)
    *extended = 0U;
  if (length > 8)
    length = 8;
  if (length > rxLen_136__0002[rxQTail_136__0002])
    length = rxLen_136__0002[rxQTail_136__0002];
  if (data != NULL)
    for (i = 0; i < length; i++)
      data[i] = rxBuf_136__0002[rxQTail_136__0002][i];
  if ((rxQHead_136__0002 != (rxQTail_136__0002 + 1)% 1U) && (rxAge_136__0002 ==
       0))
    rxQTail_136__0002 = (rxQTail_136__0002 + 1) % 1U;
  else if (rxAge_136__0002 < MAX_AGE)
    rxAge_136__0002++;
  return length;
}

void rxFn_216__0002(unsigned int id, uint8_T length, uint8_T* data)
{
  uint8_T i;
  uint8_T* b = data;
  if ((length == 8U) ) {
    for (i = 0; i < length; i++) {
      rxBuf_216__0002[rxQHead_216__0002][i] = b[i];
    }

    rxLen_216__0002[rxQHead_216__0002] = length;
    rxID_216__0002[rxQHead_216__0002] = id;
    if ((rxQHead_216__0002 == rxQTail_216__0002) && (rxAge_216__0002 == 0))
      rxQTail_216__0002 = (rxQTail_216__0002 + 1) % 1U;
    if ((rxQHead_216__0002 == (rxQTail_216__0002 + 1)% 1U) && (rxAge_216__0002
         != 0))
      rxQTail_216__0002 = (rxQTail_216__0002 + 1) % 1U;
    rxQHead_216__0002 = (rxQHead_216__0002 + 1 ) % 1U;
    rxAge_216__0002 = 0;
  }
}

uint8_T can_get_216__0002(uint16_T *age, uint32_T* id, uint8_T* extended,
  uint8_T *data, uint8_T length)
{
  uint8_T i;
  if (age != NULL)
    *age = rxAge_216__0002;
  if (id != NULL)
    *id = rxID_216__0002[rxQTail_216__0002];
  if (extended != NULL)
    *extended = 0U;
  if (length > 8)
    length = 8;
  if (length > rxLen_216__0002[rxQTail_216__0002])
    length = rxLen_216__0002[rxQTail_216__0002];
  if (data != NULL)
    for (i = 0; i < length; i++)
      data[i] = rxBuf_216__0002[rxQTail_216__0002][i];
  if ((rxQHead_216__0002 != (rxQTail_216__0002 + 1)% 1U) && (rxAge_216__0002 ==
       0))
    rxQTail_216__0002 = (rxQTail_216__0002 + 1) % 1U;
  else if (rxAge_216__0002 < MAX_AGE)
    rxAge_216__0002++;
  return length;
}

void rxFn_RxTrig_XCP_BC_CAN1(unsigned int id, uint8_T length, uint8_T* data)
{
  uint8_T i;
  uint8_T* b = data;
  if (1 ) {
    for (i = 0; i < length; i++) {
      rxBuf_RxTrig_XCP_BC_CAN1[rxQHead_RxTrig_XCP_BC_CAN1][i] = b[i];
    }

    rxLen_RxTrig_XCP_BC_CAN1[rxQHead_RxTrig_XCP_BC_CAN1] = length;
    rxID_RxTrig_XCP_BC_CAN1[rxQHead_RxTrig_XCP_BC_CAN1] = id;
    if ((rxQHead_RxTrig_XCP_BC_CAN1 == rxQTail_RxTrig_XCP_BC_CAN1) &&
        (rxAge_RxTrig_XCP_BC_CAN1 == 0))
      rxQTail_RxTrig_XCP_BC_CAN1 = (rxQTail_RxTrig_XCP_BC_CAN1 + 1) % 1;
    if ((rxQHead_RxTrig_XCP_BC_CAN1 == (rxQTail_RxTrig_XCP_BC_CAN1 + 1)% 1) &&
        (rxAge_RxTrig_XCP_BC_CAN1 != 0))
      rxQTail_RxTrig_XCP_BC_CAN1 = (rxQTail_RxTrig_XCP_BC_CAN1 + 1) % 1;
    rxQHead_RxTrig_XCP_BC_CAN1 = (rxQHead_RxTrig_XCP_BC_CAN1 + 1 ) % 1;
    rxAge_RxTrig_XCP_BC_CAN1 = 0;

    {
      extern void RxTrig_XCP_BC_CAN1();
      RxTrig_XCP_BC_CAN1();
    }
  }
}

uint32_T RxTrig_XCP_BC_CAN1_msgID = 0x100;
uint8_T RxTrig_XCP_BC_CAN1_msgExtended = 0;
void can_init_rxIdRxTrig_XCP_BC_CAN1(uint32_T id, uint8_T extended)
{
  RxTrig_XCP_BC_CAN1_msgID = id;
  RxTrig_XCP_BC_CAN1_msgExtended = extended;
}

uint8_T can_get_RxTrig_XCP_BC_CAN1(uint16_T *age, uint32_T* id, uint8_T
  * extended, uint8_T *data, uint8_T length)
{
  uint8_T i;
  if (age != NULL)
    *age = rxAge_RxTrig_XCP_BC_CAN1;
  if (id != NULL)
    *id = rxID_RxTrig_XCP_BC_CAN1[rxQTail_RxTrig_XCP_BC_CAN1];
  if (extended != NULL)
    *extended = 0;
  if (length > 8)
    length = 8;
  if (length > rxLen_RxTrig_XCP_BC_CAN1[rxQTail_RxTrig_XCP_BC_CAN1])
    length = rxLen_RxTrig_XCP_BC_CAN1[rxQTail_RxTrig_XCP_BC_CAN1];
  if (data != NULL)
    for (i = 0; i < length; i++)
      data[i] = rxBuf_RxTrig_XCP_BC_CAN1[rxQTail_RxTrig_XCP_BC_CAN1][i];
  if ((rxQHead_RxTrig_XCP_BC_CAN1 != (rxQTail_RxTrig_XCP_BC_CAN1 + 1)% 1) &&
      (rxAge_RxTrig_XCP_BC_CAN1 == 0))
    rxQTail_RxTrig_XCP_BC_CAN1 = (rxQTail_RxTrig_XCP_BC_CAN1 + 1) % 1;
  else if (rxAge_RxTrig_XCP_BC_CAN1 < MAX_AGE)
    rxAge_RxTrig_XCP_BC_CAN1++;
  return length;
}

void rxFn_RxTrig_XCP_CMD_CAN1(unsigned int id, uint8_T length, uint8_T* data)
{
  uint8_T i;
  uint8_T* b = data;
  if (1 ) {
    for (i = 0; i < length; i++) {
      rxBuf_RxTrig_XCP_CMD_CAN1[rxQHead_RxTrig_XCP_CMD_CAN1][i] = b[i];
    }

    rxLen_RxTrig_XCP_CMD_CAN1[rxQHead_RxTrig_XCP_CMD_CAN1] = length;
    rxID_RxTrig_XCP_CMD_CAN1[rxQHead_RxTrig_XCP_CMD_CAN1] = id;
    if ((rxQHead_RxTrig_XCP_CMD_CAN1 == rxQTail_RxTrig_XCP_CMD_CAN1) &&
        (rxAge_RxTrig_XCP_CMD_CAN1 == 0))
      rxQTail_RxTrig_XCP_CMD_CAN1 = (rxQTail_RxTrig_XCP_CMD_CAN1 + 1) % 1;
    if ((rxQHead_RxTrig_XCP_CMD_CAN1 == (rxQTail_RxTrig_XCP_CMD_CAN1 + 1)% 1) &&
        (rxAge_RxTrig_XCP_CMD_CAN1 != 0))
      rxQTail_RxTrig_XCP_CMD_CAN1 = (rxQTail_RxTrig_XCP_CMD_CAN1 + 1) % 1;
    rxQHead_RxTrig_XCP_CMD_CAN1 = (rxQHead_RxTrig_XCP_CMD_CAN1 + 1 ) % 1;
    rxAge_RxTrig_XCP_CMD_CAN1 = 0;

    {
      extern void RxTrig_XCP_CMD_CAN1();
      RxTrig_XCP_CMD_CAN1();
    }
  }
}

uint32_T RxTrig_XCP_CMD_CAN1_msgID = 0x200;
uint8_T RxTrig_XCP_CMD_CAN1_msgExtended = 0;
void can_init_rxIdRxTrig_XCP_CMD_CAN1(uint32_T id, uint8_T extended)
{
  RxTrig_XCP_CMD_CAN1_msgID = id;
  RxTrig_XCP_CMD_CAN1_msgExtended = extended;
}

uint8_T can_get_RxTrig_XCP_CMD_CAN1(uint16_T *age, uint32_T* id, uint8_T
  * extended, uint8_T *data, uint8_T length)
{
  uint8_T i;
  if (age != NULL)
    *age = rxAge_RxTrig_XCP_CMD_CAN1;
  if (id != NULL)
    *id = rxID_RxTrig_XCP_CMD_CAN1[rxQTail_RxTrig_XCP_CMD_CAN1];
  if (extended != NULL)
    *extended = 0;
  if (length > 8)
    length = 8;
  if (length > rxLen_RxTrig_XCP_CMD_CAN1[rxQTail_RxTrig_XCP_CMD_CAN1])
    length = rxLen_RxTrig_XCP_CMD_CAN1[rxQTail_RxTrig_XCP_CMD_CAN1];
  if (data != NULL)
    for (i = 0; i < length; i++)
      data[i] = rxBuf_RxTrig_XCP_CMD_CAN1[rxQTail_RxTrig_XCP_CMD_CAN1][i];
  if ((rxQHead_RxTrig_XCP_CMD_CAN1 != (rxQTail_RxTrig_XCP_CMD_CAN1 + 1)% 1) &&
      (rxAge_RxTrig_XCP_CMD_CAN1 == 0))
    rxQTail_RxTrig_XCP_CMD_CAN1 = (rxQTail_RxTrig_XCP_CMD_CAN1 + 1) % 1;
  else if (rxAge_RxTrig_XCP_CMD_CAN1 < MAX_AGE)
    rxAge_RxTrig_XCP_CMD_CAN1++;
  return length;
}

void rxFn_uds_receive(unsigned int id, uint8_T length, uint8_T* data)
{
  uint8_T i;
  uint8_T* b = data;
  if (1 ) {
    for (i = 0; i < length; i++) {
      rxBuf_uds_receive[rxQHead_uds_receive][i] = b[i];
    }

    rxLen_uds_receive[rxQHead_uds_receive] = length;
    rxID_uds_receive[rxQHead_uds_receive] = id;
    if ((rxQHead_uds_receive == rxQTail_uds_receive) && (rxAge_uds_receive == 0))
      rxQTail_uds_receive = (rxQTail_uds_receive + 1) % 1;
    if ((rxQHead_uds_receive == (rxQTail_uds_receive + 1)% 1) &&
        (rxAge_uds_receive != 0))
      rxQTail_uds_receive = (rxQTail_uds_receive + 1) % 1;
    rxQHead_uds_receive = (rxQHead_uds_receive + 1 ) % 1;
    rxAge_uds_receive = 0;

    {
      extern void uds_request_trigger();
      uds_request_trigger();
    }
  }
}

uint8_T can_get_uds_receive(uint16_T *age, uint32_T* id, uint8_T* extended,
  uint8_T *data, uint8_T length)
{
  uint8_T i;
  if (age != NULL)
    *age = rxAge_uds_receive;
  if (id != NULL)
    *id = rxID_uds_receive[rxQTail_uds_receive];
  if (extended != NULL)
    *extended = 0;
  if (length > 8)
    length = 8;
  if (length > rxLen_uds_receive[rxQTail_uds_receive])
    length = rxLen_uds_receive[rxQTail_uds_receive];
  if (data != NULL)
    for (i = 0; i < length; i++)
      data[i] = rxBuf_uds_receive[rxQTail_uds_receive][i];
  if ((rxQHead_uds_receive != (rxQTail_uds_receive + 1)% 1) &&
      (rxAge_uds_receive == 0))
    rxQTail_uds_receive = (rxQTail_uds_receive + 1) % 1;
  else if (rxAge_uds_receive < MAX_AGE)
    rxAge_uds_receive++;
  return length;
}

void can_send_137__0002(uint32_T id, uint8_T extended, uint8_T length, const
  uint8_T *data)
{
  if (!started_673__0001) {
    pre_start_CAN_673__0001();
  }

  send_can_message(CAN1, extended, id, data, length);
}

void can_update_137__0002(uint32_T id, uint8_T extended, uint8_T length, const
  uint8_T *data)
{
}

uint32_T can_set_period_137__0002(uint32_T period)
{
  if (period > 65535)
    period = 65535;
  return period;
}

void can_send_138__0002(uint32_T id, uint8_T extended, uint8_T length, const
  uint8_T *data)
{
  if (!started_673__0001) {
    pre_start_CAN_673__0001();
  }

  send_can_message(CAN1, extended, id, data, length);
}

void can_update_138__0002(uint32_T id, uint8_T extended, uint8_T length, const
  uint8_T *data)
{
}

uint32_T can_set_period_138__0002(uint32_T period)
{
  if (period > 65535)
    period = 65535;
  return period;
}

void can_send_217__0002(uint32_T id, uint8_T extended, uint8_T length, const
  uint8_T *data)
{
  if (!started_673__0001) {
    pre_start_CAN_673__0001();
  }

  send_can_message(CAN1, extended, id, data, length);
}

void can_update_217__0002(uint32_T id, uint8_T extended, uint8_T length, const
  uint8_T *data)
{
}

uint32_T can_set_period_217__0002(uint32_T period)
{
  if (period > 65535)
    period = 65535;
  return period;
}

void can_send_Tx_XCP_CAN1(uint32_T id, uint8_T extended, uint8_T length, const
  uint8_T *data)
{
  if (!started_673__0001) {
    pre_start_CAN_673__0001();
  }

  {
    extern void CAN_XCPTransmit(E_CAN_CONTROLLER busId, boolean_t extended,
      uint32_t id, uint8_t length, const uint8_t * pData);
    CAN_XCPTransmit(CAN1, extended, id, length, data);
  }
}

void can_update_Tx_XCP_CAN1(uint32_T id, uint8_T extended, uint8_T length, const
  uint8_T *data)
{
}

uint32_T can_set_period_Tx_XCP_CAN1(uint32_T period)
{
  if (period > 65535)
    period = 65535;
  return period;
}

void can_send_uds_send(uint32_T id, uint8_T extended, uint8_T length, const
  uint8_T *data)
{
  if (!started_673__0001) {
    pre_start_CAN_673__0001();
  }

  send_can_message(CAN1, extended, id, data, length);
}

void can_update_uds_send(uint32_T id, uint8_T extended, uint8_T length, const
  uint8_T *data)
{
}

uint32_T can_set_period_uds_send(uint32_T period)
{
  if (period > 65535)
    period = 65535;
  return period;
}

void CAN_ReceiveDispatch_673__0001(boolean extended, uint32_t id, uint8_t * data,
  uint8_t data_len)
{
  extern uint8_T app_is_in_shutdown;
  if (!app_is_in_shutdown) {
    if (extended == 0U) {
      if ((id & 0x7FF) == 0x430) {
        rxFn_135__0002(id, data_len, data);
      }
    }
  }

  if (!app_is_in_shutdown) {
    if (extended == 0U) {
      if ((id & 0x7FF) == 0x431) {
        rxFn_136__0002(id, data_len, data);
      }
    }
  }

  if (!app_is_in_shutdown) {
    if (extended == 0U) {
      if ((id & 0x7FF) == 0x430) {
        rxFn_216__0002(id, data_len, data);
      }
    }
  }

  if (extended == 0) {
    if ((id & 0x1FFFFFFF) == (RxTrig_XCP_BC_CAN1_msgID & 0x1FFFFFFF)) {
      rxFn_RxTrig_XCP_BC_CAN1(id, data_len, data);
    }
  }

  if (extended == 0) {
    if ((id & 0x1FFFFFFF) == (RxTrig_XCP_CMD_CAN1_msgID & 0x1FFFFFFF)) {
      rxFn_RxTrig_XCP_CMD_CAN1(id, data_len, data);
    }
  }

  if (extended == 0) {
    if ((id & 0x1FFFFFFF) == 0x600) {
      rxFn_uds_receive(id, data_len, data);
    }
  }
}

void post_start_CAN_673__0001(void)
{
  if (started_673__0001) {
    return;
  }

  started_673__0001 = 1;
  start_CAN(CAN1, CAN_CAN1_baud_rate );
  can_register_rx_callback( CAN1, CAN_ReceiveDispatch_673__0001 );
}                                      // end post_start_CAN_673__0001
