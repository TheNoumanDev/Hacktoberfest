// C++ program to Count Inversions in an Array


#include <bits/stdc++.h>
using namespace std;

int getInv_Count(int arr[], int n)
{
    int inversion_count = 0;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] > arr[j])
                inversion_count++;

    return inversion_count;
}

 
int main()
{
    int arr[] = { 1, 20, 6, 4, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << " Number of inversions are "
         << getInv_Count(arr, n);
    return 0;
}