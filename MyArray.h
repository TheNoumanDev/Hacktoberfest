#pragma once
class MyArray
{
	int size; 
	int index; 
	int* arr;
	void resize();
public: 
	MyArray(int s = 10);
	~MyArray();
	int getLength() const;
	int getIndex() const;
	void setElement(int val); 
	int getElement(int i) const; 
};

