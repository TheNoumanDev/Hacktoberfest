#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "enter a number : ";
	cin >> n;
	int max_count = 0;
	int result = 0;
	for (int i = 0; i <= 9; i++)
	{
		int count = 0;
		int d = n;
		int remainder = 0;
		while (d != 0)
		{
			remainder = d % 10;
			if (remainder == i)
				count++;
			d = d / 10;
		}
		if (count >= max_count)
		{
			max_count = count;
			result = i;
		}
	}
	cout << "most occuring number is : " << result;
	return 0;
}