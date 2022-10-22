#include<iostream>
using namespace std;
int main(){
    int number = 0;
    cout<<"Enter any number to check: ";
    cin>>number;
    if(number> 0){
        cout<<"\n"<<number<<" is positive";
    }
    else if(number == 0){
        cout<<"Given number is 0";
    }
    else{
        cout<<"Given number "<<number<<" is negative";
    }
    return 0;
}