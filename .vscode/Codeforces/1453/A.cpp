#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
ll n,m;
//先是下面的编号（水平方向），再是左边的编号（竖直方向）
ll a[MAXN];
ll b[MAXN];
int cnt[MAXN];
void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=m;i++) cin>>b[i];
    for(int i=1;i<=100;i++) cnt[i]=0;
    for(int i=1;i<=n;i++) cnt[a[i]]++;
    int ans=0;
    for(int i=1;i<=m;i++){
        if(cnt[b[i]]>0)
            ans++;
    }
    cout<<ans<<endl;
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