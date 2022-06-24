#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 400005
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
int head[MAXN];int tot;
struct node
{
    int to,from,val;
}edge[MAXM];

int n, m;
int f[MAXN];
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
    n = read(), m = read();
    for (int i = 1; i <= m; i ++)
    {
        edge[i].from = read();
        edge[i].to = read();
        edge[i].val = read();
    }
    int ans = 0;
    for (int i = 31; i >= 0; i --) //规定的最大位数
    {
        int mx = ans;
        for (int j = i - 1; j >= 0; j --)
            mx |= (1 << j); //限制位数下MST可能取到的最大权值
        vector <node> v;
        for (int j = 1; j <= m; j ++)        
            if ((edge[j].val | mx) <= mx)           
                v.pb(edge[j]);
        int cnt = 0;
        for (int j = 1; j <= n; j ++) f[j] = j;
        for (node now : v)
        {
            int a = findx(now.from);
            int b = findx(now.to);
            if (a != b)
            {
                f[b] = a;
                cnt ++;
                if (cnt == n - 1) //以目前已加入边的前提下，满足新加入边的边权位数不超过i的条件下，若能组成MST，就不加这条边。否则就意味着必须加上边权位数大小为i的某条边来保证连通性，加上其贡献
                    break;
            }
        }    
        if (cnt < n - 1) 
            ans |= (1 << i);
    }
    printf("%d\n", ans);
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