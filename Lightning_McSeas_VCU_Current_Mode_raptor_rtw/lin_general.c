/*****************************************************************************
   lin_general.c
   Generated By:
   Raptor 2021b_1.0.14409 (6115)
   Matlab (R2021b) 9.11

   Copyright (c) 2018 New Eagle Products, Inc.
   All rights reserved.

   Code Generated at: Fri Jan 27 12:39:18 2023
 *****************************************************************************/

#include "lin.h"

extern LIN_Master_Channel_t LIN2_Channel_Def;
LIN_Master_Channel_t * pMaster_LIN_Defs[3] = {
  &LIN2_Channel_Def,
  NULL,
  NULL,
};

LIN_Slave_Channel_t *pSlave_LIN_Def = NULL;
void Raptor_LIN_Init(void)
{
  LIN_Master_Init(&LIN2_Channel_Def);
  LIN_Init();                     // Set up tasking and enable LIN for operation
}
