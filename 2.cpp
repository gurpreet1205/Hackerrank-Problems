#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long int n,i,j,flag=0;
	cin>>n;
	long long int a[n];
	string s;
	for(i=0;i<n;i++)
	{
		cin>>s;
		if(s[0]=='b')
			a[i]=1;
		else if(s[0]=='r')
			a[i]=2;
		else
			a[i]=0;
	}
	for(i=0;i<n;i++)
	{
		if(a[i]!=0)
			break;
	}
	if(i==n)
		cout<<"yes\n";
	else
	{
		for(j=i+1;j<n;j++)
		{
			if(a[j]==a[j-1])
			{
				flag=1;
				break;
			}
			if(a[j]==0)
				a[j]=a[j-1]==1?2:1;
		}
		if(flag==1)
			cout<<"no\n";
		else
			cout<<"yes\n";
	}
	return 0;
}