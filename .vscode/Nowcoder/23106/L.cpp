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

double get(double x, double y)
{
    return sqrt(x * x + y * y);
}
char s[MAXN];
void solve()
{
    int n;
    double ans = 0;
    int x = 0, y = 0;
    n = read();
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i ++)
    {
        if (s[i] == 'L') y --;
        else if (s[i] == 'R') y ++;
        else if (s[i] == 'U') x --;
        else x ++;
        ans = max(ans, get(x, y));
    }
    printf("%.6lf\n", ans);
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