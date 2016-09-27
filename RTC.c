/*
 * RTC.c
 *
 *  Created on: 01.09.2015
 *      Author: lars
 */

#include "RTC.h"

void init_RTC()
{
	// Configure LFXT 32kHz crystal
	CSCTL0_H = CSKEY >> 8;                  // Unlock CS registers
	CSCTL4 &= ~LFXTOFF;                     // Enable LFXT
	do
	{
	  CSCTL5 &= ~LFXTOFFG;                  // Clear LFXT fault flag
	  SFRIFG1 &= ~OFIFG;
	} while (SFRIFG1 & OFIFG);              // Test oscillator fault flag
	CSCTL0_H = 0;                           // Lock CS registers

	 // Configure RTC_C
	RTCCTL01 = RTCRDYIE | RTCBCD | RTCHOLD;
											// RTC enable, BCD mode, RTC hold
											// enable RTC read ready interrupt

	RTCYEAR = 0x2015;                       // Year = 0x2015
	RTCMON = 0x08;                           // Month = 0x08 = August
	RTCDAY = 0x13;                          // Day = 0x13 = 13th
	RTCDOW = 0x04;                          // Day of week = 0x01 = Thursday
	RTCHOUR = 0x18;                         // Hour = 0x16
	RTCMIN = 0x01;                          // Minute = 0x45
	RTCSEC = 0x22;                          // Seconds = 0x10

	//RTC Alarm register. Alarm wird nicht genutzt aber trotzdem auf einen definierten wert inititlaisiert.
	RTCADOWDAY = 0x2;                       // RTC Day of week alarm = 0x2
	RTCADAY = 0x20;                         // RTC Day Alarm = 0x20
	RTCAHOUR = 0x10;                        // RTC Hour Alarm
	RTCAMIN = 0x23;                         // RTC Minute Alarm

	RTCPS1CTL |= RT1IP__64 | RT1PSIE;		// RT1PSIFG Interrupt im 2Hz takt (128/64)

	RTCCTL01 &= ~(RTCHOLD);                 // Start RTC

}

void set_RTC_DateTime(uint16_t year, uint8_t month, uint8_t day, uint8_t dayOfWeek, uint8_t hour, uint8_t minute, uint8_t second)
{
	RTCCTL01 = RTCHOLD;		// RTC anhalten

	RTCYEAR = year;
	RTCMON = month;
	RTCDAY = day;
	RTCDOW = dayOfWeek;
	RTCHOUR = hour;
	RTCMIN = minute;
	RTCSEC = second;

	RTCCTL01 &= ~(RTCHOLD);	// RTC starten
}
