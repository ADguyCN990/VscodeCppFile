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
int a[5][MAXN];
int cnt[MAXN];
int f[MAXN << 1], cost[MAXN << 1]; //i表示不换，i + n 表示换，数组表示代价，即换了代价为1不换代价为0
int last[MAXN];
bool vis[MAXN << 1];
int n;
vector <int> res;

int findx(int x)
{
    if (x == f[x]) return x;
    return x = findx(f[x]);
}

void init()
{
    for (int i = 1; i <= n; i ++)
    {
        f[i] = i, f[i + n] = i + n;
        cost[i] = 0, cost[i + n] = 1;
        vis[i] = false, vis[i + n] = false;
        last[i] = 0;
        cnt[i] = 0;
    }
    res.clear();
}

void solve()
{
    n = read();
    init();
    for (int i = 1; i <= 2; i ++)
        for (int j = 1; j <= n; j ++)
            a[i][j] = read(), cnt[a[i][j]] ++;
    for (int i = 1; i <= n; i ++)
    {
        if (cnt[i] != 2)
        {
            puts("-1");
            return;
        }
    }
    for (int i = 1; i <= 2; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            int now = a[i][j]; 
            if (!last[now])
            {
                last[now] = j;
                continue;
            }
            int pre = last[now]; //现在所在的列数
            if (pre == j) continue;
            int u = findx(j), v = findx(pre), x = findx(j + n), y = findx(pre + n);
            //u表示当前这一列不换
            //v表示当前这一列换
            //x表示上一次出现的那列不换
            //y表示上一次出现的那列换
            if (a[i][pre] != now) // 不在同一行，要么一起换要么都不换
            {
                if (v == x || u == y) //一个换一个不换就是非法情况
                {
                    puts("-1");
                    return;
                }
                if (u != v) //2SAT连边，都换
                    f[v] = u, cost[u] += cost[v];
                if (x != y) //2SAT连边，都不换
                    f[y] = x, cost[x] += cost[y];
            }
            else //在同一行，必须换
            {
                if (u == v || x == y) //在同一行都换或都不换就是非法情况
                {
                    puts("-1");
                    return;
                }
                if (u != y) //2SAT连边
                    f[y] = u, cost[u] += cost[y];
                if (x != v) //2SAT连边
                    f[v] = x, cost[x] += cost[v];
            }
        }
    }
    for (int i = 1; i <= 2 * n; i ++) f[i] = findx(i); //连通块编号，每一个连通块都对应着若干种合法的方案
    for (int i = 1; i <= n; i ++)
    {
        if (!vis[f[i]] && !vis[f[i + n]]) //都没访问过，否则两个块互斥，相当于已经做好选择了
        {
            if (cost[f[i]] <= cost[f[i + n]])
                vis[f[i]] = true;
            else
                vis[f[i + n]] = true;
        }
    }
    for (int i = 1; i <= n; i ++)
        if (vis[f[i + n]])
            res.pb(i);
    printf("%d\n", res.size());
    for (int x : res) printf("%d ", x);
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