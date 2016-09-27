/*
 * SPI.c
 *
 *  Created on: 28.07.2015
 *      Author: Lars
 */
#include "ClockSPI.h"

// ################## Init Rutienen ##################

void init_ClockSPI()
{
	UCA1CTLW0 = UCSWRST; //stop UCB0
	UCA1CTLW0 |= UCCKPH + UCMST + UCMODE_0 + UCSYNC + UCMSB; // 3-pin 8Bit SPI-Master
	UCA1CTLW0 |= UCSSEL__SMCLK; // Select SMCLK  as BRCLK

	UCA1BRW_L = 0x02; //Set Clock Divider 2
	UCA1BRW_H = 0x00;

	P2SEL0 &= ~BIT5; //Configure Port 2.5 to SPI Mode MOSI
	P2SEL1 |= BIT5;

	P2SEL0 &= ~BIT4; //Configure Port 2.4 to SPI Mode CLK
	P2SEL1 |= BIT4;

	UCA1CTLW0 &= ~ UCSWRST; // Start SPI

	// Configure P1.5 as Blank
	P1SEL0 &= ~BIT5;
	P1SEL1 &= ~BIT5;
	P1DIR |= BIT5;

	// Configure P1.4 as Latch
	P1SEL0 &= ~BIT4;
	P1SEL1 &= ~BIT4;
	P1DIR |= BIT4;
}

// ################## Sende Rutienen ##################

void send_ClockSPI()
{
	int i;

	i=MAXBUFFLENGTH;
	while (i>0)
	{
		UCA1TXBUF = clockBuffer[i-1];
		while((UCA1STATW & UCBUSY) != 0){};
		i--;
	}

	// Blank the clock
	P1OUT |= BIT5;

	// Latch
	P1OUT |= BIT4;
	P1OUT &= ~BIT4;

	// UnBlank the clock
	P1OUT &= ~BIT5;
}
