/*
 * processor.c
 *
 *  Created on: Dec 2, 2019
 *      Author: Muhammad.Elzeiny
 */
#include "processor.h"

static PROCESSOR_ModeType g_processorMode;

void PROCESSOR_switchMode(PROCESSOR_ModeType Mode)
{
    /* TODO use Svc assembly instruction to switch to handler mode*/
    g_processorMode = Mode;
    __asm("    SVC    #1\n");
}

/*TODO: Put the following function address in Vector table */
void PROCESSOR_SvcHandler(void)
{
    /*TODO use TMPL bit field in CONTROL Register to switch between
     * privilege and non-privilege modes.See page(88) */
    if(g_processorMode == 1)
    {
        __asm("    MOV   r0,#1\n"
              "    MSR   CONTROL,r0\n");
    }
    else if(g_processorMode == 0)
    {
        __asm("    MOV   r0,#0\n"
              "    MSR   CONTROL,r0\n");
    }


}

void PROCESSOR_enableGlobalInt(void)
{
    PROCESSOR_switchMode(PROCESSOR_ModePrivilege);
    __asm("    cpsie   i\n");
    PROCESSOR_switchMode(PROCESSOR_ModeNonPrivilege);
}

void PROCESSOR_disableGlobalInt(void)
{
    PROCESSOR_switchMode(PROCESSOR_ModePrivilege);
    __asm("    cpsid   i\n");
    PROCESSOR_switchMode(PROCESSOR_ModeNonPrivilege);
}
