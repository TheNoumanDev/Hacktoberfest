#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int m;
	    cin>>m;
	    int sum=0;
	    int count=0;
	    for(int i=1;sum+i<=m;i++)
	    {
	        sum=sum+i;
	        count++;
	    }
	    cout<<count<<endl;
	}
	return 0;
}
