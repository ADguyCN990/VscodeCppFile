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

int divide(int l, int r, char now)
{
    int mid = l + r >> 1;
    int cntl = 0, cntr = 0;
    if (l == r)
    {
        if (s[l] == now) return 0;
        else return 1;
    }
    for (int i = l; i <= mid; i ++)
    {
        if (s[i] == now) continue;
        cntl ++;
    }
    for (int i = mid + 1; i <= r; i ++)
    {
        if (s[i] == now) continue;
        cntr ++;
    }
    return min(cntl + divide(mid + 1, r, now + 1), cntr + divide(l, mid , now + 1));
}

void solve()
{
    n = read();
    scanf("%s", s + 1);
    int ans = divide(1, n, 'a');
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