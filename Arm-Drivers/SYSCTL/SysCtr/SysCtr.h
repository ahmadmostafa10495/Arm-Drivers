/*
 * SysCtr.h
 *
 *  Created on: Aug 2, 2019
 *      Author: Muhammad.Elzeiny
 */

#ifndef E15_ARM_REPO_MCAL_SYS_CTR_SYSCTR_H_
#define E15_ARM_REPO_MCAL_SYS_CTR_SYSCTR_H_


#define SYSCTL_SYSDIV2_8MHZ          (0)       // sysdiv value to get 8MHZ
#define SYSCTL_SYSDIV2_4MHZ          (1)       // sysdiv value to get 4MHZ
#define SYSCTL_SYSDIV2_15_3MHZ       (2)       // sysdiv value to get 15.3MHZ


// clock source options
#define SYSCTL_OSC_INT              0  // Osc source is int. osc
//#define SYSCTL_OSC_INT4             1  // Osc source is int. osc /4
#define SYSCTL_OSC_MAIN_16MHZ       2  // External crystal is 16 MHz
#define SYSCTL_OSC_MAIN_8MHZ        3  // External crystal is 8MHz
#define SYSCTL_OSC_MAIN_25MHZ       4  // External crystal is 25.0 MHz


#include "Std_Types.h"

void SysCtr_init(void);
uint32 SysCtr_getSysClockFreq(void);



#endif /* E15_ARM_REPO_MCAL_SYS_CTR_SYSCTR_H_ */
