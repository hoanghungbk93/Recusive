#include<iostream>
using namespace std;

int binarySeach(int a[], int k, int low, int high)
{
	if(low > high)
	{
		return -1;
	}
	int mid = (low + high) / 2;

	if(a[mid] == k)
	{
		return mid;
	}
	else if(a[mid] < k)
	{
		low = mid + 1;
		binarySeach(a, k, low, high);
	}
	else
	{
		high = mid - 1;
		binarySeach(a, k, low, high);
	}
}
int main()
{
	int  a[11] = {1,2,3,4,5,6,7,8,10,11,12};
	int c = binarySeach(a,9, 0, 10);

}