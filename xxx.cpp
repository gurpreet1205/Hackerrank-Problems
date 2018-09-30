#include <bits/stdc++.h>
using namespace std;
// Complete the equal function below.
int equal(vector<int> arr) {
    int ans=0;
    multiset<int,std::greater<int> > s;
    for(int i=0;i<arr.size();i++)
        s.insert(arr[i]);
    multiset<int>:: iterator it;
    std::multiset<int>::reverse_iterator rit;
    while(true)
    {
        it=s.begin();
        int y=*it;
        rit=s.rbegin();
        int x=*it-*rit;
        //cout<<x<<" ";
        if(x>=5)
        {
            ans=ans+x/5;
            y=y-5*(x/5);
            x=x%5;
            if(x==2)
            {
                y=y-2;
                ans++;
            }
            if(x==1)
            {
                y=y-1;
                ans++;
            }
        }
        else
            break;
        s.erase(it);
        s.insert(y);
    }
    //for(it=s.begin();it!=s.end();it++)
       // cout<<*it<<" ";
    //cout<<"\n"<<ans<<"\n";
    int m=*rit,z=0,y=0;
    for(it=s.begin();it!=s.end();it++)
    {
        if(*it-m==4)
        {
            z=z+2;
            y++;
        }
        if(*it-m==3)
        {
            z=z+2;
            y=y+2;
        }
        if(*it-m==2)
        {
            z++;
            y=y+2;
        }
        if(*it-m==1)
        {
            z++;
            y++;
        }
        if(*it-m==0)
            y++;
    }
    //cout<<*it<<"\n";
    ans=ans+min(y,z);
    return ans;
}

int main()
{
    int t,n,x,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        vector<int> v;
        for(i=0;i<n;i++)
        {
            cin>>x;
            v.push_back(x);
        }
        cout<<equal(v)<<"\n";
    }
}
