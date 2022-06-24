#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 205
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
int n, m;
int a[MAXN], b[MAXN];

bool check(int x)
{
    for (int i = 1; i <= n; i ++)
    {
        bool flag = false;
        for (int j = 1; j <= m; j ++)
        {
            if (flag) break;
            if (((a[i] & b[j]) | x) == x) 
            {
                //printf("%d ans %d or %d = %d\n", a[i], b[j], x, x);
                flag = true;
            }
        }
        if (!flag) return false;
    }
    return true;
}

void solve()
{
    n = read(), m = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    for (int i = 1; i <= m; i ++) b[i] = read();
    int ans = 512;
    for (int i = 0; i <= ans; i ++)
    {
        bool flag = check(i);
        if (flag)
        {
            printf("%d\n", i);
            return;
        }
    }
}

int main()
{
    solve();
    return 0;
}