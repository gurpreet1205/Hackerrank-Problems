#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int q,i,j,r,c;
	cin>>q;
	while(q--)
	{
		cin>>r>>c;
		if((r+c)%2==0)
			cout<<"black\n";
		else
			cout<<"red\n";
	}
	return 0;
}