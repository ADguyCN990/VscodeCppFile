#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll n;
ll a[MAXN];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n%2==0)
    {
        cout<<"YES"<<endl;
        return;
    }
    int f=0;//非递增，两个数相同，三个数递减
    for(int i=1;i<n;i++)
    {
        if(a[i]>=a[i+1]) f=1;
    }
    if(f) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
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