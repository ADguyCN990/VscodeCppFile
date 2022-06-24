#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
#define ll long long
ll n;
string s;
//'*'是羊，'.'是空格
ll sum[MAXN];
vector <int> pos;
void solve()
{
    cin>>n>>s;
    for(int i=1;i<=n;i++) sum[i]=0;
    pos.clear();
    pos.emplace_back(-1);
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='*') sum[i]=sum[i-1]+1;
        else sum[i]=sum[i-1];
        if(s[i]=='*') pos.emplace_back(i);
    }
    //l=sum[i],r=sum[n]-sum[i]
    ll ans=0;
    ll len=pos.size()-1;
    ll mid=pos[(1+len)/2];
    ll l=1;ll r=1;
    for(int i=1;i<=len;i++)
    {
        if(pos[i]<mid)
        {
            ans=ans+abs(mid-pos[i])-l;
            l++;
        }
        else if(pos[i]>mid)
        {
            ans=ans+abs(pos[i]-mid)-r;
            r++;
        }
    }
    cout<<ans<<endl;
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