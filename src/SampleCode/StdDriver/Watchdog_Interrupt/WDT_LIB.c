/*---------------------------------------------------------------------------------------------------------*/
/*                                                                                                         */
/* Copyright(c) 2020 Nuvoton Technology Corp. All rights reserved.                                         */
/*                                                                                                         */
/*---------------------------------------------------------------------------------------------------------*/

/***********************************************************************************************************/
/* Website: http://www.nuvoton.com                                                                         */
/*  E-Mail : MicroC-8bit@nuvoton.com                                                                       */
/*  Date   : Apr/29/2020                                                                                   */
/***********************************************************************************************************/

/************************************************************************************************************/
/*  File Function: ML51 Watchdog timer interrupt function demo                                              */
/************************************************************************************************************/
#include "ML51.h"
 
/************************************************************************************************************
*    WDT interrupt sub-routine
************************************************************************************************************/
void WDT_ISR (void)   interrupt 10
{
  _push_(SFRS);
    clr_WDCON_WDTF;
    P32 = ~P32;
  _pop_(SFRS);
}

/************************************************************************************************************
*    Main function 
************************************************************************************************************/
void main (void)
{
/* Note
  WDT timer base is LIRC 10Khz
*/
    P32_QUASI_MODE;
//--------------------------------------------------------
//Warning:
//Pleaes always check CONFIG WDT disable first 
//only when WDT reset disable, WDT use as pure timer
//--------------------------------------------------------
    ENABLE_P17_PULLDOWN;
    WDT_Open(256);
    WDT_Interrupt(Enable);
    ENABLE_GLOBAL_INTERRUPT;
    while (P17)
    {
      set_WDCON_WDCLR;
    }

}