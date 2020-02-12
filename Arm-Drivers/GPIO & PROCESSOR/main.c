

/**
 * main.c
 * Author: Ahmed
 */
#include "utils/processor/processor.h"
#include <mcal/PortDriver/port.h>
#include <mcal/SysCtr/SysCtr.h>
#include "../mcal/dio/dio.h"
#define RCGC (*((volatile uint32 *)0x400FE608))
void lab_00_dio(void)
{
    /*TODO: write simple code to test System control clock */

    //SysCtr_init();
    RCGC = 0x3F;
    PORT_init();

    Dio_WriteChannel(Dio_Channel_F3, STD_high);
    Dio_WriteChannel(Dio_Channel_F1, STD_high);
    Dio_WriteChannel(Dio_Channel_F2, STD_high);

    while(1)
    {

    }
}
int main(void)
{
    lab_00_dio();
//    PROCESSOR_ModeType processorMode = PROCESSOR_ModePrivilege;
    while(1)
    {
//        PROCESSOR_switchMode(processorMode);
//        processorMode = PROCESSOR_ModeNonPrivilege;
//        PROCESSOR_switchMode(processorMode);
//        processorMode = PROCESSOR_ModePrivilege;
    }
	return 0;
}
