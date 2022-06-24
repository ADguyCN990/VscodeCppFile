#include<bits/stdc++.h>
using namespace std;
#define MAXN 30
int t,n;
int a[MAXN<<1];
void solve()
{
    cin>>n;
    for(int i=1;i<=2*n;i++) cin>>a[i];
    sort(a+1,a+1+2*n);
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" "<<a[i+n]<<" ";
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}