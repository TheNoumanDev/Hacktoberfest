#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	long long int number, firstDigit, lastDigit, count, a, b, SwapNum;

	cout << "\nPlease Enter Any Number to find First and Last Digit =  ";
	while (!(cin >> number))
	{
		cout << "ERROR! Number is invalid.\nEnter a number again.";
		cin.clear();
		cin.ignore(123, '\n');
	}

	count = log10(number);
	firstDigit = number / ((long long int)round(pow(10, count)));

	lastDigit = number % 10;

	a = firstDigit * ((long long int)round(pow(10, count)));
	b = number % a;
	number = b / 10;

	SwapNum = lastDigit * ((long long int)round(pow(10, count))) + (number * 10 + firstDigit);

	cout << "\nThe First Digit in a Given Number    = " << firstDigit;
	cout << "\nThe Last Digit in a Given Number     = " << lastDigit;
	cout << "\nAfter Swapping First and Last Digit  = " << SwapNum;
	return 0;
}