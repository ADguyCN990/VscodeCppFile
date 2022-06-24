#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 20005
#define MAXM 200005
typedef pair<ll,ll> pii;
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
int f[MAXN];
map <ll,int> mp;int cnt;
ll x, y, z, q;
ll a[MAXN];
ll b[MAXN];
int n;
int findx(int x)
{
    if(x==f[x]) return x;
    else return f[x]=findx(f[x]);
}
void merge(int x,int y)
{
    int fx=findx(x);
    int fy=findx(y);
    if(fy!=fx) f[fy]=fx;
}

void solve()
{
    n = read(), x = read(), y = read(), z = read(), q = read();
    for (int i = 1; i <= n; i ++)
    {
        ll tmp;
        tmp = read();
        if(!mp.count(tmp)) mp[tmp] = ++ cnt;
    }
    for (int i = 1; i <= n; i ++) f[i] = i;
    for (int i = 1; i <= x; i ++)
    {
        a[i] = read();
        a[i] = mp[a[i]];
    }
    for (int i = 1; i <= y; i ++)
    {
        b[i] = read();
        b[i] = mp[b[i]];
        if (i != 1) merge(b[1], b[i]);
    }
    int wa = b[1];
    for (int i = 1; i <= z; i ++)
    {
        ll u, v;
        u = mp[u], v = mp[v];
        merge(u, v);
    }
    for (int i = 1; i <= cnt; i ++) cout << f[i] <<" ";
    cout << endl;
    while (q --)
    {
        ll u;
        u = mp[u];
        int fx = findx(u);
        if (fx != findx(wa))
        {
            puts("ac");
        }
        else
            puts("wa");
    }
}

int main()
{
    solve();

    return 0;
}