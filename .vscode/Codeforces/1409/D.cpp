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
char s[20];
int k, n;

bool check()
{
    int ans = 0;
    for (int i = 1; i <= n; i ++)
    {
        int u = s[i] - '0';
        ans += u;
    }
    return ans <= k;
}

void solve()
{
    scanf("%s", s + 1);
    k = read();
    n = strlen(s + 1);
    bool flag = check();
    if (flag)
    {
        puts("0");
        return;
    }
    if (n == 1)
    {
        int u = s[1] -'0';
        printf("%d\n", 10 - u);
        return;
    }
    int pos = 0, sum = 0;
    for (int i = 1; i <= n; i ++)
    {
        int u = s[i] - '0';
        sum += u;
        if (sum > k)
        {
            int j = i;
            while (sum + 1 > k && j >= 0)
            {
                int u = s[j] - '0';
                sum -= u;
                j --;
            }
            pos = j;
            break;
        }
    }
    ll ans = 0, tmp = 0;
    for (int i = 1; i <= pos; i ++)
    {
        int u = s[i] - '0';
        ans = ans * 10 + u;
        tmp = tmp * 10 + u;
    }
    ans ++;
    for (int i = pos + 1; i <= n; i ++)
    {
        int u = s[i] - '0';
        ans *= 10;
        tmp = tmp * 10 + u;
    }
    printf("%lld\n", ans - tmp);
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