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
ll n, tmp;
set <ll> s;
void solve()
{
    s.insert(INF), s.insert(-INF);
    n = read();
    tmp = read();
    ll ans = tmp;
    s.insert(tmp);
    for (int i = 1; i < n; i ++)
    {
        tmp = read();
        auto it = s.lower_bound(tmp);
        auto iter = it;
        if (*iter > tmp) it --;
        ll contribute = min(abs(tmp - *it), abs(*iter - tmp));
        ans += contribute;
        s.insert(tmp);
    }
    printf("%lld\n", ans);
}

int main()
{
    solve();
    return 0;
}