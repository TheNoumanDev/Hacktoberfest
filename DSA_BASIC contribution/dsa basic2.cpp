#include<iostream>
using namespace std;

// pattern printing

int main(){
    int i,j,k,l;
    for (i=5;i>=1;i--){
        for (j=1;j<=i;j++){
            cout << j;
        }
        for(j=1;j<=(5-i);j++){
            cout << " ";
        }
        for (k=1;k<=(5-i);k++){
            cout << " ";
        }
        for (l=i;l>=1;l--){
            cout << l;
        }
        cout << endl;
    }
}
