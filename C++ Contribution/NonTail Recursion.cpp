#include<iostream>
using namespace std;

//Program to convert decimal number to binary using  "Non-Tail Recursion"

int Dec_to_bin(int n)
{
	if (n == 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{
		int	arr = n % 2;
		return ((arr + 10) * Dec_to_bin(n / 2));
	}

}

int main()
{
	cout << "Enter the Decimal Number you want to convert : ";
	int v;
	cin >> v;

cout<<	Dec_to_bin(v);
	return 0;
}
