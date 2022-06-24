#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
char s[MAXN];
ll n;

void solve()
{
    cin>>n;
    cin>>s+1;
    int cnt0=0;int cnt1=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='0')
            cnt0++;
        else if(s[i]=='1')
            cnt1++;
    }
    int need=0;
    vector <int> v;
    vector <int> vv;
    for(int i=1;i<=cnt0;i++)
        if(s[i]=='1')
        {
            need++;
            v.emplace_back(i);
        }
    if(need==0)
    {
        cout<<0<<endl;
        return;
    }
    cout<<1<<endl;
    cout<<need*2<<" ";
    for(int i=n,cnt=1;cnt<=need;i--)
    {
        if(s[i]=='0')
        {
            vv.emplace_back(i);
            cnt++;
        }
                 
    }
    reverse(vv.begin(),vv.end());
    for(auto x:v) cout<<x<<" ";
    for(auto x:vv) cout<<x<<" ";
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