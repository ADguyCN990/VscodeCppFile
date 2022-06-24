#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
ll n;
ll a[MAXN];
bool check(ll m)
{
    for(int i=2;i*i<=m;i++)
    {
        if(m%i==0) return true;//不是质数
    }
    return false;
}

void solve()
{
    cin>>n;
    ll sum=0;
    ll id=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        sum+=a[i];
        if(a[i]%2==1) id=i;
    }
    if(check(sum))
    {
        cout<<n<<endl;
        for(int i=1;i<=n;i++) cout<<i<<" ";
        cout<<endl;
    }
    else
    {
        cout<<n-1<<endl;
        for(int i=1;i<=n;i++)
        {
            if(i==id) continue;
            cout<<i<<" ";
        }
        cout<<endl;
    }
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