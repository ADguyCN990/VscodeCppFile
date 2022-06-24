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
ll add[320], sum[320]; //懒惰标记和区间和的真实值
int n, m; //区间长度和操作个数
char opt[10]; 
int a[MAXN]; 
int l, r, d;
int len; //块的长度

int get(int x) //通过点编号获得块编号
{
    return (x - 1) / len;
}

void update(int l, int r, int d)
{
    if (get(l) == get(r)) //段内直接暴力
    {
        for (int i = l; i <= r; i ++) a[i] += d, sum[get(i)] += d;
    }
    else
    {
        int i = l, j = r;
        while (get(i) == get(l)) sum[get(i)] += d, a[i] += d, i ++;
        while (get(j) == get(r)) sum[get(j)] += d, a[j] += d, j --;
        for (int k = get(i); k <= get(j); k ++) sum[k] += d * len, add[k] += d;
    }
}

ll query(int l, int r)
{
    ll ans = 0;
    if (get(l) == get(r))
    {
        for (int i = l; i <= r; i ++) ans += a[i] + add[get(i)];
    }
    else
    {
        int i = l, j = r;
        while (get(i) == get(l)) ans += a[i] + add[get(i)], i ++;
        while (get(j) == get(r)) ans += a[j] + add[get(j)], j --;
        for (int k = get(i); k <= get(j); k ++) ans += sum[k];
    }
    return ans;
}

void solve()
{
    n = read(), m = read();
    len = sqrt(n); //分块
    for (int i = 1; i <= n; i ++) a[i] = read(), sum[get(i)] += a[i];
    while (m --)
    {
        scanf("%s%d%d",opt, &l, &r);
        if (opt[0] == 'C')
        {
            d = read();
            update(l, r, d);
        }
        else
            printf("%lld\n", query(l, r));
    }
}

int main()
{
    solve();
    return 0;
}