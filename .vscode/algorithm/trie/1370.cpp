#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 2005
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
int son[MAXM][30],cnt[MAXM],tot;
int dp[MAXN];
string s;

void insert(string s)
{
    int len=s.length();
    int now=0;
    for(int i=0;i<len;i++)
    {
        int u=s[i]-'A';
        if(!son[now][u]) 
            son[now][u]=++tot;
        now=son[now][u];
    }
    cnt[now]++;
}

bool query(int e)
{
    int now=0;
    for(int i=e;i>=0&&e-i+1<=10;i--)
    {
        int u=s[i]-'A';
        if(!son[now][u]) return false;
        else
        {
            now=son[now][u];
            if(cnt[now]&&dp[i]) return true;
        }
    }
    return false;
}

void solve()
{
    string t;
    while(cin>>t,t!=".")
    {
        reverse(t.begin(),t.end());
        insert(t);
    }
    string tmp;
    while(cin>>tmp) s+=tmp;
    //cin>>s;
    dp[0]=1;
    int ans=0;
    int n=s.length();
    for(int i=1;i<=n;i++)
    {
        if(query(i-1))
        {
            ans=i;
            dp[i]=1;
        }
    }
    printf("%d\n",ans);
   // for(int i=0;i<=n;i++) cout<<dp[i]<<" ";
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}