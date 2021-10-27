 #include<iostream>
using namespace std;

//Program to write backward counting using  "Tail Recursion"

int counting(int n)
{
 
if (n == 1)
	{
		return 1;
	}
	else
	{
		 cout<<n<<endl;
		return (counting(n-1));
	}

}

int main()
{
	cout << "How many Numbers you want to print : ";
	int v;
	cin >> v;

cout<<counting(v);
	return 0;
}
