/*
 * 7SegmentNumbers.h
 *
 *  Created on: 28.07.2015
 *      Author: Lars
 */
#ifndef SEGMENTNUMBERS_H_
#define SEGMENTNUMBERS_H_

#include <msp430.h>
#include "stdint.h"

#define MAXBUFFLENGTH 216
#define SEGMENTLENGTH 36

#define SEGMENT5 180
#define SEGMENT4 144
#define SEGMENT3 108
#define SEGMENT2 72
#define SEGMENT1 36
#define SEGMENT0 0

#define SEC_STARTSEGMENT SEGMENT4
#define MIN_STARTSEGMENT SEGMENT2
#define HOUR_STARTSEGMENT SEGMENT0
#define TEMP_STARTSEGMENT SEGMENT0

#define HOUR_DOUBLEPOINTS 67
#define MIN_DOUBLEPOINTS 139

extern uint8_t clockBuffer[MAXBUFFLENGTH];

void clearClockBuffer();
void clearSingleSegment(int pos);
void storeNumberInClockBuffer(uint16_t number, uint16_t b, uint16_t r, uint16_t g, uint16_t points,const uint16_t pos);
void storeBCDInClockBuffer(uint8_t bcdValue, uint16_t b, uint16_t r, uint16_t g, uint16_t points, uint16_t leadingZero, uint16_t pos);
void setDoublePoints( uint16_t b, uint16_t r, uint16_t g, uint16_t points,uint16_t pos);


static const uint8_t numberTable[10][7];


#endif /* 7SEGMENTNUMBERS_H_ */
