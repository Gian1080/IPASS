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
 
	MAX7219 mijnChip(spi,CS);
	mijnChip.setup();
	hwlib::wait_ms(2222);
	mijnChip.setBrightness(2);
	hwlib::wait_ms(2222);
	mijnChip.clearChip();
	hwlib::wait_ms(2222);
	mijnChip.setPixel(5,4);
	hwlib::wait_ms(2222);
	mijnChip.setPixel(5,5);
	hwlib::wait_ms(2222);
	mijnChip.setPixel(5,6);
	


}
