#include<iostream>
#include <algorithm> 
using namespace std;

void selectionSort(int a[], int n)
{
	int min = 0;
	int iMin = 0;
	for(int i = 0; i < n - 1; i++)
	{
		min = a[i];
		iMin = i;
		for(int j = i + 1; j < n; j++)
		{
			if(a[j] < min)
			{
				min = a[j];
				iMin = j;
			}
		}
		if(iMin != i)
		{
			int temp = a[i];
			a[i] = a[iMin];
			a[iMin] = temp;
		}
	}
}

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
	//sort(a, a + 10);

	int c = binarySeach(a,9, 0, 10);

}