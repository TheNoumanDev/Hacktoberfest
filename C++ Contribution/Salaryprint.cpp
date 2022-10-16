#include <iostream>
using namespace std;
int main(){
	char a,b,c,d,x;
	a='s';
	b='S';
	c='j';
	d='J';
	cout<<"Enter your status"<<endl;
	cout<<"Enter 's' or'S' for senior person salary"<<endl;
	cout<<"Enter 'j' or 'J' for junior person salary"<<endl; 
    cin>>x;
	if(x==a||x==b){
		cout<<"Your salary is Rs.400";
	}
	else{
		if(x==c||x==d){
			cout<<"Your salary is Rs.275";
		}
		else{
			cout<<"Error";
		}
	}
	return 0;
}
