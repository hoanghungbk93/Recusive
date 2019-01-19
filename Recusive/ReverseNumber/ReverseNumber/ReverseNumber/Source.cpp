#include <iostream>
#include <math.h>
using namespace std;

int reseverNumber(int number, int n)
{
	if(number < 10)
	{
		return number;
	}
	else
	{
		return (number % 10 * pow(10, n - 1)) + reseverNumber(number / 10, n -1)  ;
	}
}
int main()
{
	int a = reseverNumber(1, 1);
}