#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    int size = 0;
    cin>>size;
    int temp=0;
    int *arr=new int[size];
    int min_index;
    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % 20) + 1;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    for (int i = 0; i < size - 1; i++)
    {
        
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] < arr[j])
            {
               temp = arr[i];
               arr[i] = arr[j];
               arr[j] = temp;
            }
        }
     }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
