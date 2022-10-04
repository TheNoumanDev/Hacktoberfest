#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    const int size = 10;
    int x = time(0);
    srand(x);
    int arr[size] = {};
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
        min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min_index])
            {
                min_index = j;
            }
        }
        int temp;
        temp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = temp;
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}