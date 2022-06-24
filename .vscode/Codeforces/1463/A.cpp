#include<bits/stdc++.h>
using namespace std;
#define ll long long 
ll a[5];

void solve()
{
    ll sum=0;
    for(int i=1;i<=3;i++) cin>>a[i];
    sort(a+1,a+1+3);
    for(int i=1;i<=3;i++) sum+=a[i];
    if(sum%9!=0)
    {
        cout<<"NO"<<endl;
        return;
    }
    ll tmp=sum/9;
    if(a[1]<tmp||a[2]<tmp||a[3]<tmp)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
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