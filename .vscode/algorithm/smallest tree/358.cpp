#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 650005
typedef pair<int,int> pii;
#define INF 1e16
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
int head[MAXN];int tot;
struct EDGE
{
    int to,next,val;
}edge[MAXM];

void add_edge(int from,int to,int val)
{
    edge[++tot].to=to;edge[tot].val=val;edge[tot].next=head[from];head[from]=tot;
}
int n,m,father[MAXN][32],depth[MAXN],f[MAXM];
ll dp[2][MAXN][32],val1,val2,mx,ans;

struct node
{
    int x,y,z,vis;
}s[MAXM];
bool cmp (node a, node b) {return a.z < b.z;}

int findx(int x)
{
    if(x==f[x]) return x;
    else return f[x]=findx(f[x]);
}

void kruskal()
{
    sort(s+1,s+1+m,cmp);
    for (int i = 1; i <= m; i++)
    {
        int a = findx(s[i].x), b = findx(s[i].y);
        if (a == b) continue;
        s[i].vis = 1;
        f[a] = b;
        ans += s[i].z;
        add_edge (s[i].x, s[i].y, s[i].z);
        add_edge (s[i].y, s[i].x, s[i].z);

    }
}

void bfs (int rt)
{
    depth[rt] = 0;
    queue<int> q;
    q.push(rt);
    while (q.size())
    {
        int x = q.front();
        int len = (int) log2(depth[x]+1);
        q.pop();
        for (int i = head[x]; i; i = edge[i].next)
        {
            int y = edge[i].to;
            int val = edge[i].val;
            if (y == father[x][0])
                continue;
            depth[y] = depth[x] + 1;
            father[y][0] = x;
            dp[0][y][0] = val;
            dp[1][y][0] = -INF;
            q.push(y);
            for (int t = 1; t <= len; t++)
            {
                father[y][t] = father[father[y][t-1]][t-1];
                if(dp[0][y][t-1]!=dp[0][father[y][t-1]][t-1])
                {
                    dp[0][y][t]=max(dp[0][y][t-1],dp[0][father[y][t-1]][t-1]);
                    dp[1][y][t]=min(dp[0][y][t-1],dp[0][father[y][t-1]][t-1]);
                }
                else
                {
                    dp[0][y][t]=dp[0][y][t-1];
                    dp[1][y][t]=max(dp[1][y][t-1],dp[1][father[y][t-1]][t-1]);
                }
            }
        }
    }
}

void update2 (int x)
{
    if (x > val1)
        val2 = val1, val1 = x;
    else if (x > val2 && x != val1)   
        val2 = x;   
}

void update (int x, int t)
{
    update2(dp[0][x][t]);
    update2(dp[1][x][t]);
}

void lca (int x, int y)
{
    val1 = val2 = -INF;
    if(depth[x]<depth[y])
        swap(x,y);
    while(depth[x]>depth[y])
    {
        int t=(int)log2(depth[x]-depth[y]);
        update(x,t),x=father[x][t];
    }
    if(x==y)
        return;
    for(int t=(int)log2(depth[x]); t>=0; t--)
    {
        if(father[x][t]!=father[y][t])
        {
            update(x,t),update(y,t);
            x=father[x][t];
            y=father[y][t];
        }
    }
    update(x,0),update(y,0);
}

void solve()
{
    n = read();
    m = read();
    for (int i = 1; i <= m; i++)
    {
        int a, b, c;
        a = read(), b = read(), c = read();
        s[i].x = a, s[i].y = b,s[i].z = c, f[i] = i;
    }
    kruskal();
    bfs (1);
    mx = INF;
    for (int i = 1; i <= m; i++)
    {
        if (!s[i].vis)
        {
            lca (s[i].x, s[i].y);
            if (val1 != s[i].z)
                mx = min(mx, ans - val1 + s[i].z);
            else
                mx = min(mx, ans - val2 + s[i].z);
        }
    }
    printf("%lld\n", mx);
}

int main()
{
    solve();
    return 0;
}