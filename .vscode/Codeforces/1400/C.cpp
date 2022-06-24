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
int n, x;
char s[MAXN];
char tmp[MAXN];
char t[MAXN];
void solve()
{
    scanf("%s", s + 1);
    x = read();
    n = strlen(s + 1);
    for (int i = 1; i <= n; i ++) tmp[i] = '1';
    for (int i = 1; i <= n; i ++)
    {
        if (s[i] == '1') continue;
        if (i - x > 0) tmp[i - x] = '0';
        if (i + x <= n) tmp[i + x] = '0';
    }
    for (int i = 1; i <= n; i ++)
    {
        if ((i + x > n || i + x <= n && tmp[i + x] == '0') && (i - x > 0 && tmp[i - x] == '0' || i - x <= 0))
            t[i] = '0';
        else
            t[i] = '1';
    }
    for (int i = 1; i <= n; i ++)
    {
        if (t[i] != s[i])
        {
            puts("-1");
            return;
        }
    }
    for (int i = 1; i <= n; i ++) printf("%c", tmp[i]);
    puts("");
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