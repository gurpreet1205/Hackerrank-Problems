#include<bits/stdc++.h>
using namespace std;
long long int a[100001];
int main()
{
	long long int n,c1,c2,i,j,k,x;
	cin>>n>>c1>>c2;
	if(n==1)
		cout<<0<<" "<<1<<"\n";
	else
	{
		j=0;
		for(i=1;i*i<=n;i++)
		{
			if(n%i==0)
			{
				a[j++]=i;
				if(i*i!=n)
					a[j++]=n/i;
			}
		}
		sort(a,a+j);
		long long int cost[j],ways[j];
		for(i=0;i<j;i++)
		{
			for(k=i;k<j;k++)
			{
				if(i==0)
				{
					cost[k]=c2*(a[k]/a[i]-1)+c1;
					ways[k]=1;
				}
				else
				{
					if(a[k]%a[i]==0)
					{
						x=cost[i]+c1+c2*(a[k]/a[i]-1);
						if(x==cost[k])
						{
							ways[k]=ways[k]+ways[i];
						}
						else if(x<cost[k])
						{
							ways[k]=ways[i];
							cost[k]=x;
						}
					}
				}
			}
		}
		cout<<cost[j-1]<<" "<<ways[j-1]<<"\n";
	}
	return 0;
}