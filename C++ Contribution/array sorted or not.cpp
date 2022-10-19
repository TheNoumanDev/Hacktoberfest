//this program check wether sorted or not
#include<iostream>
using namespace std;
int main()
{
	int x;
	cout << "Enter size of array: ";
	cin >> x;
	while (x < 2)
	{
		cout << "Invalid enter again\n";
		cin >> x;
	}
	int* p = new int[x];
	cout << "Enter elment of array\n";
	for (int i = 0; i < x; i++)
	{
		cin >> p[i];
	}
	int k = 0;
	for (int i = 0, j=1; j < x ; i++,j++)
	{
		if (p[i] > p[j])
			k++;
	}
	if (k == x - 1)
		cout << "Array sorted in decending order\n";
	else if(k==0)
		cout << "Array sorted in ascending order\n";
	else
		cout << "Array is not sorted\n";
	delete[]p;
}