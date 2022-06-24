#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll n;
ll a[MAXN];
ll b[MAXN];//小
ll c[MAXN];//大
set <int> sb,sc;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        b[i]=0;c[i]=0;
    }
    for(int i=1;i<=n;i++) cin>>a[i];
    int now=1;
    for(int i=1;i<=n;i++)
    {
        sb.insert(i);sc.insert(i);
    }
    b[1]=a[1];c[1]=a[1];sb.erase(a[1]);sc.erase(a[1]);
    for(int i=2;i<=n;i++)
    {
        if(a[i]!=a[i-1]) 
        {
            b[i]=a[i];c[i]=a[i];
            sb.erase(a[i]);sc.erase(a[i]);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(b[i]==0)
        {
            int x=*sb.begin();
            b[i]=x;
            sb.erase(x);
        }
        if(c[i]==0)
        {
            auto it=sc.upper_bound(c[i-1]);
            it--;
            int x=*it;
            c[i]=x;
            sc.erase(x);
        }
    }
    for(int i=1;i<=n;i++) cout<<b[i]<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++) cout<<c[i]<<" ";
    cout<<endl;
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