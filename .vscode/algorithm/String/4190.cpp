#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
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
char p[MAXN], s[MAXN];
int n, m, ne[MAXN];

void solve()
{
    memset(ne, 0, sizeof ne);
    int ans = 0;
    vector <int> pos;
    for (int i = 2, j = 0; i <= n; i ++)
    {
        while (j && p[i] != p[j + 1]) j = ne[j];
        if (p[i] == p[j + 1]) j ++;
        ne[i] = j;
    }
    for (int i = 1, j = 0; i <= m; i ++)
    {
        while (j && s[i] != p[j + 1]) j = ne[j];
        if (s[i] == p[j + 1]) j ++;
        if (j == n)
        {
            pos.pb(i);
            j = ne[j];
        }
    }
    int last = 0;
    for (auto x : pos)
    {
        if (!last || last + n <= x)
        {
            ans ++;
            last = x;
        }
    }
    printf("%d\n", ans);
}

int main()
{
    while (1)
    {
        scanf("%s",s + 1);
        m = strlen(s + 1);
        if (m == 1 && s[1] == '#') break;
        scanf("%s", p + 1);
        n = strlen(p + 1);
        solve();
    }
    return 0;
}