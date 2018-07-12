/*Power = paars
Ground = blauw
Data In = Groen
Chip Select = Geel
Clock = Oranje*/
#include "hwlib.hpp"
#include "MAX7219.hpp"

int main( void )
{	
   // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    
    namespace target = hwlib::target;
    auto DIN   = target::pin_out( target::pins::d5 );  //Data-in-pin;
    auto Clck = target::pin_out( target::pins::d7 );  //Clock-pin;
    auto CS = target::pin_out(target::pins::d3);     //Select-pin;
    auto spi  = hwlib::spi_bus_bit_banged_sclk_mosi_miso(Clck,DIN, hwlib::pin_in_dummy);
 
 
	
	uint8_t testerAdres = 0x0C;
	uint8_t testertje [8] = {testerAdres,1,testerAdres,1,testerAdres,1,testerAdres,1};
	spi.write_and_read(CS,8,testertje,nullptr);
	hwlib::wait_ms(222);	
	uint8_t TestdecodeAdres = 0x09;
	uint8_t TestdecodeData [8] = {TestdecodeAdres,0,TestdecodeAdres,0,TestdecodeAdres,0,TestdecodeAdres,0};
	spi.write_and_read(CS,8,TestdecodeData,nullptr);
	hwlib::wait_ms(222);
	uint8_t TestscanLimit = 0x0B;
	uint8_t TestscanData [8] = {TestscanLimit, 7,TestscanLimit, 7,TestscanLimit, 7,TestscanLimit, 7};
	spi.write_and_read(CS,8,TestscanData,nullptr);
	hwlib::wait_ms(222);
	uint8_t laatsteScherm [8] = {1,0,1,0,1,0,7,7};
	spi.write_and_read(CS,8,laatsteScherm,nullptr);
	MAX7219 mijnChip(spi,CS);
	
	mijnChip.setup();
	hwlib::wait_ms(222);
	
	
	mijnChip.clearChip();
	hwlib::wait_ms(555);
	
	mijnChip.setPixel(5,4);
	hwlib::wait_ms(555);
	
	mijnChip.setPixel(5,5);
	hwlib::wait_ms(555);
	
	hwlib::wait_ms(555);
	
	mijnChip.multiSetPixel(1,1,1);
	mijnChip.multiSetPixel(1,6,1);
	mijnChip.multiSetPixel(1,4,1);
	mijnChip.multiSetPixel(1,2,3);
	hwlib::wait_ms(322);
	mijnChip.setBrightness(1,15);
	hwlib::wait_ms(232);
	mijnChip.setBrightness(1,1);
	hwlib::wait_ms(333);
	mijnChip.setBrightness(1,15);
	mijnChip.flush();

}
