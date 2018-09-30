#include<bits/stdc++.h>
using namespace std;
long long int b[100001][31];
int main()
{
	long long int n,i,j,c,x=0,y=0;
	cin>>n;
	long long int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		//a[i]=100000000;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<31;j++)
		{
			b[i][j]=a[i]%2;
			a[i]=a[i]/2;
		}
	}
	for(i=0;i<31;i++)
	{
		c=0;
		x=0;
		for(j=0;j<n;j++)
		{

			if(b[j][i]==1)
			{
				x=x+(c*(c+1))/2;
				c=0;
			}
			else
				c++;
		}
		x=x+(c*(c+1))/2;
		y=y+((n*(n+1))/2-x)*pow(2,i);
	}
	cout<<y<<"\n";
	return 0;
}