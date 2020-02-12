/*
 *  File Name  : SysCtl_lcfg.c
 *  Description: contains the linking configuration parameters
 *  Created on : Feb 10, 2020
 *  Author     : ahmed_elbadwi
 */




#include "SysCtr_types.h"
#include "SysCtr.h"

/*
 * hint :
 *        1- you must configure u32_SysClkSource to either (SYSCTL_OSC_INT or SYSCTL_OSC_MAIN_16MHZ or
 *           SYSCTL_OSC_MAIN_8MHZ or SYSCTL_OSC_MAIN_25MHZ) as these are the supported configurations currently.
 *        2- you must configure u32_SysClkFrequency to either (SYSCTL_SYSDIV2_8MHZ or SYSCTL_SYSDIV2_4MHZ
 *           or SYSCTL_SYSDIV2_15_3MHZ) as these are the supported configurations currently.
 * */

const SysCtl_cfg_t SysCtl_InitCfg=
{
 .u32_SysClkSource=SYSCTL_OSC_INT,
 .u32_SysClkFrequency=SYSCTL_SYSDIV2_15_3MHZ
};



