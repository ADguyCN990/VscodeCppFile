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
ll a[MAXN], b[MAXN];
int indgr[MAXN];
vector <int> pos; //正的拓扑序，正序输出
vector <int> neg; //负的拓扑序，逆序输出
ll ans;
void topu()
{
    queue <int> q;
    for (int i = 1; i <= n; i ++)
        if (!indgr[i])
            q.push(i);
    while (q.size())
    {
        int now = q.front();
        q.pop();
        ans += a[now];
        if (a[now] >= 0)
        {
            pos.pb(now);
            if (b[now] == -1) continue;
            int to = b[now];
            a[to] += a[now];
            indgr[to] --;
            if (!indgr[to])
                q.push(to);
        }
        else
        {
            neg.pb(now);
            if (b[now] == -1) continue;
            int to = b[now];
            indgr[to] --;
            if (!indgr[to])
                q.push(to);
        }
    }
}

void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    for (int i = 1; i <= n; i ++) b[i] = read();
    for (int i = 1; i <= n; i ++)
    {
        if (b[i] != -1)
            indgr[b[i]] ++;
    }
    topu();
    printf("%lld\n", ans);
    // 正的从起点开始加，负的从终点开始加
    reverse(neg.begin(), neg.end());
    for (int x : pos) printf("%d ", x);
    for (int x : neg) printf("%d ", x);
    puts("");
}

int main()
{
    solve();
    return 0;
}