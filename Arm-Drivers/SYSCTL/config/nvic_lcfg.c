/*
 * nvic_lcfg.c
 *
 *  Created on: Dec 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "nvic_cfg.h"
#include "nvic_types.h"


const uint8 gu8_CfgIntPriorityLevel=INTERRUPT_PRIORITY_LEVEL;

const NVIC_CfgType NVIC_CfgArr[NVIC_NUM_OF_ENABLED_INT]=
{
   /*Configure each Enabled Interrupt */
 /*INT_NUM  Group_Priority SubGroup_Priority  */
 {NVIC_UART0,    2,              0},
 {NVIC_SSI0,     0,              1},
 {NVIC_GPIOC,    3,              0},
 {NVIC_GPIOA,    3,              1},
 {NVIC_GPIOB,    1,              0}
};
