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
int ans[MAXN];
int cnt;

void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++) ans[i] = 0;
    scanf("%s", s + 1);
    cnt = 0;
    queue <int> q0, q1;
    for (int i = 1; i <= n; i ++)
    {
        if (s[i] == '1')
        {
            if (q0.size())
            {
                int now = q0.front();
                q0.pop();
                ans[i] = now;
                q1.push(now);
            }
            else
            {
                int now = ++ cnt;
                ans[i] = now;
                q1.push(now);
            }
        }
        else
        {
            if (q1.size())
            {
                int now = q1.front();
                q1.pop();
                ans[i] = now;
                q0.push(now);
            }
            else
            {
                int now = ++ cnt;
                ans[i] = now;
                q0.push(now);
            }
        }
    }
    printf("%d\n", cnt);
    for (int i = 1; i <= n; i ++)
        printf("%d ", ans[i]);
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