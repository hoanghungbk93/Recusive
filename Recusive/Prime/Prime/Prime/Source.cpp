#include <iostream>

using namespace std;

bool isPrime(int a, int i)
{
	if(1 == i)
	{
		if(1 == a)
		{
			return false;
		}
		return true;
	}
	else
	{
		if(0 == a % i)
		{
			return false;
		}
		else
		{
			isPrime(a, i - 1);
		}
	}
}
int main()
{
	bool a = isPrime(19, 10);
	bool b = isPrime(27, 13);
	bool c = isPrime(31, 15);
	bool d = isPrime(53, 22);
	bool e = isPrime(6, 3);
	bool f = isPrime(4, 2);
	bool g = isPrime(2, 1);
	bool h = isPrime(1, 1);
}