#ifndef GENERATE_FILE_H
#define GENERATE_FILE_H

using namespace std;

unsigned random_hex()
{
	unsigned c_hex;
	c_hex = rand() % 16;
	return c_hex;
}
void generate_hex_num_tofile(string filename, int DataSize, int NumberOfData)
{
	ofstream fout(filename.c_str());
	int i, j;
	if(!fout) // detect if fail to open file
	{    
		cout << "fail to open " << filename << " !!" << endl;
	}
	else
	{
		for(i = 0; i < NumberOfData;i++)
		{
			for(j = 0;j < DataSize;j++)
			{
				if(j == 0)
				{
					fout << 0;
				}
				else
				{
					fout << hex << random_hex();	
				}
			}
			fout << endl;
		}
		fout.close();   // close file  
	}
}
void generate_int_dec_num_upcounter_tofile(string filename, int start, int NumberOfData, int stride)
{
	ofstream fout(filename.c_str());
	
	int data = start;
	int i;
	if(!fout) // detect if fail to open file
	{    
		cout << "fail to open " << filename << " !!" << endl;
	}
	else if(NumberOfData <= 0)
	{
		cout << "error in function \"generate_int_dec_num_upcounter_tofile\" "
			 << endl 
			 << " >> the numberOfData should be more than zero!! "
			 << endl << endl;	
	}
	else
	{
		for(i = 0; i < NumberOfData;i++)
		{
			fout << data 
				 << endl;
			data += stride;
		}
		fout.close();   // close file  
		cout << "file: " << filename << " is created! " << endl;
	}
}

#endif
