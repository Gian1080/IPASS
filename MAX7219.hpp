#ifndef MAX7219_HPP
#define MAX7219_HPP

#include "hwlib.hpp"
namespace target = hwlib::target;

class MAX7219
{
private:
	hwlib::spi_bus_bit_banged_sclk_mosi_miso& spiBus;
	target::pin_out& chipSelect;
public:
	MAX7219(hwlib::spi_bus_bit_banged_sclk_mosi_miso& spiBus, target::pin_out& chipSelect):
	spiBus(spiBus),
	chipSelect(chipSelect)
	{}
	
	void setup()
	{
	uint8_t adresShutdown = 0x0C;
	uint8_t wakeupData [2] = {adresShutdown,1};
	uint8_t decodeAdres = 0x09;
	uint8_t decodeData [2] = {decodeAdres,0};
	uint8_t scanLimit = 0x0B;
	uint8_t scanData [2] = {scanLimit, 7};
	uint8_t brightnessAdress = 0x0A;
	uint8_t brightnessData [2] = {brightnessAdress,15};
	spiBus.write_and_read(chipSelect,2,decodeData,nullptr);
	spiBus.write_and_read(chipSelect,2,scanData,nullptr);
	spiBus.write_and_read(chipSelect,2,wakeupData,nullptr);
	spiBus.write_and_read(chipSelect,2,brightnessData,nullptr);
	}
	
	void setBrightness(uint8_t B)
	{
		if(B > 15 )
		{
			B = 15;
		}
		if(B < 0 )
		{
			B = 0;
		}
		uint8_t brightnessAdress = 0x0A;
		uint8_t brightnessData [2] = {brightnessAdress,B};
		spiBus.write_and_read(chipSelect,2,brightnessData,nullptr);
	}
	
	void clearChip()
	{
		uint8_t forLoopData [2] = {}; 
		for(unsigned int i=0; i<9; i++)
		{
			hwlib::wait_ms(77);
			forLoopData[0] = i;
			forLoopData[1] = 0;
			spiBus.write_and_read(chipSelect,2,forLoopData,nullptr);
		}
	}
	
	void setPixel(uint8_t Row, int Column)
	{
		uint8_t ColumnReplacer = 1 << (Column -1);
		uint8_t pixelSet [2] = {Row, ColumnReplacer};
		spiBus.write_and_read(chipSelect,2,pixelSet,nullptr);
	}
	
	void 
};
#endif //MAX7219_HPP