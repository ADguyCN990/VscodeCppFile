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
int fa[MAXN];
void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++) fa[i] = i; 
    for (int i = 1; i <= n; i ++)
    {
        int son1, son2;
        son1 = read(), son2 = read();
        fa[son1] = i, fa[son2] = i;
    }
    for (int i = 1; i <= n; i ++)
    {
        int son1, son2;
        son1 = read(), son2 = read();
        if (fa[i] == son1 )
        {
            printf("1\n%d\n", son1);
            return;
        }
        if (fa[i] == son2)
        {
            printf("1\n%d\n", son2);
            return;
        }
    }
    puts("0");
}

int main()
{
    solve();
    return 0;
}