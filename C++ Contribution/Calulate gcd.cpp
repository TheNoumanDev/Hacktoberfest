#include <iostream>
using namespace std;

int calculate_gcd(int, int);

int main()
{
    int nomi, denomi;
    cout << "Enter the nominator of fraction: ";
    cin >> nomi;
    cout << "Enter the denominator of fraction: ";
    cin >> denomi;

    int gcd = calculate_gcd(nomi, denomi);

    cout<<"The gcd of your fraction is: "<<gcd;
}

int calculate_gcd(int nomi, int denomi)
{
    int gcd;
    if (nomi > denomi)
    {
        int temp = nomi;
        nomi = denomi;
        denomi = temp;
    }

    for (int i = 1; i <= nomi; i++)
    {
        if (nomi % i == 0 && denomi % i == 0)
        {
            gcd = i;
        }
    }

    return gcd;
}
