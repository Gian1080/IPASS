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


#include "Characters.hpp"

void Character::drawToBuffer()
	{
		for(unsigned int y = 0; y < 8; y++)
		{
			for(unsigned int x = 0; x < 8; x++)
			{
				if(bitmap[7-y][x] == 1)
				{
					ledMatrix.newSetPixel(x+posx, y+posy, 1);
				}
				
			}
		}
	}