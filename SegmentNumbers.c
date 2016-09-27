/*
 * 7SegmentNumbers.c
 *
 *  Created on: 28.07.2015
 *      Author: Lars
 */
#include "SegmentNumbers.h"

// ############# Data #############

uint8_t clockBuffer[MAXBUFFLENGTH];

static const uint8_t numberTable[10][7]=
{
//		{1,0,0,0,0,0,0},
//		{0,1,0,0,0,0,0},
//		{0,0,1,0,0,0,0},
//		{0,0,0,1,0,0,0},
//		{0,0,0,0,1,0,0},
//		{0,0,0,0,0,1,0},
//		{0,0,0,0,0,0,1},
//		{0,0,0,0,0,0,0},
//		{0,0,0,0,0,0,0},
//		{0,0,0,0,0,0,0},
		{1,1,0,1,1,1,1},	// 0
		{0,0,0,0,0,1,1},	// 1
		{1,0,1,1,1,0,1},	// 2
		{1,0,1,0,1,1,1},	// 3
		{0,1,1,0,0,1,1},	// 4
		{1,1,1,0,1,1,0},	// 5
		{1,1,1,1,1,1,0},	// 6
		{1,0,0,0,0,1,1},	// 7
		{1,1,1,1,1,1,1},	// 8
		{1,1,1,0,1,1,1},	// 9
};

// #################################

// ############# Functions #############

void clearClockBuffer()
{
	int i;

	i=0;
	while(i<216)
	{
		clockBuffer[i] = 0x00;
		i++;
	}
}

void clearSingleSegment(int pos)
{
	int i;

	i=0;
	while(i<SEGMENTLENGTH)
	{
		clockBuffer[i]=0x00;
		i++;
	}
}

void fill(uint16_t b, uint16_t r, uint16_t g, uint16_t pos, uint16_t nibble)
{
	if(nibble != 0) // Linie f�ngt im halben Byte an
	{
		clockBuffer[pos + 4] = g >> 4;		// Grün MSB
		clockBuffer[pos + 3] = g << 4;		// Grün LSB
		clockBuffer[pos + 3] |= r >> 8;		// Rot MSB
		clockBuffer[pos + 2] = r & 0x00FF;	// ROT LSB
		clockBuffer[pos + 1] = b >> 4;		// Blau MSB
		clockBuffer[pos + 0] |= b << 4;		// Blau LSB
	}
	else
	{
		clockBuffer[pos + 4] |= g >> 8;		// Grün MSB
		clockBuffer[pos + 3] = g & 0x00FF;	// Grün LSB
		clockBuffer[pos + 2] = r >> 4;		// Rot MSB
		clockBuffer[pos + 1] = r << 4;		// Rot LSB
		clockBuffer[pos + 1] |= b >> 8;		// Blau MSB
		clockBuffer[pos + 0] = b & 0x00FF;	// BLau LSN
	}
}

void storeNumberInClockBuffer(uint16_t number, uint16_t b, uint16_t r, uint16_t g, uint16_t points,const uint16_t pos)
{
	int i, k, nibble;

	nibble = 0;

	k=0;

	for(i=0; i<7; i++)
	{
		if(numberTable[number][i]!=0) // Linie wird f�r Anzeige gebraucht
		{
			if(nibble != 0) // Linie f�ngt im halben Byte an
			{
				fill(b,r,g,pos+k,nibble);

				nibble = 0;
				k = k + 5;
			}
			else // Linie f�ngt im ganzen Byte an
			{
				fill(b,r,g,pos+k,nibble);

				nibble = 1;
				k = k + 4;
			}
		}

		else // Linie wird nicht f�r Anzeige gebraucht
		{
			if(nibble !=0) // Linie f�ngt im halben Byte an
			{
				fill(0x0000,0x0000,0x0000,pos + k,nibble);

				nibble = 0;
				k = k + 5;
			}
			else // Linie f�ngt im ganzen Byte an
			{
				fill(0x0000,0x0000,0x0000,pos + k,nibble);

				nibble = 1;
				k = k + 4;
			}
		}
	}

	setDoublePoints(b,r,g,points,pos+31);
}

void storeBCDInClockBuffer(uint8_t bcdValue, uint16_t b, uint16_t r, uint16_t g, uint16_t points, uint16_t leadingZero, uint16_t pos)
{
	uint16_t lowDigit = bcdValue & 0x000F;
	uint16_t highDigit = ((bcdValue & 0x00F0) >> 4);

	storeNumberInClockBuffer(lowDigit,b,r,g,points,pos + SEGMENTLENGTH);

	if(highDigit == 0)
	{
		if(leadingZero)
		{
			storeNumberInClockBuffer(highDigit,b,r,g, 0, pos);
		}
		else
		{
			clearSingleSegment(pos);
		}
	}
	else
	{
		storeNumberInClockBuffer(highDigit,b,r,g,0, pos);
	}

}

void setDoublePoints( uint16_t b, uint16_t r, uint16_t g,uint16_t points, uint16_t pos)
{
	if (points != 1)
	{
		r = 0x0000;
		g = 0x0000;
		b = 0x0000;
	}

	fill(b,r,g,pos,1);
//	clockBuffer[pos + 4] = g >> 4;		// Grün MSB
//	clockBuffer[pos + 3] = g << 4;		// Grün LSB
//	clockBuffer[pos + 3] |= r >> 8;		// Rot MSB
//	clockBuffer[pos + 2] = r & 0x00FF;	// ROT LSB
//	clockBuffer[pos + 1] = b >> 4;		// Blau MSB
//	clockBuffer[pos + 0] = b << 4;		// Blau LSB
}
