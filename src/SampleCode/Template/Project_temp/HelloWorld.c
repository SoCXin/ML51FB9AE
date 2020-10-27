/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

//***********************************************************************************************************
//  Website: http://www.nuvoton.com
//  E-Mail : MicroC-8bit@nuvoton.com
//***********************************************************************************************************

//***********************************************************************************************************
//  File Function: ML51 simple GPIO toggle out demo code
//***********************************************************************************************************

#include "ML51.h"


void main (void) 
{
	/*
 For UART0 P3.1 as TXD output setting 
 * include uart.c in Common Setting for UART0 
*/
    MFP_P31_UART0_TXD;                              // UART0 TXD use P1.6
    P31_QUASI_MODE;                                  // set P1.6 as Quasi mode for UART0 trasnfer
    UART_Open(24000000,UART0_Timer1,115200);        // Open UART0 use timer1 as baudrate generate and baud rate = 115200
    ENABLE_UART0_PRINTF;

    printf("\n Hello world!");
    while(1);
}


