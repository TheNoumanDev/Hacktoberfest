//Name: Rehmat E Mustafa

//Username: Rehmat-E-Mustafa

//Favorite Language: c++

#include<iostream>
#include<string>

using namespace std;
int counter = 0;

//****************struct of node type**********************
struct node
{
	char data;
	node* next;
};

//________________________________________________________
//__________________Class Stack___________________________
class stack
{
private:
	//data member top
	node* top;
public:

	//***********Default contructor********************

	stack()
	{
		top = NULL;
	}

	//***********Push function to add string **********

	void Push(char value)
	{
		//creating a temporary node

		node* temp = new node;

		//giving it value

		temp->data = value;
		temp->next = NULL;

		//for the first node

		if (top == NULL)
		{
			top = temp;
			top->next = NULL;
		}

		//inserting node at begning for LIFO

		else
		{

			//adding temp before top

			temp->next = top;

			//moving top to the left most node ie the top

			top = temp;
		}
	}

	//*************POP function to remove top**********

	void Pop()
	{
		node* temp = new node;

		//checking if list is empty

		if (top == NULL)
		{
			cout << "\nStack is empty";
		}

		//decrementing top and unlinking the previous top

		else
		{
			temp = top;
			top = top->next;
		}
	}

	//********************validate input************************

	bool validateInput(char value)
	{
		if (value == '[' || value == ']' || value == '{' || value == '}' || value == '(' || value == ')')
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//checking if open brackets are input

	bool openbrackets(char value)
	{
		if (value == '[' || value == '{' || value == '(')
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void closingbrackets(char value)
	{
		//checking if pairs formed 

		if (top == NULL)
		{

		}
		else if (value == ']' && top->data == '[')
		{
			Pop();
		}
		else if (value == '}' && top->data == '{')
		{
			Pop();
		}
		else if (value == ')' && top->data == '(')
		{
			Pop();
		}
		else
		{

		}
	}

	//********************checking empty stack************************

	bool isEmpty()
	{
		if (top == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//********************MENU************************

	void menu()
	{
		char value;
		cout << "\nEnter the bracket : ";
		for (int i = 0; i < 6; i++)
		{
			cin >> value;

			//validating input

			bool istrue = validateInput(value);
			if (istrue == true)

			{
				//only adding opening brackets in stack

				istrue = openbrackets(value);
				if (istrue == true)
				{
					this->Push(value);
					counter++;
				}

				//checking if the parenthesis are balanced

				else
				{
					this->closingbrackets(value);
				}
			}
			else
			{
				cout << "\nInvalid Input";
			}
		}
	}
};

//***************DRIVER PROGRAMM***********
int main()
{
	//class object

	stack s;

	//calling menu function

	s.menu();
	bool a = s.isEmpty();
	if (counter == 0)
	{
		cout << "\nPrenthesis are not balanced";
	}
	else
	{
		if (a == true)
		{
			cout << "\nPrenthesis are balanced";
		}
		else
		{
			cout << "\nPrenthesis are not balanced";
		}
	}
	return 0;
}
//*******************************************************************************************************************************************************
//_______________________________________________________ANOTHER APPROACH_______________________________________________________________________________
#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool BalancedParanthesis(string exp)
{
	stack<char>S;
	for (int i = 0; i < exp.length(); i++)
	{
		if (exp[i]== '(' || exp[i] == '{' || exp[i] == '[')
		{
			S.push(exp[i]);
		}
		else if (exp[i] == ')'  || exp[i] == ']'  || exp[i] == '}' )
		{
			if (S.empty())
			{
				return false;
			}
			S.pop();
		}
	}
	if (S.empty())
	{
		return true;
	}
	return false;
}
int main()
{
	string exp;
	cout << "\nEnter the expression: ";
	getline(cin,exp);
	bool check=BalancedParanthesis(exp);
	if (check == true)
	{
		cout << exp << " is balanced";
	}
	else
	{
		cout << exp << " is not balanced";
	}
	return 0;
}