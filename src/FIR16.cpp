/*****************************************************************************
[file name]--------------
FIR16.cpp
[editor]----
yu-wen Wang (vincent08tw@gmail.com) (vincent08tw@yahoo.com.tw)
[create date]---
2022-01-04
[last edit]---
2022-01-04 
*****************************************************************************/ 
#include "FIR16.h"

void FIR16::fir16()
{
	// reset
	b0  = 0x00000F0F;
	b1  = 0x00000F0F;
	b2  = 0x00000F0F;
	b3  = 0x00000F0F;
	b4  = 0x00000F0F;
	b5  = 0x00000F0F;
	b6  = 0x00000F0F;
	b7  = 0x00000F0F;
	b8  = 0x00000F0F;
	b9  = 0x00000F0F;
	b10 = 0x00000F0F;
	b11 = 0x00000F0F;
	b12 = 0x00000F0F;
	b13 = 0x00000F0F;
	b14 = 0x00000F0F;
	b15 = 0x00000F0F;
	
	d1  = 0;
	d2  = 0;
	d3  = 0;
	d4  = 0;
	d5  = 0;
	d6  = 0;
	d7  = 0;
	d8  = 0;
	d9  = 0;
	d10 = 0;
	d11 = 0;
	d12 = 0;
	d13 = 0;
	d14 = 0;
	d15 = 0;
		
	//computation
	while(1)
	{
		wait();
		input = x.read();
		
		d1  = input;
		d2  = d1;
		d3  = d2;
		d4  = d3;
		d5  = d4;
		d6  = d5;
		d7  = d6;
		d8  = d7;
		d9  = d8;
		d10 = d9;
		d11 = d10;
		d12 = d11;
		d13 = d12;
		d14 = d13;
		d15 = d14;
		
		output = b0  * input 
			   + b1  * d1.read()
			   + b2  * d2.read()
			   + b3  * d3.read()
               + b4  * d4.read()
               + b5  * d5.read()
               + b6  * d6.read()
               + b7  * d7.read()
               + b8  * d8.read()
               + b9  * d9.read()
               + b10 * d10.read()
               + b11 * d11.read()
               + b12 * d12.read()
               + b13 * d13.read()
               + b14 * d14.read()
               + b15 * d15.read();
		
		y.write(output);
	}
}