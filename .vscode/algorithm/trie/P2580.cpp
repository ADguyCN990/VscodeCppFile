#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 2000005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define pb emplace_back
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll n,m;
string s;
ll son[MAXN][30],tot,cnt[MAXN];
set <string> ss;

void insert(string s)
{
    int len=s.length();
    int now=0;
    for(int i=0;i<len;i++)
    {
        int u=s[i]-'a';
        if(!son[now][u])
            son[now][u]=++tot;
        now=son[now][u];
    }
    cnt[now]++;
}

bool query(string s)
{
    int len=s.length();
    int now=0;
    for(int i=0;i<len;i++)
    {
        int u=s[i]-'a';
        if(!son[now][u])
            return false;
        now=son[now][u];
    }
    return true;
}

void solve()
{
    cin>>n;
    rep(i,1,n)
    {
        cin>>s;
        insert(s);
    }
    cin>>m;
    rep(i,1,m)
    {
        string s;
        cin>>s;
        bool flag=query(s);
        if(!flag)
            puts("WRONG");
        else if(flag&&ss.count(s))
            puts("REPEAT");
        else 
            puts("OK");
        ss.insert(s);
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}