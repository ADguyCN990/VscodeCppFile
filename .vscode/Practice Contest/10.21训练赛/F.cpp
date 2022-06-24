#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define mod1 11451403
#define mod2 11451449
#define MAXN 400005
ull hash1[MAXN];ull hash2[MAXN];
ull pre1[MAXN];ull pre2[MAXN];
ull p=131;//指定质数
ll n;
int cnt=0;
char s[MAXN];
pair <ull,ull> temp[MAXN];
map <pair<ull,ull>,ll> mp;//哈希表，key为双哈希组成的二元组，value为相同的个数
void init()
{
    pre1[0]=1;pre2[0]=1;
    for(int i=1;i<=400000;i++)
    {
        pre1[i]=(pre1[i-1])*p%mod1;
        pre2[i]=(pre2[i-1])*p%mod2;
    }
}

ull hashing1()
{
    int m=strlen(s+1);
    for(int i=1;i<=m;i++)
    {
        hash1[i]=(hash1[i-1]*p%mod1+(s[i]-'a'+1))%mod1;
    }
    return hash1[m];
}

ull hashing2()
{
    int m=strlen(s+1);
    for(int i=1;i<=m;i++)
    {
        hash2[i]=(hash2[i-1]*p%mod2+(s[i]-'a'+1))%mod2;
    }
    return hash2[m];
}

ull query1(ll l,ll r)
{
    return (hash1[r]-hash1[l-1]*pre1[r-l+1]%mod1+mod1)%mod1;
}
ull query2(ll l,ll r)
{
    return (hash2[r]-hash2[l-1]*pre2[r-l+1]%mod2+mod2)%mod2;
}
pair <ull,ull> query(ll l,ll r)
{
    return make_pair<ull,ull>(query1(l,r),query2(l,r));
}

void solve()
{
    cin>>n;
    init();
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s+1);        
        mp[make_pair(hashing1(),hashing2())]++;
        int m=strlen(s+1);
        for(int j=1;j+j<m;j++)
        {
            if(query(1,j)==query(m-j+1,m))//去掉前后缀后能拼接成一个字符串
            {
                temp[++cnt]=query(j+1,m-j);
                //cout<<query(j+1,m-j).first<<" "<<query(j+1,m-j).second<<endl;
            }
        }
    }
    for(int i=1;i<=cnt;i++) ans+=mp[temp[i]];
    //cout<<ans<<endl;
    for(auto now:mp)
    {
        ans+=now.second*(now.second-1)/2;
    }
    cout<<ans<<endl;
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}