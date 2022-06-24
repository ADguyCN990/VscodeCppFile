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
int n;
int a[MAXN];
int cnt[205];
int check(int x)
{
    for (int i = 0; i <= x; i ++) cnt[i] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (a[i] >= x) continue;
        if (!cnt[x - a[i]])
            cnt[a[i]] ++;
        else
        {
            for (int i = 0; i <= x; i ++) cnt[i] = 0;
            ans += 2;
        }
    }
    return ans;
}

void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    int ans = 0;
    for (int i = 2; i <= 200; i ++) //枚举和
    {
        ans = max(ans, check(i));
    }
    printf("%d\n", ans);
}

int main()
{
    solve();
    return 0;
}