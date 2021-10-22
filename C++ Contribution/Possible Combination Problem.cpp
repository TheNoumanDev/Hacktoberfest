#include <iostream>
using namespace std;
int main()
{
	int factorial = 1;
	int num1,num2,arrangements,i;
	cout<<"Enter Number of Guests: ";
	cin>>num1;
	cout<<"Enter Number of Chairs: ";
	cin>>num2;
	for (i = 1; i<=num1; i++)
	{
		factorial = factorial*i;
	}
	    arrangements = factorial/(num1-num2);
	    cout<<"Possible Arrangments : "<<arrangements;
	    return 0;
}
