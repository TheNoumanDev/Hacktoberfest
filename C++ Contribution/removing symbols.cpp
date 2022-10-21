#include <iostream>
using namespace std;

int main() {
    string l;
    string ans = "";

    cout << "Enter text: ";
    getline(cin, l);

    for (int i = 0; i < l.size(); ++i) {
        if ((l[i] >= 'a' && l[i] <= 'z') || (l[i] >= 'A' && l[i] <= 'Z')) {
            ans = ans + l[i];
        }
    }
    l = ans;
    cout << "Output String: " << l;
    return 0;
}