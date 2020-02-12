/*
 * nvic.c
 *
 *  Created on: Aug 17, 2019
 *      Author: kareem
 */


#include "../../utils/Std_Types.h"
#include "../../utils/Bit_Math.h"
/*TODO include processor.h*/

#include "../../config/nvic_cfg.h"
#include "../mcu_hw.h"
#include "nvic_types.h"
#include "nvic.h"

#define NVIC_PRIORIRY_MASK (0x07)

extern NVIC_CfgType NVIC_CfgArr[];
extern uint8 ui8priorityConfig;


void NVIC_init(void)
{
    uint32 ui32priority;
    uint32 ui32index;
    uint8 ui8shift;
    volatile uint32 * ui32ptrReg;
    uint32 ui8interruptNumber;
    /*TODO : switch to privilege mode - use switch function in processor.h*/


    /*TODO :loop for NVIC_CfgArr configure each Interrupt
     *  as stated in Cfg (Enable/Priority/sub-priority)
     *  */
    for(ui32index=0; ui32index<NVIC_NUM_OF_ENABLED_INT; ui32index++)
    {
        /* enable interrupt */
        ui8interruptNumber = NVIC_CfgArr[ui32index].int_num;
        ui32ptrReg = (uint32 *)(NVIC_BASE + NVIC_ENABLE_BASE + (ui8interruptNumber/32)*4);
        *ui32ptrReg |= 1<<(ui8interruptNumber%32);
        /* priority */
        switch(ui8priorityConfig)
        {
            case NVIC_SETUP_PRIORITY_XXX:
                ui32priority = NVIC_CfgArr[ui32index].ui8groupPriority;
                break;
            case NVIC_SETUP_PRIORITY_XXY:
                ui32priority = (NVIC_CfgArr[ui32index].ui8groupPriority)<<1;
                ui32priority |= (NVIC_CfgArr[ui32index].ui8groupPriority);
                break;
            case NVIC_SETUP_PRIORITY_XYY:
                ui32priority = (NVIC_CfgArr[ui32index].ui8groupPriority)<<2;
                ui32priority |= (NVIC_CfgArr[ui32index].ui8groupPriority);
                break;
            case NVIC_SETUP_PRIORITY_YYY:
                ui32priority = NVIC_CfgArr[ui32index].ui8subGroupPriority;
                break;
            default:
                break;
        }
        /* set in register */
        ui32ptrReg = (uint32 *)(NVIC_BASE + NVIC_PRIORITY_BASE + (ui8interruptNumber/4)*4);
        ui8shift = (((ui8interruptNumber%4)*8)+5);
        ui32priority = (uint32)(ui32priority&NVIC_PRIORIRY_MASK);
        *ui32ptrReg = (uint32)( *ui32ptrReg | (ui32priority<<ui8shift) );
    }



    /*TODO : return to non-privilege mode */

}



