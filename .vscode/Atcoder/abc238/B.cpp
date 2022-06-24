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
int a[MAXN];
vector <int> cut;
void solve()
{
    n = read();
    int now = 0;
    for (int i = 1; i <= n; i ++)
    {
        int tmp = read();
        now = (now + tmp) % 360;
        cut.pb(now);
    }
    int mx = 0;
    sort(cut.begin(), cut.end());
    cut.pb(360);
    int last = 0;
    for (int x : cut)
    {
        mx = max(mx, x - last);
        last = x;
    }
    printf("%d\n", mx);
}

int main()
{
    solve();
    return 0;
}