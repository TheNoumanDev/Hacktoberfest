#include <iostream>
using namespace std; 

class Rectangle
{
public:
	Rectangle(); // default constructor
	Rectangle(int len, int wid);	// parametrized construtor
	void setLength(int len);	
	int getLength();
	void setWidth(int wid);
	int getWidth();
	int getArea();
	int getPerimeter();
	void draw();
	~Rectangle();
private:
	int length; 
	int width;
	const int SIDES;
};

Rectangle::~Rectangle()
{
	cout << "Destructor is called" << endl;
}

Rectangle::Rectangle():SIDES(4), length(0), width(0)
{
	cout << "Default constructor is called . . ." << endl;
}

Rectangle::Rectangle(int len, int wid = 0):SIDES(4)
{
	cout << "Parametrized constructor is called . . ." << endl;
	length = len; 
	width = wid;
}

void Rectangle::setLength(int len)
{
	length = len;
}

void Rectangle::setWidth(int wid)
{
	width = wid;
}

int Rectangle::getLength()
{
	return length; 
}

int Rectangle::getWidth()
{
	return width;
}

int Rectangle::getArea()
{
	return length * width; 

}

int Rectangle::getPerimeter()
{
	return 2 * (length + width);
}
int main()
{
//	Rectangle rect;	// default const. is called 
//	Rectangle rect2; // deafult 
//	Rectangle rect3(15, 35);	// calling parametrized const.
//	rect.setLength(10); 
//	rect.setWidth(30); 
//	cout << "Area of the Rectangle: " << rect.getArea() << endl;
//	cout << "length: " << rect.getLength() << endl;
//	cout << "width: " << rect.getWidth() << endl;
	return 0;
}