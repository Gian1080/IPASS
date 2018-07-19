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

///////////
///@file///
///////////

#include "hwlib.hpp"
#include "AbstractMAX7219.hpp"

namespace target = hwlib::target;

///\brief
/// A MAX7219 C++ library.
///\details
/// https://datasheets.maximintegrated.com/en/ds/MAX7219-MAX7221.pdf
/// A comprehensive library with multiple tools to use, easily implementable
/// and expandable. Needs hwlib.hpp for the real bare-metal programming.
/// Uses SPI and it connects to the 3,5V for a single matrix, 5V for multiple 
/// matrixes. 

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
	///\brief
/// Makes the chip ready for use.
///\details
/// Shuts the chip down, sets the scan limit on the correct value and than turns the chip on again.
	void setup() override;
	///\brief
/// Regulates screen brightness.
///\details
/// Sets the brightness on the screen according to the input of the user. 
/// Values can range from 0 = no light, to 15 = maximum brightness.
/// the int screen directs the value to the correct screen.
	void setBrightness(int screen, uint8_t B) override;
	///\brief
/// Changes brightness on all screens.
///\details
/// Calls forth the setBrightness function multiple times to adjust
/// the brightness accordingly.
	void setAllBrightness(uint8_t B) override;
	///\brief
/// Clears the chip of any values it holds.
///\details
/// Loops through the array to set any individual value to 0.
	void clearChip() override;
	///\brief
/// Turns on a individual led directly on the matrix.
///\details
/// Turns on a individual pixel by bitshifting the chosen value directly to the led-matrix.
/// Only one led can be turned on per individual row.
	void setOldPixel(uint8_t Row, int Column) override;
	///\brief
/// Flushes a buffer array to the led-matrix.
///\details
/// Calls forth the screen command function to write the bufferarray to the led-matrix.
/// This bufferarray elements will be sent to the correct OP-code.
	void flush() override;
	///\brief
/// The main command function to write commands or values to the MAX7219-chip.
///\details
/// With the correct input a command will be sent to the correct screen. This function
/// can adress all needed OP-adresses with BCD-codes for the MAX7219-chip.
	void screenCommand(int screen, uint8_t row, uint8_t column) override;
	///\brief
/// Clears the buffer from values it holds, setting them to 0.
///\details
/// Loops through the buffer-array to clear it from values it holds at that moment.
	void clearBuffer() override;
	///\brief
/// Turns on a individual led in the buffer-array.
///\details
/// Turns on a individual led in the buffer-array by bitsetting it.
/// Multiple leds can be turned on on the same row.
	void setPixel(uint8_t X, int Y) override;
	///\brief
/// Reverses the X and Y axis.
///\details
/// This function makes it possible to have characters and symbols that scroll through the horizontal plane
/// of the led-matrixes when you have more then one matrix alligned.
/// Orientates the 1,1 led coordinate to the corner led closest to the CLOCK input cable and making the X-axis 
/// 32 wide, and the Y-axis 8 high.
	void newSetPixel(uint8_t X, uint8_t Y, bool on) override;

};
#endif //MAX7219_HPP