#include<iostream>
using namespace std;
int main()
{
	int row;
	cout << "Enter number of rows: ";
	cin >> row;

	for (int i = 1; i <= row; i++)
	{
		int j = 1;
		while (j <= row - i)
		{
			cout << " ";
			j++;
		}
		for (int k = 0; k <= (i * 2) - 2; k++)
			cout << "*";
		cout << endl;
	}
	return 0;
}