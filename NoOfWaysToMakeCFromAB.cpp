#include<bits/stdc++.h>
using namespace std;
int dp[301][301][301][3];
int a,b,c;
string A,B,C;
int p=1000000007;
int CfromAorBorBoth(int i,int j,int k,int status)
{
    if(a-i+b-j<c-k)
        return 0;
    if(dp[i][j][k][status]!=-1)
        return dp[i][j][k][status];
    int sum=0;
    if(k==c)
        return 1;
    if(i<a&&status!=2)
    {
        //cout<<i<<" "<<k<<" "<<A[i]<<" "<<C[k]<<"\n";
        if(A[i]==C[k])
            sum=(sum+CfromAorBorBoth(i+1,j,k+1,0))%p;
        sum=(sum+CfromAorBorBoth(i+1,j,k,1))%p;
    }
    if(j<b&&status!=1)
    {
        //cout<<j<<" "<<k<<" "<<B[j]<<" "<<C[k]<<"\n";
        if(B[j]==C[k])
            sum=(sum+CfromAorBorBoth(i,j+1,k+1,0))%p;
        sum=(sum+CfromAorBorBoth(i,j+1,k,2))%p;
    }
    dp[i][j][k][status]=sum;
    return sum;
}
int dp1[301][301];
int CfromAonly(int i,int k)
{
    int sum=0;
    if(a-i<c-k)
        return 0;
    if(dp1[i][k]!=-1)
        return dp1[i][k];
    if(k==c)
        return 1;
    if(i<a)
    {
        if(A[i]==C[k])
            sum=(sum+CfromAonly(i+1,k+1))%p;
        sum=(sum+CfromAonly(i+1,k))%p;
    }
    dp1[i][k]=sum;
    return sum;
}
int dp2[301][301];
int CfromBonly(int j,int k)
{
    int sum=0;
    if(b-j<c-k)
        return 0;
    if(dp2[j][k]!=-1)
        return dp2[j][k];
    if(k==c)
        return 1;
    if(j<b)
    {
        if(B[j]==C[k])
            sum=(sum+CfromBonly(j+1,k+1))%p;
        sum=(sum+CfromBonly(j+1,k))%p;
    }
    dp2[j][k]=sum;
    return sum;
}
int main()
{
    int x,y,z,i,j,k,pp;
    ios_base :: sync_with_stdio(false);
    cin.tie(0);
    cin>>A>>B>>C;
    a=A.length(),b=B.length(),c=C.length();
    for(i=0;i<301;i++)
    {
        for(j=0;j<301;j++)
        {
            for(k=0;k<301;k++)
            {
                for(pp=0;pp<3;pp++)
                    dp[i][j][k][pp]=-1;
            }
        }
    }
    for(i=0;i<301;i++)
    {
        for(j=0;j<301;j++)
        {
            dp1[i][j]=-1;
            dp2[i][j]=-1;
        }
    }
    x=CfromAorBorBoth(0,0,0,0);
    y=CfromAonly(0,0);
    z=CfromBonly(0,0);
    //cout<<x<<" "<<y<<" "<<z<<"\n";
    y=(y+z)%p;
    x=(x-y+p)%p;
    cout<<x<<"\n";
    return 0;
}