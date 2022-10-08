#include<iostream>
using namespace std;
int main(){
	int a;
	cout<<"1st Number";
	cin>>a;
	int b;
	cout<<"2nd Number";
	cin>>b;
	int c;
	while(b!=0){
		c=b;
		b=a%b;
		a=c;
	}
	cout<<a;
	return 0;
}
