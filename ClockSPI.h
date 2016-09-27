/*
 * SPI.h
 *
 *  Created on: 28.07.2015
 *      Author: Lars
 */
#ifndef CLOCKSPI_H_
#define CLOCKSPI_H_

#include <msp430.h>
#include "stdint.h"
#include "SegmentNumbers.h"

void init_ClockSPI();
void send_ClockSPI();
void clear_Clock();


#endif /* CLOCKSPI_H_ */
