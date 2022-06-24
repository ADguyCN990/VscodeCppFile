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
char s[MAXN];
int n;
int a[MAXN], idx;
void solve()
{
    scanf("%s", s + 1);
    idx = 0;
    n = strlen(s + 1);
    int cnt = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (s[i] == '1') cnt ++;
        else 
        {
            if (s[i - 1] == '1') a[++ idx] = cnt;
            cnt = 0;
        }
    }
    if(cnt) a[++ idx] = cnt;
    sort(a + 1, a + 1 + idx, greater<int>());
    int ans = 0;
    for (int i = 1; i <= idx; i += 2) ans += a[i];
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
