#include<iostream>
using namespace std;
int main()
{
	//removing duplicate numbers
	int size;
	cin >> size;
	int* array = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> array[i];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; )
		{
			if (array[i] == array[j])
			{
				for (int k = j; k < size - 1; ++k)
				{
					array[k] = array[k + 1];
				}
				--size;

			}
			else 
				j++;
		}
	}
	cout << endl;
	for (int i = 0; i < size; i++)
		cout << array[i] << "   ";
	delete[] array;
	array = nullptr;
}