#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 3005
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
int a[MAXN];
int cnt[MAXN];
void solve()
{
    n = read();
    ll ans = 0;
    for (int i = 1; i <= n; i ++) a[i] = read(), cnt[i] = 0;
    for (int i = 1; i <= n; i ++)
    {
        ll tmp = 0;
        for (int j = i + 1; j <= n; j ++)
        {
            if (a[i] == a[j]) ans += tmp;
            tmp += cnt[a[j]];
        }
        cnt[a[i]] ++;
    }
        
    printf("%lld\n", ans);
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