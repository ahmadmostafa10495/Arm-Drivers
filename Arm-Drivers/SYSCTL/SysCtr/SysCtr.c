/*
 * SysCtr.c
 *
 *  Created on: Aug 2, 2019
 *  Author: Ahmed_Elbadwi
 */

/*================================================================= *
 *                       Includes                                   *
 *================================================================= */
#include "mcu_hw.h"
#include "STD_Types.h"
#include "Bit_Math.h"
#include "SysCtr_types.h"
#include "SysCtr.h"
/*================================================================== *
 *               Private #defines                                    *
 *================================================================== */
// External crystal options
#define SYSCTL_XTAL_16MHZ        0x15  // External crystal is 16 MHz
#define SYSCTL_XTAL_8MHZ         0x0E  // External crystal is 8MHz
#define SYSCTL_XTAL_25MHZ        0x1A  // External crystal is 25.0 MHz
#define CLK_FREQUENCY_8MHZ      (8000000UL )
#define CLK_FREQUENCY_4MHZ      (4000000UL )
#define CLK_FREQUENCY_15_3MHZ   (15300000UL)
#define SYSDIV2_8MHZ            (24U)
#define SYSDIV2_4MHZ            (49U)
#define SYSDIV2_15_3MHZ         (12U)
#define MAIN_OSC                  0
#define OSC_INT                   1
/*==================================================================== *
 *                         Externs                                     *
 *==================================================================== */
extern const SysCtl_cfg_t SysCtl_InitCfg;
/*==================================================================== *
 *                   Static Global Variables                           *
 *==================================================================== */
static uint8 gau8_xtal_Lookup[] = {0, 0, SYSCTL_XTAL_16MHZ, SYSCTL_XTAL_8MHZ, SYSCTL_XTAL_25MHZ};
static uint8 gau8_OscSource_Lookup[] = {OSC_INT, OSC_INT, MAIN_OSC, MAIN_OSC, MAIN_OSC};
static uint8 gau8_ClkDivisor_Lookup[] = {SYSDIV2_8MHZ, SYSDIV2_4MHZ, SYSDIV2_15_3MHZ};
static uint32 gau32_ClkFreq_Lookup[] = {CLK_FREQUENCY_8MHZ, CLK_FREQUENCY_4MHZ, CLK_FREQUENCY_15_3MHZ};
static uint32 gu32_CurrentClkFrequency=0;

/*==================================================================== *
 *                   Function Definitions                              *
 *==================================================================== */
void SysCtr_init(void)
{
    /* Configure RCC Register */
    /* Enable System Clock Divider */
    SysCtl_RCC_R.Bits_t.USESYSDIV=1;
    /* Crystal Value */
    SysCtl_RCC_R.Bits_t.XTAL= gau8_xtal_Lookup[SysCtl_InitCfg.u32_SysClkSource];
    /* Configure RCC2 Register */
    /* Override the RCC register fields */
    SysCtl_RCC2_R.Bits_t.USERCC2=1;
    /* Low Level Design: Divide PLL as 200 MHz */
    SysCtl_RCC2_R.Bits_t.DIV400=0;
    /* System Clock Divisor 2 */
    SysCtl_RCC2_R.Bits_t.SYSDIV2=gau8_ClkDivisor_Lookup[SysCtl_InitCfg.u32_SysClkFrequency];
    /* Configure Oscillator Source */
    SysCtl_RCC2_R.Bits_t.OSCSRC2=gau8_OscSource_Lookup[SysCtl_InitCfg.u32_SysClkSource];
    /* The PLL operates normally */
    SysCtl_RCC2_R.Bits_t.PWRDN2 = 0;
    /* Low level design: The system clock is the PLL output clock divided by the divisor specified by SYSDIV2 */
    SysCtl_RCC2_R.Bits_t.BYPASS2=0;
    /* Save Desired Frequency */
    gu32_CurrentClkFrequency = gau32_ClkFreq_Lookup[SysCtl_InitCfg.u32_SysClkFrequency];
}

uint32 SysCtr_getSysClockFreq(void)
{
    /* return the current system clock frequency */
    return gu32_CurrentClkFrequency;
}


/*TODO make general API to enable clock gating of any peripheral */

