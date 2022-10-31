// Kick Start Round-H Q.2

#include <iostream>
#include <string>
using namespace std;

int min_stroke(int l, string s)
{
    int r[2], y[2], b[2];
    for (int i = 0; i < 2; i++)
    {
        r[i] = y[i] = b[i] = 0;
    }
    for (int i = 0; i < l; i++)
    {
        char c = s[i];
        if (c == 'U')
        {
            r[1] = y[1] = b[1] = 0;
        }
        else if (c == 'R')
        {
            if (r[1] == 0)
            {
                r[0]++;
                r[1] = 1;
            }
            y[1] = b[1] = 0;
        }
        else if (c == 'Y')
        {
            if (y[1] == 0)
            {
                y[0]++;
                y[1] = 1;
            }
            r[1] = b[1] = 0;
        }
        else if (c == 'B')
        {
            if (b[1] == 0)
            {
                b[0]++;
                b[1] = 1;
            }
            r[1] = y[1] = 0;
        }
        else if (c == 'O')
        {
            if (r[1] == 0)
            {
                r[0]++;
                r[1] = 1;
            }
            if (y[1] == 0)
            {
                y[0]++;
                y[1] = 1;
            }
            b[1] = 0;
        }
        else if (c == 'P')
        {
            if (r[1] == 0)
            {
                r[0]++;
                r[1] = 1;
            }
            if (b[1] == 0)
            {
                b[0]++;
                b[1] = 1;
            }
            y[1] = 0;
        }
        else if (c == 'G')
        {
            if (y[1] == 0)
            {
                y[0]++;
                y[1] = 1;
            }
            if (b[1] == 0)
            {
                b[0]++;
                b[1] = 1;
            }
            r[1] = 0;
        }
        else if (c == 'A')
        {
            if (r[1] == 0)
            {
                r[0]++;
                r[1] = 1;
            }
            if (y[1] == 0)
            {
                y[0]++;
                y[1] = 1;
            }
            if (b[1] == 0)
            {
                b[0]++;
                b[1] = 1;
            }
        }
    }
    return (r[0] + y[0] + b[0]);
}
int main()
{
    int t, l, res;
    string s;
    cout << "Enter no. of test cases: ";
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        cin >> l;
        cin >> s;
        res = min_stroke(l, s);
        cout << "Case #" << i << ": " << res << "\n";
    }
}