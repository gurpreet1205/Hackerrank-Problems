#include <bits/stdc++.h>
using namespace std;
long long int a[18],n,ans=0,ans1=0;
void solve(long long int x,long long int y,long long int z,long long int in)
{
    if(x==0&&y==0&&z==0&&in==n)
    {
        ans++;
        return;
    }
    if(in>=n)
        return;
    solve(x-a[in],y,z,in+1);
    solve(x,y-a[in],z,in+1);
    solve(x,y,z-a[in],in+1);
}

void solve(long long int x,long long int y,long long int in)
{
    if(x==0&&y==0&&in==n)
    {
        ans1++;
        return;
    }
    if(in>=n)
        return;
    solve(x-a[in],y,in+1);
    solve(x,y-a[in],in+1);
}

int main()
{
    long long int i,j,s=0;
    cin>>n;
    for(i=0;i<n;i++)
        cin>>a[i];
    for(i=0;i<n;i++)
        s=s+a[i];
    if(s%3!=0)
        cout<<"0\n";
    else
    {
        solve(s/3,s/3,s/3,0);
        if(s==0)
        {
            solve(s/2,s/2,0);
            ans=ans-3*(ans1-2)-3;
        }
        cout<<ans<<"\n";
    }
    return 0;
}