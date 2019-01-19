#include<iostream>

using namespace std;
/*
**P(n) = 1.3.5....(2n + 1)
**S(n) = 1 + 3 + 5 + .. + (2n + 1)
*/
int P(int n)
{
	if(0 == n)
	{
		return 1;
	}
	else
	{
		return (2 * n - 1)* P(n - 1);
	}
}

int S(int n)
{
	if(0 == n)
	{
		return 0;
	}
	else
	{
		return (2 * n - 1) + S(n - 1);
	}
}
int main()
{
	int a = P(5);
	int b = S(5);
}