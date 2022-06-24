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
int a[1005];
int b[1005];
int n, m;
void solve()
{
    n = read(), m = read();
    memset(a, 0, sizeof a);
    memset(b, 0, sizeof b);
    for (int i = 1; i <= n; i ++)
    {
        int tmp = read();
        a[tmp] ++;
    }
    for (int i = 1; i <= m; i ++)
    {
        int tmp = read();
        b[tmp] ++;
    }
    for (int i = 1; i <= 1000; i ++)
    {
        if (a[i] && b[i])
        {
            puts("YES");
            printf("1 %d\n", i);
            return;
        }
    }
    puts("NO");
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