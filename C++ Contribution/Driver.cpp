#include "MyArray.h"
#include <iostream>
using namespace std;

int main()
{
	MyArray obj; 
	for (int i = 0; i < obj.getLength(); i++)
	{
		obj.setElement(i + 1);
	}

	
	obj.setElement(300);
	obj.setElement(500);
	for (int i = 0; i < obj.getIndex(); i++)
	{
		cout << obj.getElement(i) << endl;
	}
	
	//	int a = 1011;
	//	int b = 12; 

	//	cout << static_cast<double>(a) / b << endl;


}