// it will print the each digit of any integer in reverse order
#include<iostream>
using namespace std;
int main(){
    int number = 0; 
    cout << "Enter any integer except single digit: ";
    cin >> number;
    while(number >0){
        int out = number % 10;
        cout<<out<<"\n";
        number = number / 10;
    }
    return 0;
}