/*****************************************************************************
   can_936__0024.h
   Generated By:
   Raptor 2021b_1.0.14409 (6115)
   Matlab (R2021b) 9.11

   Copyright (c) 2018 New Eagle Products, Inc.
   All rights reserved.

   Code Generated at: Sun Nov  6 17:27:16 2022
 *****************************************************************************/

#ifndef __CAN_936__0024_H
#define __CAN_936__0024_H

/*   CAN Bus: CAN2 */
/*  Resource: CAN2 */
#include "can.h"

/* FUNCTION PROTOTYPES */
/* CAN initialization */
extern void pre_start_CAN_936__0024(void);
extern void post_start_CAN_936__0024(void);

/* Receive CAN object declarations */
extern uint8_T can_get_472__0006(uint16_T *age, uint32_T* id, uint8_T* extended,
  uint8_T *data, uint8_T length);
extern uint8_T can_get_474__0006(uint16_T *age, uint32_T* id, uint8_T* extended,
  uint8_T *data, uint8_T length);
extern uint8_T can_get_473__0006(uint16_T *age, uint32_T* id, uint8_T* extended,
  uint8_T *data, uint8_T length);

/* Transmit CAN object declarations */
#endif
