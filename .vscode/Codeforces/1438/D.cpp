#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll n;
ll a[MAXN];

void solve()
{
    cin>>n;
    ll x=0;//异或和
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        x^=a[i];
    }
    if(x!=0&&n%2==0)
    {
        cout<<"NO"<<endl;
        return;
    }
    if(n%2==0) n--;
    cout<<"YES"<<endl<<n-1<<endl;
    for(int i=1;i<=n-2;i+=2)
    {
        cout<<i<<" "<<i+1<<" "<<i+2<<endl;
    }
    for(int i=1;i<=n-2;i+=2)
    {
        cout<<i<<" "<<i+1<<" "<<n<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    // int T;
    // cin>>T;
    // while(T--)
    // {
        solve();
    // }
    return 0;
}