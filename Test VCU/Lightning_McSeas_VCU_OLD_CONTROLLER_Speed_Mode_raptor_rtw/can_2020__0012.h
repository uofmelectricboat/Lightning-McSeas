/*****************************************************************************
   can_2020__0012.h
   Generated By:
   Raptor 2021b_1.0.14409 (6115)
   Matlab (R2021b) 9.11

   Copyright (c) 2018 New Eagle Products, Inc.
   All rights reserved.

   Code Generated at: Mon Apr 17 16:47:54 2023
 *****************************************************************************/

#ifndef __CAN_2020__0012_H
#define __CAN_2020__0012_H

/*   CAN Bus: CAN2 */
/*  Resource: CAN2 */
#include "can.h"

/* FUNCTION PROTOTYPES */
/* CAN initialization */
extern void pre_start_CAN_2020__0012(void);
extern void post_start_CAN_2020__0012(void);

/* Receive CAN object declarations */
extern uint8_T can_get_1556__0012(uint16_T *age, uint32_T* id, uint8_T* extended,
  uint8_T *data, uint8_T length);
extern uint8_T can_get_1558__0012(uint16_T *age, uint32_T* id, uint8_T* extended,
  uint8_T *data, uint8_T length);
extern uint8_T can_get_1557__0012(uint16_T *age, uint32_T* id, uint8_T* extended,
  uint8_T *data, uint8_T length);

/* Transmit CAN object declarations */
#endif
