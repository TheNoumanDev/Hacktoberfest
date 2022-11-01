#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	ofstream out;
	out.open("file4.txt");	
	out<<"KIIT University";
	
	out.close();
	
	
	ifstream in;
	in.open("file4.txt");
	char c=' ',s[20];
	in.get(s,20);
	cout<<"Content of file: "<<s<<endl;
	int t=0;
	in.seekg(-1,ios::end);
	cout<<"output: ";
	while(in)
	{
		in.get(c);
		if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
		{
			if((t%2==0))
				cout<<c;
			t++;
		}
		in.seekg(-2,ios::cur);
	}
	cout<<endl;
}
