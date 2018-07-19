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


#include "teeth.hpp"

void teeth::draw(int screen)
	{
		for(int i=0; i<8; i++)
		{
		ledMatrix.screenCommand(screen,i+1,tooth[i]);
		}
	}

void teeth::reversedraw(int screen)
	{
		for(int i=0; i<8; i++)
		{
		ledMatrix.screenCommand(screen,i+1,tooth[7-i]);
		}
	}
	