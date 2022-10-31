#include<iostream>
using namespace std;


void array(int ar[]){
    for (int i=0;i<=5;i++){
        cout << "array is " << i << ar[i] <<endl;
    }
}
int main(){
    int one[10]= {3,6};
    cout << one[0];
    array(one);

}
////////////////////////////////////////////////////////
int max(int a[],int n){
    int max = INT32_MIN;
    for (int i =0;i<=n;i++){
        if(a[i]> max){
            max=a[i];
        }
    }
    return max;
}

int main(){
    int b[100]={4,60,2,8,9};

    int a = max(b,5);
    cout << "ans is :" <<a;
    
// }
