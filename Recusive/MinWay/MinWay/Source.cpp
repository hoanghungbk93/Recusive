#include <iostream>
#include <vector>
#include <iomanip> 
using namespace std;

int main()
{
	int maze[5][5] = {
		{0, 10, 0, 0 , 5},
		{0, 0, 1, 0 , 2},
		{0, 0, 0, 4 , 0},
		{7, 0, 6, 0 , 0},
		{0, 0, 9, 2 , 0},
	};
	ios::fmtflags old_settings = cout.flags(); //save previous format flags
	int old_precision = cout.precision(); // save previous precision setting
	cout << setprecision(8);
	cout<<setw(4)<<12<<endl;
	cout<<setw(4)<<1<<endl;
	cout<<setw(4)<<123<<endl;
		
	cout << setprecision(old_precision);
	cout.flags(old_settings);
	cout<<setw(4)<<12<<endl;
	cout<<setw(4)<<1<<endl;
	cout<<setw(4)<<123<<endl;
	system("pause");
	return 0;
}