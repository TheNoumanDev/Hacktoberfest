#include "MyArray.h"
#include <iostream>
using namespace std; 

MyArray::MyArray(int s)
{
	size = s; 
	index = 0; 
	arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = 0;
}

MyArray::~MyArray()
{
	if (arr)
	{
		delete[]arr; 
		arr = nullptr;
	}
}
void MyArray::setElement(int value)
{
	if (index >= size)
	{
		resize();
	}
	arr[index] = value;
	index++;
}
int MyArray::getIndex() const
{
	return index;
}
void MyArray::resize()
{
	int* temp = new int[size * 2];
	for (int i = 0; i < size; i++)
		temp[i] = arr[i];
	size = size * 2; 
	delete[]arr; 
	arr = temp;
}

int MyArray::getElement(int i) const
{
	if (i > -1 && i < size)
		return arr[i];
	else
	{
		cout << "Index out of bound" << endl;
		return -1;
	}
}

int MyArray::getLength() const
{
	return size; 
}