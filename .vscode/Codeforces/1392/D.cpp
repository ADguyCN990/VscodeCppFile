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
char s[MAXN];
void solve()
{
    n = read();
    scanf("%s", s + 1);
    int len = n;
    int cnt = 0;
    while (s[1] == s[n])
    {
        cnt ++; 
        n --;
    }
    if (n == 0)
    {
        if (len <= 2) puts("0");
        else printf("%d\n", (len + 2) / 3);
        return;
    }
    int ans = 0;
    s[n + 1] = '#';
    for (int i = 1; i <= n; i ++)
    {
        cnt ++;
        if (s[i] != s[i + 1])
        {
            ans += cnt / 3;
            cnt = 0;
        }
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