#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 233333
#define MAXN 200005
ll n;
vector <pair<ll,ll>> mp[mod+5];//fi为真正的hash值，se为出现次数
ll ans=0;
//求出有多少对a+b=b+a
ll hashing(string a,string b)//a+b
{
    return (a[0]-'A')*26+(a[1]-'A')+(b[0]-'A')*26*26*26+(b[1]-'A')*26*26;
}
void insert(ll hash)
{
    for(int i=0;i<mp[hash%mod].size();i++)
    {
        if(mp[hash%mod][i].first==hash)//处理冲突
        {
            mp[hash%mod][i].second++;
            return;
        }      
    }
    mp[hash%mod].emplace_back(pair<ll,ll>(hash,1));
}

ll find(ll hash)
{
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
        a[2]=0; 
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