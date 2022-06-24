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
int a[105][5];
int dis[MAXN];
void solve()
{
    int n;
    n = read();
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= 3; j ++)
            a[i][j] = read();
    for (int i = 1; i <= n; i ++)
    {
        dis[i] = dis[i - 1] + 1;
        if (a[i][1] == 1)
        {
            if (dis[i - 1] + 4 >= dis[i])
                dis[i] = dis[i - 1] + 4;
        }
        if (a[i][2] == 1)
        {
            if (dis[i - 2] + 4 >= dis[i])
                dis[i] = dis[i - 2] + 4;
        }
        if (a[i][3] == 1)
        {
            if (dis[i - 3] + 4 >= dis[i])
                dis[i] = dis[i - 3] + 4;
        }
    }
    printf("%d\n", dis[n] - n);
}

int main()
{
    solve();
    return 0;
}