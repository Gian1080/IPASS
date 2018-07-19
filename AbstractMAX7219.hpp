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


#ifndef ABSTRACTMAX7219_HPP
#define ABSTRACTMAX7219_HPP


class AbstractMAX7219
{
public:

	virtual void setup()=0;
	virtual void setBrightness(int screen, uint8_t B)=0;
	virtual void setAllBrightness(uint8_t B)=0;
	virtual void clearChip()=0;
	virtual void setOldPixel(uint8_t Row, int Column)=0;
	virtual void flush()=0;
	virtual void screenCommand(int screen, uint8_t row, uint8_t column)=0;
	virtual void clearBuffer()=0;
	virtual void setPixel(uint8_t X, int Y)=0;
	virtual void newSetPixel(uint8_t X, uint8_t Y, bool on)=0;
};	
#endif //ABSTRACTMAX7219_HPP