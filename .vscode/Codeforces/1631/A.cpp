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
int a[MAXN], b[MAXN];
void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    for (int i = 1; i <= n; i ++) b[i] = read();
    for (int i = 1; i <= n; i ++)
        if (a[i] > b[i])
            swap(a[i], b[i]);
    int mx1 = 0, mx2 = 0;
    for (int i = 1; i <= n; i ++)
        mx1 = max(mx1, a[i]), mx2 = max(mx2, b[i]);
    printf("%d\n", mx1 * mx2);
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