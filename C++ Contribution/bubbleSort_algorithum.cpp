#include <iostream>
using namespace std;
int main()
{
    int size,temp=0;
    cout<<"enter size of array"<<endl;
    cin>>size;
    //dynamically allocating array
    int *arr=new int[size];
    cout << "Enter the elemetns of the array:" << endl;
    for (int i = 0; i < size; i++)
    {
       cin>>arr[i];
    }
    cout<"Entered array is: "<<endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "The sorted array in the asscending order is given as as:" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size-1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp=arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        
    }
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // cout << sizeof(arr) / sizeof(int); // To check the size of the array that can be given in the array:

    return 0;
}
