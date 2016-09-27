/*
 * RTC.h
 *
 *  Created on: 01.09.2015
 *      Author: lars
 */

#ifndef RTC_H_
#define RTC_H_

#include <msp430.h>
#include "stdint.h"

void init_RTC();
void set_RTC_DateTime(uint16_t year, uint8_t month, uint8_t day, uint8_t dayOfWeek, uint8_t hour, uint8_t minute, uint8_t second);

#endif /* RTC_H_ */
