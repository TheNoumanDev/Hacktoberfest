#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    int x = time(0);
    srand(x);
   const  int size = 10;
    int arr[size];
    cout << "The elemnets in the array are given as:" << endl;
    for (int i = 0; i < size; i++)
    {
        // arr[i] = (rand() % 20) + 1;
        cin>>arr[i];
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    int innerSize=size;
    cout << "The sorted array in the asscending order is given as as:" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < innerSize; j++)
        {
            int temp = arr[j + 1];
            if (arr[j] > arr[j + 1])
            {
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
        innerSize--;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // cout << sizeof(arr) / sizeof(int); // To check the size of the array that can be given in the array:

    return 0;
}