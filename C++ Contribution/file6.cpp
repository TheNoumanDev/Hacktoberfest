#include <iostream>
#include<string>
using namespace std;

int main() {
	// your code goes here
	int t;
	cin >> t;
	while (t--)
	{
		string m;
		cin >> m;
		int u = 0;
		string array[100];
		for (int i = 0; i < m.size() - 1; i++)
		{
			array[u] = m.substr(i, 2);
			// cout<<array[u]<<endl;
			u++;
		}

		int f = u;
		for (int i = 0; i < u; i++)
		{
			for (int j = 0; j < u; j++)
			{
				if (i != j)
				{
					if (array[i] == array[j])
					{
						u--;
					}
				}
			}
		}
		cout << u << endl;
	}
	return 0;
}