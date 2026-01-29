/***************************************************************************************************
* FILENAME : main.c
* DESCRIPTION : Main appllication for testing timer driver.
*
* NOTES :
*
* AUTHOR : Mariyam Shahid
***************************************************************************************************/

/*************************************** Header Inclusion *****************************************/
#include "../inc/gpio.h"
#include "../inc/gptm.h"
#include "../inc/nvic.h"
#include "../inc/uart.h"
#include "../inc/state_machine.h"

/********************************************* Globals ********************************************/
volatile state_machine_States Current_state = STATE_IDLE;
gptm_Config timer;
gpio_Config switches;

/************************************** Main Implementation ***************************************/

/**
 * @brief main : Main function for testing timer driver
 * 
 * @return int
 */
int main(void) 
{
    uart_Config uart;

    uart.UART_NUM = UART_1;
    uart.BAUD_RATE = BAUD_RATE_9600;
    uart.WORD_LENGTH = WORDLENGTH_8_BITS;
    uart.STOP_BITS = STOPBITS_1;
    uart.PARITY = PARITY_NONE;
    uart.UART_INTERRUPT = UART_INTERRUPT_ENABLE;
    uart_init(&uart);
    uart_sendString(&uart, "\r\nhello! uart initialized \0");


    while(1);

    return 0;
}