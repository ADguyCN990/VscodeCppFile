#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
ll dp[MAXN*2000];//最接近i的数j(j<=i)，价值和空间都相等
ll a[MAXN];
int n;
ll V;
int minx=0x3f3f3f3f;int minid=-1;
int lowbit(int x){return x&(-x);}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        V+=a[i];
        if(lowbit(a[i])<minx)
        {
            minid=i;
            minx=lowbit(a[i]);
        }
    }
    if(V%2==1)
    {
        cout<<0<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=V/2;j>=a[i];j--)
        {
            dp[j]=max(dp[j],dp[j-a[i]]+a[i]);
        }
    }
    int f=0;
    if(dp[V/2]==V/2) f=1;
    if(f==1)
    {
        cout<<1<<endl<<minid<<endl;
    }
    else
    {
        cout<<0<<endl;
    }
    return 0;
}