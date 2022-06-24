#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
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
int n;
int a[MAXN];
bool vis[MAXN]; //false的含义是这个数出现过但是没有与之前出现过的数连接起来
int cnt[MAXN];
int pos[MAXN];

void init()
{
    for (int i = 0; i <= n; i ++)
    {
        vis[i] = true;
        pos[i] = 0;
        cnt[i] = 0;
    }   
}

void solve()
{
    n = read();
    init();
    for (int i = 1; i <= n; i ++)
    {
        a[i] = read();
        cnt[a[i]] ++;
    }
    int mx = -1;
    vector <int> ans;
    for (int i = 1; i <= n; i ++)
    {
        pos[a[i]] ++;
        if (a[i] > mx) vis[a[i]] = false;
        while (vis[mx + 1] == false) vis[++ mx] = true;

        if (pos[mx + 1] == cnt[mx + 1])
        {
            ans.pb(mx + 1);
            mx = -1;
        }
    }
    int len = ans.size();
    printf("%d\n", len);
    for (int x : ans) printf("%d ", x);
    puts("");
}

int main()
{
    int T;
    T=read();
    while(T--)
    {
        solve();
    }

    return 0;
}