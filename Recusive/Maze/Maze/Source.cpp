#include <iostream>
#include <math.h>
using namespace std;
// ham nay dung de in ma tran cho cac so thang cot
//neu khong co ham nay thi ma tran se bi nhu sau :
// 1 2 3 4 5
// 16 17 18 19 6
// co ham nay 
// 1  2  3  4  5
// 16 17 18 19 6
void coutAv(int n, int space)
{
    int numberDigit = (int)log10(n);
    int first = true;
    for(int i = 0; i < space; i++)
    {
        if( i > numberDigit)
        {
            cout << " ";
        }
        else
        {
            if(true == first)
            {
                cout << n;
                first = false;
            }
                
        }
    }
}
//Ham de qui tao ma tran
//Giai thuat ve tu ngoai vao trong
void maze(int low, int high, int **a, int& k)
{
    if(low == high) // neu ma tran la so le thi se co luc low + 1 = high - 1 va chi con 1 phan tu o giua
    {
       a[low][low] = k;
    }
    else if(low > high)
    {
        return;
    }
    else
    {
        for(int i = low; i < high; i++ )
        {
            a[low][i] = k++;// tao hang ngang o tren;
        }
        for(int i = low; i < high; i++ )
        {
            a[i][high] = k++;// tao hang doc ben phai
        }
        for(int i = high; i > low; i-- )
        {
            a[high][i] = k++;// tao hang ngang phia duoi 
        }
        for(int i = high; i > low; i-- )
        {
            a[i][low] = k++;// tao hang doc ben trai
        }
        maze(low + 1, high - 1, a, k); // thu nho ma tran ve tiep hang ben trong
    }
}
int main()
{
   int n = 7;
   int **a = (int **)(malloc(sizeof(int *) * n)); // tao con tro cap 2 tuong duong voi mang 2 chieu
   for(int i = 0; i< n; i++)
   {
       a[i] = (int *)malloc(sizeof(int ) * n);
   }
   int k = 1;
   maze(0, n - 1, a, k); // goi ham tao me cung
   // in ra ma tran sau khi tao
   for(int i = 0; i< n; i++)
   {
       for(int j = 0; j< n; j++)
       {
           coutAv(a[i][j], 4);
       }
       cout << endl;
   }
   system("pause");
   return 0;
}