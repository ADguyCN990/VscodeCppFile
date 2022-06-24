#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 233333
#define MAXN 200005
ll n;
vector <pair<ll,ll>> mp[MAXN];//fi为hash值，se为出现次数
ll ans=0;
//求出有多少对a+b=b+a
ll hashing(string a,string b)//a+b
{
    return a[0]*26*26+a[1]*26+b[0]*26*26+b[1]*26;
}
void insert(ll hash)
{
    for(auto now:mp[hash%mod])
    {
        if(now.first==hash)//处理冲突
        {
            now.second++;
            return;
        }
        mp[hash%mod].emplace_back(make_pair(hash,1));
    }
    
}

ll find(ll hash)
{
    ll cnt=0;
    for(auto now:mp[hash%mod])
    {
        if(now.first==hash) return now.second;
    }
    return 0;
}

void solve()
{
    string a,b;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        a=a.substr(0,2);    
        if(a[0]!=b[0]||a[1]!=b[1])   
        ans+=find(hashing(b,a));
        insert(hashing(a,b));
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}