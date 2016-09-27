
#include <fstream>
#include <iostream>

/************************************************************
* This header file defines the following classes/functions 
* to be used in the main Form (i.e., Form1)

PrintFile Classe:
* This class is used to print the final statistics
* into an Excel file

time_diff Function:
* This function provides the difference between two instances 
* of time.

time_add Function: 
* This function adds to instances of time together

perc Function:
* Gets two inputs as elapsed time_a and elapsedtime_b, 
* converst them into second and reports their ratio
* in a percentage format 

Developped by: Iman Faraji
************************************************************/

//IMAN: this class is used to print the final statistics into an Excel file
class PrintFile
{
public:
	std::fstream fs;

	PrintFile() {};

	bool OPEN()
	{
		fs.open("C:\\EFFICIENCY_TRACKER\\MY_EFFICIENCY_TRACKER.csv", std::fstream::in | std::fstream::out | std::fstream::app);
		return fs.is_open();
	}

	void WRITE(std::string st) 
	{
		fs<<st;
	}

	void CLOSE()
	{
		fs.close();
	}
};

void time_diff(int old_h, int old_m, int old_s, int new_h, int new_m, int new_s, int *diff)
{

	if (new_s >= old_s) diff[0] = new_s - old_s;
	else
	{
		if (new_m > 0)
		{
			new_s += 60;
			new_m--;
			diff[0] = new_s - old_s;
		}
		else
		{
			new_m += 59;
			new_s += 60;
			new_h--;
			diff[0] = new_s - old_s;
		}
	}
	if (new_m >= old_m) diff[1] = new_m - old_m;
	else
	{
		new_m += 60;
		new_h--;
		diff[1] = new_m - old_m;
	}

	diff[2] = new_h - old_h;
}


void time_add(int old_h, int old_m, int old_s, int new_h, int new_m, int new_s, int *d)
{
	d[0] = new_s + old_s;

	if (d[0] >= 60)
	{
		d[0] -= 60;
		new_m++;
	}

	d[1] = new_m + old_m;

	if (d[1] >= 60)
	{
		d[1] -= 60;
		new_h++;
	}

	d[2] = new_h + old_h;
}


long double  perc(int old_h, int old_m, int old_s, int new_h, int new_m, int new_s)
{
	int old_total_sec = 0, new_total_sec = 0;
	
	old_total_sec = 3600 * old_h + 60 * old_m + old_s;
	new_total_sec = 100 * (3600 * new_h + 60* new_m + new_s);

	return ((double) new_total_sec /(double) old_total_sec); 
}