#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h> 
#include <iomanip>
#include <sstream>
#include <stdlib.h>
#include <time.h>

#include "generate_file.h"
using namespace std;
int main()
{
	string file_name("firData");
	int start = 1;
	int numOfData = 64;
	int stride = 1;
	generate_int_dec_num_upcounter_tofile(file_name,start,numOfData,stride);
	
	return 0;
}
