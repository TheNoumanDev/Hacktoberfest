#include <iostream>
using namespace std;

int main() {

    int n;
    int nInReverse = 0;
    int Rem;

    cout << "Enter your number : ";
    cin >> n;

    while (n != 0) {
        Rem = n % 10;
        nInReverse = (nInReverse * 10) + Rem;
        n = n / 10;
    }

    cout << "Reversed number : " << nInReverse;

    return 0;
}