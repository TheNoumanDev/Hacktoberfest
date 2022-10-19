#include <iostream>
using namespace std;
int main()
{
    int start = 0, end, mid, x;
    cout << "ENter the size of the array: ";
    cin >> end;
    int *arr = new int[end];

    cout << "Enter the elements of the array one by one: ";
    for (int i = 0; i < end; i++)
    {
        cin >> arr[i];
    }

    int flag = 1;
    for (int i = 0; i < end - 1 && flag == 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            flag = 0;
        }
    }

    cout << "Enter the element of array you want to find: ";
    cin >> x;

    if (flag == 1)
    {
        while (start < end)
        {
            mid = (start + end) / 2;
            if (x > arr[mid])
            {
                start = mid + 1;
            }
            else
            {
                end = mid;
            }
        }

        if (x == arr[start])
        {
            cout << "Your no is present in index " << start << " of the array " << endl;
        }
        else
        {
            cout << "The no is not present in the array. . . " << endl;
        }
    }
    else
    {
        cout<<"Your array is not sorted. . . "<<endl;
        cout<<endl<<"Please enter a sorted array. . . "<<endl;
    }
}