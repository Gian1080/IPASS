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


#ifndef TEETH_HPP
#define TEETH_HPP

#include "MAX7219.hpp"

class teeth
{
private:
	uint8_t tooth [8]={102,255,255,126,126,126,90,66};
	MAX7219& ledMatrix;
public:
	teeth(MAX7219& ledMatrix):
	ledMatrix(ledMatrix)
	{}
	void draw(int screen);
	void reversedraw(int screen);
};

#endif //TEETH_HPP