#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{
    int x = time(0);
    srand(x);
    const int size = 10;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = (rand() % 10) + 1;
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    for (int i = 1; i < size; i++)
    {
        int temp;
        if (arr[i] < arr[i - 1])
        {
            temp = arr[i];
            int j = i;
            do
            {
                arr[j] = arr[j - 1];
                j--;
            } while (j > 0 && arr[j - 1] > temp);
            arr[j] = temp;
        }
    }
    cout << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}