// Calculatior(plus-minus-multiply-divide).cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include<iostream>
#include<stdio.h >
#include <stack>
#include <string>

using namespace std;
//creating function to display / select operator
void selectOp() {

	cout << "\n Please Enter a Operator (+,-,*,/) : ";
}
void selectNum(int n) {

	cout << "\n Please Enter a Single Number "<<n+1<<" : ";
}
int main()
{
//input Expression
	stack<int> nums;
	stack<char> ops;
	string exp;
	// precedence
	int d = 1;
	int m = 2;
	int a = 3;
	int s = 4;
	cout << " Enter Expression : ";
	cin >> exp;
	

	int i = 0;
	int check = 0;
	int pcheck = 0;
	//Moving through Expression
	while (exp[i] != '\0') {

	
		if (isdigit(exp[i])) {
			nums.push(exp[i]-'0');
		}
		else {
			if (ops.empty()) {
				switch (exp[i]) {
				case('/'): {
					check = d;
					break;
				}
				case('*'): {
					check = m;
					break;
				}
				case('+'): {
					check = a;
					break;
				}
				case('-'): {
					check = s;
					break;
				}
				}
				ops.push(exp[i]);
			}
			else {
				switch (exp[i]) {
				case('/'): {
					pcheck = d;
					break;
				}
				case('*'): {
					pcheck = m;
					break;
				}
				case('+'): {
					pcheck = a;
					break;
				}
				case('-'): {
					pcheck = s;
					break;
				}
				}
				if (check<=pcheck) {
					
					while (!ops.empty()) {
						int a;
						int b;
						switch (ops.top()) {
							
						case('+'): {
							a = nums.top(); nums.pop();
							b = nums.top(); nums.pop();
							nums.push(a + b);
							break;
						}
						case('-'): {
							a = nums.top(); nums.pop();
							b = nums.top(); nums.pop();
							nums.push( b - a);
							break;
						}
						case('*'): {
							a = nums.top(); nums.pop();
							b = nums.top(); nums.pop();
							nums.push(a * b);
							
							break;
						}
						case('/'): {
							a = nums.top(); nums.pop();
							b = nums.top(); nums.pop();
							nums.push(b / a);
							break;
						}
						}
						ops.pop();
					}
					ops.push(exp[i]);
				}
				else {
					ops.push(exp[i]);
				}
			}

			
			
		}
		i++;
	}

	//empty array;
	while (!ops.empty()) {
		int a;
		int b;
		switch (ops.top()) {

		case('+'): {
			a = nums.top(); nums.pop();
			b = nums.top(); nums.pop();
			nums.push(a + b);
			break;
		}
		case('-'): {
			a = nums.top(); nums.pop();
			b = nums.top(); nums.pop();
			nums.push(b - a);
			break;
		}
		case('*'): {
			a = nums.top(); nums.pop();
			b = nums.top(); nums.pop();
			nums.push(a * b);
			break;
		}
		case('/'): {
			a = nums.top(); nums.pop();
			b = nums.top(); nums.pop();
			nums.push(b / a);
			break;
		}
		}
		ops.pop();
	}

	cout << "Answer :" << nums.top();
		


		
		
		
	}
	
	
	
	
 


