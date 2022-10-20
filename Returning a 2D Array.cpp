//Returning a 2_Dimensional (dynamically allocated array) from a function
#include <iostream>
using namespace std;


void getData(int** arr, const int& rows, const int& cols)
{
	cout << "Enter elements of array\n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cin >> arr[i][j];
		}
	}
}
void displayData(int** arr, const int& rows, const int& cols)
{
	cout << "Displaying Elements of Array\n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int** twice(int** arr, const int& rows, const int& cols)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] *= 2;
		}
	}
	return arr;
}
int main()
{
	int rows, cols;
	int** ptr;
	cout << "Number of Rows : ";
	cin >> rows;
	cout << "Number of columns : ";
	cin >> cols;
	int** arr = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols];
	}
	getData(arr, rows, cols);
	cout << "\n\t--------------------------------------------------\n";

	displayData(arr, rows, cols);
	cout << "\n\t--------------------------------------------------\n";

	ptr = twice(arr, rows, cols);
	cout << "Displaying twice the Elements of Original Array\n";
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << ptr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "\n\t--------------------------------------------------\n";

	for (int i = 0; i < rows; i++)
	{
		delete arr[i];
	}
	delete[]arr;

	return 0;
}