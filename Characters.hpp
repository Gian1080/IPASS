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


#include "hwlib.hpp"
#include "MAX7219.hpp"
#include "teeth.hpp"

class Character
{
private:
		bool (&bitmap)  [8][8];
		MAX7219 &ledMatrix;
public:
	Character(bool (&bitmap) [8][8], MAX7219 &ledMatrix, int posx, int posy):
				bitmap(bitmap),
				ledMatrix(ledMatrix),
				posx(posx),
				posy(posy)
				{}
				
	int posx, posy;
				
	void drawToBuffer();

};