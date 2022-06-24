#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
int a[MAXN];int b[MAXN];
ll n,m;
ll suma[MAXN];ll sumb[MAXN];
void solve()
{
    cin>>n;for(int i=1;i<=n;i++) cin>>a[i];//红
    cin>>m;for(int i=1;i<=m;i++) cin>>b[i];//蓝
    suma[1]=a[1];sumb[1]=b[1];
    for(int i=2;i<=n;i++) suma[i]=suma[i-1]+a[i];//红的前缀和
    for(int i=2;i<=m;i++) sumb[i]=sumb[i-1]+b[i];//蓝的前缀和
    int pa=1;int pb=1;
    ll mx=-0x7fffffff;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            mx=max(mx,suma[i]+sumb[j]);
        }
    }
    cout<<mx<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}