#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll n,k;//栅栏的高度为k
ll a[MAXN];//地面的海拔高度

void solve()
{
    cin>>n>>k;
    for(int i=1;i<=n;i++) cin>>a[i];
    ll h_min=a[1];//能达到的最低高度
    ll h_max=a[1];//能到达的最高高度
    for(int i=2;i<=n;i++)
    {
        h_min=max(h_min+1-k,a[i]);//往下低一个身位和地面高度取最大
        h_max=min(a[i],h_max)+k-1;//最低的合法高度加一个身位
        if(h_min>h_max)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    if(h_min>a[n]) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
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