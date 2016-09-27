#include <msp430.h> 
#include "stdint.h"

#include "ClockSPI.h"
#include "SegmentNumbers.h"
#include "RTC.h"

#include "simplelink.h"
#include "sl_common.h"

/*
 * main.c
 */

/* ############### Defines und globale Variablen ###############*/

#define INVALIDRTCVALUE 0x80

typedef enum
{
	clockIntInitValue = 0x00,
	clockReady = 0x01,
	Hz2Interrupt = 0x02

}ClockInterrupt;

uint16_t doublePoints = 1;
uint16_t red, green, blue;

static ClockInterrupt aktInterrupt;

static inline void setAktInerrupt(ClockInterrupt value)
{
	aktInterrupt = value;
}
static inline ClockInterrupt getAktInterrupt()
{
	return aktInterrupt;
}



/* ############### Funktionen ###############*/

/* --------------- Init Funktionen ---------------*/
void init_Clock()
{
	CSCTL0_H = 0xA5;
	CSCTL0_L = 0;
	CSCTL1 = DCORSEL + DCOFSEL0 + DCOFSEL1;     /* Set DCO setting = 8MHz */
	CSCTL2 = SELA_1 + SELS_3 + SELM_3;          /*set ACLK - VLO, the rest = MCLK = DCO*/
	CSCTL3 = DIVA_0 + DIVS_0 + DIVM_0;          /* set all dividers to 0 */
}

/* --------------- Normale Funktionen ---------------*/
void storeTimeInClockBuffer()
{
	clearClockBuffer();
	storeBCDInClockBuffer(RTCHOUR,blue,red,green,0,0,HOUR_STARTSEGMENT);
	storeBCDInClockBuffer(RTCMIN,blue,red,green,0,1,MIN_STARTSEGMENT);
	storeBCDInClockBuffer(RTCSEC,blue,red,green,0,1,SEC_STARTSEGMENT);
}

void toggleDoublePoints()
{
	setDoublePoints(blue ,red,green, doublePoints, HOUR_DOUBLEPOINTS);
	setDoublePoints(blue ,red,green, doublePoints, MIN_DOUBLEPOINTS);

	doublePoints ^= 0x0001;
}

/* ############### Main ###############*/

int main(void)
{
	red = 0x00FF;
	green = 0x00A0;
	blue = 0x0000;

	setAktInerrupt(clockIntInitValue);	// Initialisierungsvalue für RTC Interupts

    WDTCTL = WDTPW | WDTHOLD;			// Stop watchdog timer

    init_Clock();

    init_ClockSPI();					// ClockSPI Initialisieren

    PJSEL0 = BIT4 | BIT5;       		// Initialize LFXT pins (RTC relevant)

    PM5CTL0 &= ~LOCKLPM5;       		// Disable the GPIO power-on default high-impedance mode

    init_RTC();

    __bis_SR_register(GIE); // Enable all Interrupts

    P1OUT |= BIT5; // Blank the clock
    clearClockBuffer();
    send_ClockSPI();

    while(1)
    {
    	switch(getAktInterrupt())
    	{
    		case clockReady:	// RTC-Ready Interrupt Zeit in Buffer ablegen
    			storeTimeInClockBuffer();
    			break;

    		case Hz2Interrupt:	// 2 Hz Interrupt Doppelpunkte toggeln und Buffer raussenden
    			toggleDoublePoints();
    			send_ClockSPI();
    			break;
    	}
    	 __bis_SR_register(LPM3_bits);     // Enter LPM3 mode
    }

	return 0;
}

/* ############### Interrupt Routinen ###############*/

// RTC Interrupts
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=RTC_VECTOR
__interrupt void RTC_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(RTC_VECTOR))) RTC_ISR (void)
#else
#error Compiler not supported!
#endif
{
    switch(__even_in_range(RTCIV, RTCIV_RT1PSIFG))
    {
        case RTCIV_NONE:      break;        // No interrupts
        case RTCIV_RTCOFIFG:  break;        // RTCOFIFG
        case RTCIV_RTCRDYIFG:               // RTCRDYIFG
        	setAktInerrupt(clockReady);
        	_BIC_SR(LPM3_EXIT); // exit LPM3 mode
        	break;
        case RTCIV_RTCTEVIFG: break;        // RTCEVIFG
        case RTCIV_RTCAIFG:   break;        // RTCAIFG
        case RTCIV_RT0PSIFG:  break;        // RT0PSIFG
        case RTCIV_RT1PSIFG:				// RT1PSIFG
        	setAktInerrupt(Hz2Interrupt);
        	_BIC_SR(LPM3_EXIT); // exit LPM3 mode
        	break;
        default: break;
    }
}
