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


/*Power = paars
Ground = blauw
Data In = Groen
Chip Select = Geel
Clock = Oranje*/
#include "teeth.hpp"
#include "Characters.hpp"
#include "bitmap.hpp"

void showPoets(MAX7219 &ledMatrix)
{
	Character testP(P, ledMatrix,33,1);
	Character testO(O, ledMatrix,42,1);
	Character testE(E, ledMatrix,51,1);
	Character testT(T, ledMatrix,60,1);
	Character testS(S, ledMatrix,68,1);
	int counter1 = 0;
	while(counter1 < 111)
	{
		ledMatrix.clearBuffer();
		testS.drawToBuffer();
		testT.drawToBuffer();
		testO.drawToBuffer();
		testE.drawToBuffer();
		testP.drawToBuffer();
		
		testS.posx--;
		testT.posx--;
		testO.posx--;
		testE.posx--;
		testP.posx--;
		
		ledMatrix.flush();
		counter1 ++;
		
	}
}

void showStop(MAX7219 &ledMatrix)
{
	Character testS(S, ledMatrix,33,1);
	Character testT(T, ledMatrix,42,1);
	Character testO(O, ledMatrix,51,1);
	Character testP(P, ledMatrix,60,1);
	int counter1 = 0;
	while(counter1 < 88)
	{
		ledMatrix.clearBuffer();
		testS.drawToBuffer();
		testT.drawToBuffer();
		testO.drawToBuffer();
		testP.drawToBuffer();
		
		testS.posx--;
		testT.posx--;
		testO.posx--;
		testP.posx--;
		
		ledMatrix.flush();
		counter1 ++;
	}
	
}

void showTooth(MAX7219 &ledMatrix)
{
	teeth myTooth(ledMatrix);
	for(unsigned int i=1; i<5; i++)
	{
		myTooth.draw(i);
	}
		for(unsigned int i = 1; i < 5; i++)
	{
		for(unsigned int j= 1; j < 16; j++)
		{
			ledMatrix.setBrightness(i,j);
			hwlib::wait_ms(100);
		}
	}
}

void showreverseTooth(MAX7219 &ledMatrix)
{
	teeth myTooth(ledMatrix);
	for(unsigned int i=1; i<5; i++)
	{
		myTooth.reversedraw(i);
	}
		for(unsigned int i = 1; i < 5; i++)
	{
		for(unsigned int j= 1; j < 16; j++)
		{
			ledMatrix.setBrightness(i,j);
			hwlib::wait_ms(100);
		}
	}
}



int main( void )
{	
   // kill the watchdog
    WDT->WDT_MR = WDT_MR_WDDIS;
    
    namespace target = hwlib::target;
    auto DIN   = target::pin_out( target::pins::d5 );  //Data-in-pin;
    auto Clck = target::pin_out( target::pins::d7 );  //Clock-pin;
    auto CS = target::pin_out(target::pins::d3);     //Select-pin;
    auto spi  = hwlib::spi_bus_bit_banged_sclk_mosi_miso(Clck,DIN, hwlib::pin_in_dummy);
 
	MAX7219 myChip(spi,CS);
	teeth myTooth(myChip);
	myChip.setup();
	myChip.setAllBrightness(15);
	showPoets(myChip);
	showTooth(myChip);
	showreverseTooth(myChip);
	showStop(myChip);
	
}
