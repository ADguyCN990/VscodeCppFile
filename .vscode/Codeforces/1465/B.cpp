#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    ll n;
    cin>>n;
    ll now=n;
    vector <int> v;
    while(1)
    {
        int flag=1;
        v.clear();
        ll ans=now;
        while(now)
        {
            v.emplace_back(now%10);
            now/=10;
        }
        for(int i=0;i<v.size();i++)
        {
            if(v[i]!=0&&ans%v[i]!=0)
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            cout<<ans<<endl;
            return;
        }
        now=ans;
        now++;

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