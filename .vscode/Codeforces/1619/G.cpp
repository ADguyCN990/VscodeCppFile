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
map <pii,int> idx;
int vis[MAXN];
int up = -1;
int down = 1;
int l = -1;
int r = 1;
struct node
{
    int time;
    pii p;
}a[MAXN];
bool cmp(node a, node b) {return a.time < b.time;}
int n,k;
int cnt;



void explode(pii p,int tim)
{
    if (cnt == n) return;
    cnt ++;
    int x = p.first, y = p.second;
    int now = idx[p];
    vis[now] = tim;
    for (int i = 1; i <= k; i ++)
    {
        int a, b;
        if(idx.count({a + up * k, b}) && !vis[idx[{a + up * k,b}]])
            explode({a + up * k,b}, tim);
        if(idx.count({a + down * k, b}) && !vis[idx[{a + down * k,b}]])
            explode({a + down * k,b}, tim);
        if(idx.count({a, b + l * k}) && !vis[idx[{a, b + l * k}]])
            explode({a, b + l * k}, tim);
        if(idx.count({a, b + r * k}) && !vis[idx[{a, b + r * k}]])
            explode({a, b + r * k}, tim);

    }

}



void solve()
{
    n=read(),k=read();
    idx.clear();
    for (int i = 1; i <= n; i ++) vis[i] = 0;
    cnt = 0;
    for (int i = 1; i <= n; i ++)
    {
        pii p;
        int time;
        p.first = read(), p.second = read();
        time = read();
        a[i] = {time, p};
    }
    sort(a + 1, a + 1 + n, cmp);
    for(int i = 1; i <= n; i++)  idx[a[i].p] = i;  //并查集初始化

    for (int i = 0; i < n; i ++)
    {
        if (cnt == n)
        {
            printf("%d\n",i);
            return;
        }
        if (!vis[idx[a[n - i].p]])
            explode(a[n - i].p, i);
        if (!vis[idx[a[i].p]] && a[i].time == i)
            explode(a[i].p, a[i].time);
    }
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