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
    int n, a, b;
    a = read(), b = read();
    int ans = b - a;
    for (int i = a; i < b; i ++)
    {
        int tmp = 1 + (i - a) + ((i | b) - b);
        ans = min(ans, tmp);
    }
    for (int i = b + 1; i <= b * 2; i ++)
    {
        int tmp = 1 + (i - b) + ((i | a) - i);
        ans = min(ans, tmp);
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