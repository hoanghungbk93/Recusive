#include <iostream>

using namespace std;
int convertDecimaToBinary(int decimaNumber)
{
	if(decimaNumber == 0)
	{
		return 0;
	}
	else
	{
		return decimaNumber % 2 + 10 * convertDecimaToBinary(decimaNumber/2);
	}
}
int main()
{
	int a = 31;

	int b = convertDecimaToBinary(a);
}