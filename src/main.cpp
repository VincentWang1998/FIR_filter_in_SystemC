/*****************************************************************************
[file name]--------------
main.cpp
[editor]----
yu-wen Wang (vincent08tw@gmail.com) (vincent08tw@yahoo.com.tw)
[create date]---
2022-01-04
[last edit]---
2022-01-04 
*****************************************************************************/ 
#define MEM_DEPTH 64
#define NUM_OF_TAP 16
#include "FIR16.h"

int sc_main(int argc, char* argv[])
{
	sc_signal<sc_uint<32> > x;
	sc_signal<sc_uint<32> > y;
	sc_signal<bool> rst;
	
	//sc_time clkPrd(10, SC_NS); // 100MHz
	sc_time clkPrd(5, SC_NS); // 200MHz
	sc_time clkDly( 0, SC_NS);
	// sc_clock(name, period, duty_cycle, start_time, pos_edge_first)
	sc_clock clk("clk", clkPrd, 0.50, clkDly, true);
	
	// instantiation
	FIR16 fir16_1("fir16_1");
	fir16_1.clk(clk);
	fir16_1.rst(rst);
	fir16_1.x(x);
	fir16_1.y(y);
	
	// open and read file 
	std::ifstream ifs("firData");
	if(!ifs.is_open())
	{
		cout << "failed to open file... " << endl;
		return (0);
	}
	
	// tracing:
	// trace file creation, with VCD type output
	sc_trace_file *tf = sc_create_vcd_trace_file("RESULT");
	// External signals
	sc_trace(tf, clk, "clk" );
	sc_trace(tf, rst, "rst");
	sc_trace(tf, x, "x");
	sc_trace(tf, y, "y");
	
	//reset the timer for 3 cycles before it is released for counting
	sc_start(0, SC_NS);
	rst.write(0);
	sc_start(2*clkPrd);
	rst.write(1);
	for(int i = 0;i < (MEM_DEPTH + NUM_OF_TAP);i++)
	{
		int data;
		if(i < MEM_DEPTH)
		{
			ifs >> data;
		}
		else
		{
			data = 0;
		}
		x.write(data);
		cout << "data = " << data << endl;
		sc_start(clkPrd); // for 1 cycle
		cout << "x = " << x << endl
			 << "y = " << y << endl;
	}
	
	ifs.close();
	sc_close_vcd_trace_file(tf);
	
	return (0);
}