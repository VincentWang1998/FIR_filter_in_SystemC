/*****************************************************************************
[file name]--------------
FIR16.h
[editor]----
yu-wen Wang (vincent08tw@gmail.com) (vincent08tw@yahoo.com.tw)
[create date]---
2022-01-04
[last edit]---
2022-01-04 
*****************************************************************************/ 
#ifndef FIR16_H
#define FIR16_H

#include "systemc.h"

SC_MODULE(FIR16)
{
	// port definition
	sc_in <bool> clk;
	sc_in <bool> rst;	
	sc_in <sc_uint<32> > x;
	sc_out<sc_uint<32> > y;
	
	
	// data and function members
	//int count;
	void fir16();
	sc_uint<32> input, output;
	
	sc_signal<sc_uint<32> > d1, d2, d3, d4,
							d5, d6, d7, d8,
							d9, d10,d11,d12,
							d13,d14,d15;
	
	sc_uint<32> b0, b1, b2, b3 ,
				b4, b5, b6, b7 ,
				b8, b9, b10,b11,
				b12,b13,b14,b15;
	// constructor
	SC_CTOR(FIR16)
	{
		// sensitivity list
		SC_CTHREAD(fir16, clk.pos()); // positive edge trigger clock 
		reset_signal_is(rst, false); // synchronous active-low
	}
};

#endif