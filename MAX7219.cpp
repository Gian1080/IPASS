/////////////////////////////////////////////////////////////////////////////
// ==========================================================================
//Name: Gianluca Piccardo
//
// Copyright : gianluca.piccardo@student.hu.nl 2018
//
// Distributed under the Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt or copy at 
// http://www.boost.org/LICENSE_1_0.txt)
//
// ==========================================================================
/////////////////////////////////////////////////////////////////////////////



#include "MAX7219.hpp"



void MAX7219::setup()
	{
		uint8_t shutdownData [8] = {shutDown,0,shutDown,0,shutDown,0,shutDown,0};
		spiBus.write_and_read(chipSelect,8,shutdownData,nullptr);
		
		uint8_t decoder [8] = {decodeMode,0,decodeMode,0,decodeMode,0,decodeMode,0};
		spiBus.write_and_read(chipSelect,8,decoder,nullptr);
		
		uint8_t scanlimitData [8] = {scanLimit, 7,scanLimit, 7,scanLimit, 7,scanLimit, 7};
		spiBus.write_and_read(chipSelect,8,scanlimitData,nullptr);
		
		uint8_t startupData [8] = {shutDown,1,shutDown,1,shutDown,1,shutDown,1};
		spiBus.write_and_read(chipSelect,8,startupData,nullptr);
	}

void MAX7219::setBrightness(int screen, uint8_t B)
	{
		if(B > 15 )
		{
			B = 15;
		}
		if(B < 0 )
		{
			B = 0;
		}
		screenCommand(screen,brightness,B);
	}

void MAX7219::setAllBrightness(uint8_t B)
	{
	for(unsigned int screen = 1; screen < 5; screen++)
		{
			setBrightness(screen, B);
		}
	}

void MAX7219::clearChip()
	{
		uint8_t forLoopData [8] = {}; 
		for(unsigned int i=0; i<32; i++)
		{
			forLoopData[0] = i;
			forLoopData[1] = 0;
			spiBus.write_and_read(chipSelect,2,forLoopData,nullptr);
		}
	}

void MAX7219::setOldPixel(uint8_t Row, int Column)
	{
		uint8_t ColumnReplacer = 1 << (Column -1);
		uint8_t pixelSet [2] = {Row, ColumnReplacer};
		spiBus.write_and_read(chipSelect,2,pixelSet,nullptr);
	}

void MAX7219::flush()
	{
		for(unsigned int i=1; i<5; i++)
		{
			for(unsigned int j=0; j<8; j++)
			{
				screenCommand(i,j+1, bufferArray[j+((i-1)*8)]);
			}
		}
	}

void MAX7219::screenCommand(int screen, uint8_t row, uint8_t column)
	{
		if(screen<0 || screen > 4)
		{
			return;
		}
		for(auto & t : sendDataArray)
		{
			t = 0;
		}
		switch(screen)
		{
			case 1 : screen = 4;
				break;
			case 2 : screen = 3;
				break;
			case 3 : screen = 2;
				break;
			case 4 : screen = 1;
				break;
		}
		int tempScreen = (screen * 2 )-1;
		sendDataArray [tempScreen] = column;
		sendDataArray [tempScreen-1] = row;
		spiBus.write_and_read(chipSelect,8, sendDataArray, nullptr);
	}

void MAX7219::clearBuffer()
	{
		for(unsigned int i=0; i<32; i++)
		{
			bufferArray[i] = 0;
		}
	}

void MAX7219::setPixel(uint8_t X, int Y)
	{
		uint8_t bitMask = 1 << (Y-1);
		bufferArray[X-1] = bufferArray [X-1] | bitMask;
		
	}

void MAX7219::newSetPixel(uint8_t X, uint8_t Y, bool on)
	{
		if(X < 1 || X > 32 || Y < 1 || Y > 8)
		{
			return;
		}
		
		uint8_t remain = X % 8;
		uint8_t screen = X/8;
		if(remain != 0 )
		{
			screen++;
			remain = remain -1;
		}else
		{
			remain = 7;
		}
		if(on)
		{
		bufferArray[((screen-1)*8)+(Y-1)] |= ((1<<remain));
		}
		else{
		bufferArray[((screen-1)*8)+Y-1]&= (~(1<<remain));
		}
		(bufferArray[((screen-1)*8)+(Y-1)] == 127);
	}