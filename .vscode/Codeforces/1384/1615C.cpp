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
char a[MAXN], b[MAXN];
void solve()
{
    n = read();
    scanf("%s", a + 1);
    scanf("%s", b + 1);
    int same0 = 0, same1 = 0, dif0 = 0, dif1 = 0, ans = INF;
    for (int i = 1; i <= n; i ++)
    {
        if (a[i] == b[i])
        {
            if (a[i] == '0')
                same0 ++;
            else
                same1 ++;
        }
        else
        {
            if (a[i] == '0')
                dif0 ++;
            else
                dif1 ++;
        }
    }
    if (dif0 == dif1)
        ans = min(ans, dif0 + dif1);
    if (same1 - same0 == 1)
        ans = min(ans, same1 + same0);
    if (ans == INF)
        puts("-1");
    else
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