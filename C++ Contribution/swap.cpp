#include <iostream>
using namespace std;
int main()
{
	const int SIZE=5;
	
	int array[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		cout << "ENTER THE ELEMENET:";
		cin >> array[i];
	}
	cout << "Before Swap:\n";
	for (int i = 0; i < SIZE; i++)
	{
		cout << array[i] << "\t";
	}
	cout << "\n";
	int temp;
	temp = array[0];
	array[0] = array[SIZE - 1];
	array[SIZE - 1] = temp;
	for (int i = 0; i < SIZE; i++)
	{
		cout << array[i] << "\t";
	}
	cout << "\n";

	return 0;
}
