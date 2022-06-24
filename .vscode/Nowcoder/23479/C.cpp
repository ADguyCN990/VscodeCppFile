#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<ll,ll> pii;
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
ll n, t;
char s[MAXN];
ll a[MAXN];
int vis[MAXN];
vector <pii> red;
vector <pii> blue;
void solve()
{
    n = read(), t = read();
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i ++) a[i] = read();
    for (int i = 1; i <= n; i ++)
    {
        if (s[i] == 'B')
            blue.pb(make_pair(a[i], a[i] + t - 1));
        else
            red.pb(make_pair(a[i], a[i] + t - 1));
    }
    sort(blue.begin(), blue.end());
    sort(red.begin(), red.end());
    int l = 0, r = 0;
    for (int i = 0; i < blue.size(); i ++)
    {
        int x = blue[i].first, y = blue[i].second;
        if (x <= r && y > r)
            r = y;
        else if (x > r)
        {
            for (int j = l; j <= r; j ++)
                vis[j] = 1;
            l = x;
            r = y;
        }

    }
    for (int i = l; i <= r; i ++) vis[i] = 1;
    l = 0, r = 0;
    for (int i = 0; i < red.size(); i ++)
    {
        int x = red[i].first, y = red[i].second;
        if (x <= r && y > r)
            r = y;
        else if (x > r)
        {
            for (int j = l; j <= r; j ++)
                vis[j] = 0;
            l = x;
            r = y;
        }
    }
    for (int i = l; i <= r; i ++) vis[i] = 0;
    int cnt = 0;
    for (int i = 1; i <= 100000; i ++)
        if (vis[i])
            cnt ++;
    printf("%d\n", cnt);
}

int main()
{
    
    solve();
    return 0;
}