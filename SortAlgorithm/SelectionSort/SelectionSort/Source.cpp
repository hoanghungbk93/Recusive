#include <iostream>

using namespace std;
void selectionSortRecusive(int a[], int n, int &start)
{
	if(start == n - 1)
	{
		return;
	}
	int min = a[start];
	int imin = start;
	for(int i = start + 1; i < n; i++)
	{
		if(a[i] < min)
		{
			min = a[i];
			imin = i;
		}
	}
	if(imin != start)
	{
		int temp = a[start];
		a[start] = a[imin];
		a[imin] = temp;
	}
	start ++;
	selectionSortRecusive(a, n, start);
}
void swapArr(int &a, int &b)
{
	int temp = a;
	a = b;
	b = temp;
}
void bubleSort(int a[], int n)
{
	for(int i = 0; i < n - 1; i ++)
	{
		for(int j = 0; j < n - i - 1; j++)
		{
			if(a[j + 1] < a[j])
			{
				swapArr(a[j], a[j + 1]);
			}
		}
	}
}

void bubleSortRecusive(int a[], int n, int &i)
{
	if(i == n - 1)
	{
		return;
	}
	for(int j = 0; j < n - i - 1; j++)
	{
		if(a[j + 1] < a[j])
		{
			swapArr(a[j], a[j + 1]);
		}
	}
	i++;
	bubleSortRecusive(a, n, i);
}

void insertionSort(int a[], int n)
{
	int key;
	int j;
	for(int i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;

		while(j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j --;
		}
		a[j + 1] = key;
	}
}

void insertionSortRecusive(int a[], int n, int i)
{
	if(i == n)
	{
		return;
	}
	int key;
	int j;
	key = a[i];
	j = i - 1;
	while(j >= 0 && a[j] > key)
	{
		a[j + 1] = a[j];
		j --;
	}
	a[j + 1] = key;
	i ++;
	insertionSortRecusive(a, n, i);
}
int partition (int a[], int low, int high)
{
	int i = low - 1;
	int pivot = a[high];
	for(int j = low; j < high; j++)
	{
		if(a[j] < pivot)
		{
			i++;
			swapArr(a[i],a[j]);
		}
	}
	swapArr(a[i + 1], a[high]);
	return i + 1;

}
void quickSort(int a[], int low, int high)
{
	
	if(low < high)
	{
		int pi = partition(a, low, high);
		quickSort(a, low, pi - 1);
		quickSort(a, pi + 1, high);
	}
}
int main()
{
	int a[19] = {1, 4, 2, 4, 2, 4, 1, 2, 4, 1, 2, 2, 2, 2, 4, 1, 4, 4, 4};
	int n = 19;
	int start = 0;
	int i = 1;

	//selectionSortRecusive(a, n, start);
	//bubleSortRecusive(a, n, i);
	//insertionSort(a, n);
	//insertionSortRecusive(a, n, i);
	quickSort(a, 0, n - 1);

	
}