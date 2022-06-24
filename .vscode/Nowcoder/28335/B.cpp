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
void solve()
{
    int n;
    n = read();
    for (int j = 1; j <= n; j ++)
    {
        for (int i = 1; i <= 2 * n - 1; i ++)
        {
            if (j == i * 2 - 1 && i % 2 == 1) printf("\\");
            else if ((n - i) <= j && i + 2 * j - 1 == 2 * n + 2) printf("/");
            else if (i * 2 - 1 == n) printf("|");
            else printf(" ");
        }
        puts("");
    }
    for (int i = 1; i <= n; i ++)
    {
        if (i * 2 - 1 == n) printf("O");
        else printf("-");
    }
    for (int j = n; j >= 1; j --)
    {

    }
}

int main()
{
    solve();
    return 0;
}