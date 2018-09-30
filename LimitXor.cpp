#include<bits/stdc++.h>
using namespace std;
long long int modifiedBinarySearch(long long int *a,long long int n,long long int x)
{
    long long int low=0,high=n-1,mid;
    if(a[0]>=x)
        return 0;
    if(a[n-1]<x)
        return n;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]>=x)
        {
            if(a[mid-1]<x)
                return mid;
            else
                high=mid-1;
        }
        else
        {
            low=mid+1;
        }
    }
    return;
}

int main()
{
    long long int n,k,i,j,x,y,z,p,q,r,l,u,ans=0;
    cin>>n>>k;
    long long int a[n],b[n],c[31],d[31];
    for(i=0;i<n;i++)
        cin>>a[i];
    b[0]=a[0];
    for(i=1;i<n;i++)
        b[i]=b[i-1]^a[i];
    sort(b,b+n);
    for(i=0;i<n-1;i++)
    {
        l=0,u=0;
        x=b[i]^k;
        y=k,j=0;
        while(y>0)
        {
            c[j++]=y%2;
            y=y/2;
        }
        while(j<31)
            c[j++]=0;
        j=0;
        while(x>0)
        {
            d[j++]=x%2;
            x=x/2;
        }
        while(j<31)
            d[j++]=0;
        vector< pair<long long int,long long int> > v;
        q=0;
        for(p=30;p>=0;p--)
        {
            if(c[p]==1)
            {
                if(d[p]==1)
                    z=q*2;
                else
                    z=q*2+1;
                l=z*pow(2,p);
                u=z*pow(2,p)+pow(2,p)-1;
                v.push_back(make_pair(l,u));
            }
            q=q*2+d[p];
        }
        l=v.size();
        for(j=0;j<l;j++)
        {
            x=modifiedBinarySearch(b+i+1,n-i-1,v[j].first);
            y=modifiedBinarySearch(b+i+1,n-i-1,v[j].second+1);
            ans=ans+y-x;
        }
    }
    for(i=0;i<n;i++)
    {
        if(b[i]<k)
            ans++;
    }
    cout<<ans<<"\n";
    return 0;
}