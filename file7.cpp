#include <iostream>
#include <cstring>
using namespace std;

int main()
{

	char str[50];


	cout << "Enter string : ";
	cin >> str;
	int l = strlen(str);
	for (int i = 0; i < l; i++)
	{
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'
			|| str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U')
		{
			for (int j = i; j < l; j++)
			{
				str[j] = str[j + 1];
			}
			i--;
			l--;
		}
	}

	cout << "After removing Vowels: " << str;

	return 0;
}