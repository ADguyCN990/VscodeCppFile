#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
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
ll a[MAXN], b[MAXN], n;
void solve()
{
    priority_queue <ll, vector<ll>, greater<ll>> q;
    n = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    for (int i = 1; i <= n; i ++) b[i] = read();
    for (int i = 1; i <= n; i ++)
    {
        for (int j = 1; j <= n; j ++)
        {
            if ((j - 1) * (i - 1) >= n) break;
            q.push(a[i] + b[j]);
        }
    }
    for (int i = 1; i <= n; i ++)
    {
        printf("%lld ", q.top());
        q.pop();
    }
}

int main()
{
    solve();
    return 0;
}