#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n,l,r;
ll ans=0;
ll a[15];//进位多产生的权值
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>l>>r;
        ans=0;
        while(l>0||r>0)
        {
            ans+=(r-l);
            l/=10;r/=10;
        }
        cout<<ans<<endl;

    }
    return 0;
}