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
ll n, k;
ll a[MAXN], b[MAXN];
int len, dif;
int x, y;
pii ans[MAXN];

int isvalid(int val)
{
    if (val >= x && val <= y) return 1;
    else return -1;
}

void solve()
{
    n = read(), k = read();
    for (int i = 1; i <= n; i ++) a[i] = read(), b[i] = a[i];
    sort(b + 1, b + 1 + n);
    len = (n + k + 1) >> 1; //范围内的个数减去范围外的个数的数量
    dif = INF; //x和y的差值
    for (int i = 1; i <= n; i ++)
    {
        if (i + len - 1 > n) break;
        int j = i + len - 1;
        if (b[j] - b[i] < dif)
            dif = b[j] - b[i], x = b[i], y = b[j];
    }
    int cnt = 0; // 段数
    printf("%d %d\n", x, y);
    for (int i = 1; i <= n; i ++)
    {
        cnt ++;
        ans[cnt].first = i;
        if (cnt == k) 
        {
            ans[cnt].second = n;
            break;
        }
        int j = i;
        int tmp = isvalid(a[i]);
        while (tmp <= 0) tmp += isvalid(a[++ j]);
        ans[cnt].second = j;
        i = j;
    }
    for (int i = 1; i <= k; i ++) printf("%d %d\n", ans[i].first, ans[i].second);
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