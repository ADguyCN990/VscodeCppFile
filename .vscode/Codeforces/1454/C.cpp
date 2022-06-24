#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll n;ll a[MAXN];
ll pos[MAXN];//记录上一次出现的位置
ll ans[MAXN];//划分区间的个数
ll cnt[MAXN];
void solve()
{
    cin>>n;
    ll res=0x3f3f3f3f;
    set <int> s;
    for(int i=1;i<=n;i++)
    {
        pos[i]=-1;
        ans[i]=1;
        cnt[i]=0;
    }
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        cnt[a[i]]++;
        s.insert(a[i]);
    }
    if(s.size()==1)
    {
        cout<<0<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {       
        if(pos[a[i]]!=i-1)
        {
            ans[a[i]]++;
        }
        pos[a[i]]=i;       
    }
    for(auto x:s)
    {
        if(x==a[1]&&x==a[n]) res=min(res,ans[x]-2);
        else if(x==a[1]&&x!=a[n]||x==a[n]&&x!=a[1]) res=min(res,ans[x]-1);
        else  res=min(res,ans[x]);
        //cout<<"x: "<<x<<" ans: "<<ans[x]<<endl;
    }
    cout<<res<<endl;
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