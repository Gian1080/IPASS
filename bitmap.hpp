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


#ifndef BITMAP_HPP
#define BITMAP_HPP

bool A				 [8][8]= 		 {{0,0,0,1,1,0,0,0},
									  {0,0,1,0,0,1,0,0},
									  {0,0,1,0,0,1,0,0},
									  {0,0,1,0,0,1,0,0},
									  {0,0,1,1,1,1,0,0},
									  {0,0,1,0,0,1,0,0},
									  {0,0,1,0,0,1,0,0},
									  {0,0,1,0,0,1,0,0}};

bool B 				[8][8]=  		 {{0,0,1,1,1,0,0,0},
									  {0,0,1,0,0,1,0,0},
									  {0,0,1,0,0,1,0,0},
									  {0,0,1,1,1,0,0,0},
									  {0,0,1,1,1,0,0,0},
									  {0,0,1,0,0,1,0,0},
									  {0,0,1,0,0,1,0,0},
									  {0,0,1,1,1,0,0,0}};
									  
bool S				[8][8]=		   {{0,1,1,1,1,1,1,0},
									{1,1,1,1,1,1,1,1},
									{1,1,1,0,0,0,0,0},
									{1,1,1,1,1,1,1,0},
									{0,1,1,1,1,1,1,1},
									{0,0,0,0,0,1,1,1},
									{1,1,1,1,1,1,1,1},
									{0,1,1,1,1,1,1,0}};
	
bool T				[8][8]=			{{1,1,1,1,1,1,1,0},
									{1,1,1,1,1,1,1,0},
									{0,0,1,1,1,0,0,0},
									{0,0,1,1,1,0,0,0},
									{0,0,1,1,1,0,0,0},
									{0,0,1,1,1,0,0,0},
									{0,0,1,1,1,0,0,0},
									{0,0,1,1,1,0,0,0}};
	
bool O				[8][8]=			{{0,1,1,1,1,1,1,0},
									{1,1,1,1,1,1,1,1},
									{1,1,1,0,0,1,1,1},
									{1,1,1,0,0,1,1,1},
									{1,1,1,0,0,1,1,1},
									{1,1,1,0,0,1,1,1},
									{1,1,1,1,1,1,1,1},
									{0,1,1,1,1,1,1,0}};
	
bool P				[8][8]=			{{1,1,1,1,1,1,1,0},
									{1,1,1,1,1,1,1,1},
									{1,1,1,0,0,1,1,1},
									{1,1,1,1,1,1,1,1},
									{1,1,1,1,1,1,1,0},
									{1,1,1,0,0,0,0,0},
									{1,1,1,0,0,0,0,0},
									{1,1,1,0,0,0,0,0}};	
	
bool E				[8][8]=			{{1,1,1,1,1,1,1,1},
									{1,1,1,1,1,1,1,1},
									{1,1,1,0,0,0,0,0},
									{1,1,1,1,1,1,0,0},
									{1,1,1,1,1,1,0,0},
									{1,1,1,0,0,0,0,0},
									{1,1,1,1,1,1,1,1},
									{1,1,1,1,1,1,1,1}};
#endif // BITMAP_HPP