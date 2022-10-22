// concatenating two strings.
#include<iostream>
using namespace std;
int main(){
    string s1 = "";
    string s2 = "";
    cout<< "Enter the first string to concatenate: ";
    getline(cin, s1);
    cout<<"\n Enter the second string to concatenate: ";
    getline(cin, s2);
    cout<<"Concatenated strings are: "<<s1+s2;
    return 0;
}