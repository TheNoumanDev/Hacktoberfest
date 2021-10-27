#include<iostream>
using namespace std;

//Progeam to find minimum and maximum numbers in an array using  "Indirect Recursion"
 
int maximum(int n, int min, int max);
int minimum(int n, int min, int max)
{
	if (n < min)
	{
		min = n;

		maximum(n, min, max);
	}
	return min;

}
int maximum(int n, int min, int max)
{
	if (n > max)
	{
		max = n;

		minimum(n, min, max);
	}
	return max;
}
int main()
{
	int min=1, max=5;

	int arr[3] = { 1,2,3 };
	for (int i = 0; i < 3; i++)
	{
	 
		cout << minimum(arr[i],min , max);
	}
	cout << "min: " << min << endl;
	cout << "max: " << max << endl;

	return 0;
}
 
