/******************************************************************************
* FILENAME : isr.c
* DESCRIPTION : This file contains the definitions of all functions prototypes
*               which are defined in isr.h | Interrupt Service Routines (ISRs)
*               are being implemented in this file.
* AUTHOR : Mariyam Shahid
******************************************************************************/

/***************************** Header Inclusion ******************************/
#include "isr.h"
#include "..\inc\gptm.h"
#include "..\inc\uart.h"


/********************************* Externs ***********************************/
extern gptm_Config timer;
extern gpio_Config switches;

/********************************* Globals ***********************************/

/**
 * @brief Isr_Timer0A : Interrupt service routine for timer 0 channel A.
 * 
 * @return
 */
void Isr_Timer0A(void)
{
    gptm_interruptCallback(&timer);
}

/**
 * @brief Isr_GpioF : Interrupt service routine for GPIO port F.
 * 
 * @return
 */
void Isr_GpioF(void)
{
    gpio_interruptCallback(&switches);
}

/**
 * @brief UART0_IRQHandler : Interrupt service routine for UART 0.
 * 
 * @return
 */
void Isr_Uart0(void)
{
    uart0_interruptCallback();
}

/**
 * @brief UART1_IRQHandler : Interrupt service routine for UART 1.
 * 
 * @return
 */
void Isr_Uart1(void)
{
    uart1_interruptCallback();
}