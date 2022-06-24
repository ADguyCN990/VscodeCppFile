#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
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
int n, k;
char s[MAXN];

void solve()
{
    n = read(), k = read();
    scanf("%s", s + 1);
    int cnt1 = 0, cnt0 = 0;
    for (int i = 1; i <= k; i ++)
    {
        int now = -1;
        for (int j = i; j <= n; j += k)
        {
            if (now == -1 && s[j] != '?')
            {
                now = s[j] - '0';
            }
            if (now != -1 )
            {
                if (s[j] == '?') continue;
                int tmp = s[j] - '0';
                if (tmp != now)
                {
                    puts("NO");
                    return;
                }
            }
        }
        if (now == 0) cnt0 ++;
        if (now == 1) cnt1 ++;
    }
    if (cnt0 <= k / 2 && cnt1 <= k / 2) puts("YES");
    else puts("NO");
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