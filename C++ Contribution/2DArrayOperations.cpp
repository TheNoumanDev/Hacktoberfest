#include<iostream>
using namespace std;
#define r 3
#define c 3
int getTotal(int [][c]);
float getAverage(int [][c]);
int getRowTotal(int [][c], int);
int getColumnTotal(int [][c], int);
int HighestInRow(int [][c], int);
int LowestInRow(int [][c], int);
int main()
{
	int rn, cn, h, l;
	int ar[r][c];
	cout << "Enter values in array:" << endl;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> ar[i][j];
		}
	}
	cout << "Enter the row number whose sum you want to find:";
	cin >> rn;
	cout << "Enter the column number whose sum you want to find:";
	cin >> cn;
	cout << "Enter the row number whose highest element you want to find:";
	cin >> h;
	cout << "Enter the row number whose lowest element you want to find:";
	cin >> l;
	cout << "Sum of values in array:" << " " << getTotal(ar) << endl;
	cout << "Average of values in array is:" << " " << getAverage(ar) << endl;
	cout << "Sum of values of in row number" << " " << r << " is " << getRowTotal(ar, rn) << endl;
	cout << "Sum of values of in column number" << " " << c << " is " << getColumnTotal(ar, cn) << endl;
	cout << "Highest value in row number " << h << " is " << HighestInRow(ar, h) << endl;
	cout << "Lowest value in row number " << l << " is " << LowestInRow(ar, l) << endl;
}
int getTotal(int ar[][c])
{
	int s = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			s += ar[i][j];
		}
	}
	return s;
}
float getAverage(int ar[][c])
{
	float s = 0.0;
	float avg;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			s += ar[i][j];
		}
	}
	avg = s / (r*c);
	return avg;
}
int getRowTotal(int ar[][c], int a)
{
	int sum = 0;
	for (int j = 0; j < c; j++)
	{
		sum = sum + ar[a][c];
	}
	return sum;
}
int getColumnTotal(int ar[][c], int b)
{
	int sum = 0;
	for (int i = 0; i < r; i++)
	{
		sum = sum + ar[i][b];
	}
	return sum;
}
int HighestInRow(int ar[][c], int i)
{
	int high = ar[i][0];
	for (int j = 1; j < c; j++)
	{
		if (ar[i][j] > high)
			high = ar[c][j];
	}
	return high;
}
int LowestInRow(int ar[][c], int d)
{
	int low = ar[d][0];
	for (int j = 1; j < c; j++)
	{
		if (ar[d][j] < low)
			low = ar[d][j];
	}
	return low;
}

