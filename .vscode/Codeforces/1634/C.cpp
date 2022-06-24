#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 505
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
int n, m;
void solve()
{
    n = read(), m = read();
    if (m == 1)
    {
        puts("YES");
        for (int i = 1; i <= n; i ++) printf("%d\n", i);
        return;
    }
    if (n & 1)
    {
        puts("NO");
        return;
    }
    puts("YES");
    int mx = m * n;
    int odd = 1, even = 2;
    for (int i = 1; i <= n / 2; i ++)
    {
        for (int j = 1; j <= m; j ++, odd +=2)
        {
            printf("%d ", odd);
        }
        puts("");
        for (int j = 1; j <= m; j ++, even += 2)
        {
            printf("%d ", even);
        }
        puts("");
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