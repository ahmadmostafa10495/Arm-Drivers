/*
 * SysCtr_Types.h
 *
 *  Created on: Dec 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#include "STD_types.h"

#ifndef TM4C123_FIRMWARE_MCAL_SYSCTR_SYSCTR_TYPES_H_
#define TM4C123_FIRMWARE_MCAL_SYSCTR_SYSCTR_TYPES_H_

/*
 * typedef of container of system control linking configurations
 * */
typedef struct SysCtl_cfg_t
{
    /* Desired System clock Source */
    uint32 u32_SysClkSource;
    /* Desired System CLock Frequency */
    uint32 u32_SysClkFrequency;
}SysCtl_cfg_t;


#endif /* TM4C123_FIRMWARE_MCAL_SYSCTR_SYSCTR_TYPES_H_ */
