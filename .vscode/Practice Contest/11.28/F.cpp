#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
#define ll long long
#define mod 998244353
int n;
ll a[MAXN];
ll mn;

void work()
{
    int flag=1;
    mn=9999999999999;
    for(int i=1;i<=n;i++)
    {
        if(a[i]&1)
        {
            flag=0;
            mn=min(mn,a[i]);
        }
    }
    if(!flag)
    {
        cout<<(mn+1)/2<<endl;
        exit (0);
    }
    for(int i=1;i<=n;i++)
    {
        a[i]/=2;
    }
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    //如果存在奇数堆，方案数为最小奇数除以2，向上取整
    //如果全为偶数，就一直除以2，直到存在奇数，方案数为最小奇数除以2，向上取整
    while(1)
    work();
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}