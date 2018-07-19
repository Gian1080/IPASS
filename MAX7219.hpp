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

#ifndef MAX7219_HPP
#define MAX7219_HPP

#include "hwlib.hpp"
#include "AbstractMAX7219.hpp"

namespace target = hwlib::target;

class MAX7219 : public AbstractMAX7219
{
private:
	hwlib::spi_bus_bit_banged_sclk_mosi_miso& spiBus;
	target::pin_out& chipSelect;
	const uint8_t no_Op				= 0x00;
	const uint8_t digit0 			= 0x01;
	const uint8_t digit1			= 0x02;
	const uint8_t digit2			= 0x03;
	const uint8_t digit3			= 0x04;
	const uint8_t digit4			= 0x05;
	const uint8_t digit5			= 0x06;
	const uint8_t digit6			= 0x07;
	const uint8_t digit7			= 0x08;
	const uint8_t decodeMode		= 0x09;
	const uint8_t brightness		= 0x0A;
	const uint8_t scanLimit			= 0x0B;
	const uint8_t shutDown			= 0x0C;
	const uint8_t displayTest		= 0x0F;
public:
	uint8_t sendDataArray [8] = {};
	uint8_t bufferArray [32]={};
	MAX7219(hwlib::spi_bus_bit_banged_sclk_mosi_miso& spiBus, target::pin_out& chipSelect):
	spiBus(spiBus),
	chipSelect(chipSelect)
	{}
	
	void setup() override;
	void setBrightness(int screen, uint8_t B) override;
	void setAllBrightness(uint8_t B) override;
	void clearChip() override;
	void setOldPixel(uint8_t Row, int Column) override;
	void flush() override;
	void screenCommand(int screen, uint8_t row, uint8_t column) override;
	void clearBuffer() override;
	void setPixel(uint8_t X, int Y) override;
	void newSetPixel(uint8_t X, uint8_t Y, bool on) override;

};
#endif //MAX7219_HPP