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
struct node
{
    int l, r;
}a[MAXN];
bool cmp (node a, node b)
{
    if (a.l == b.l)
        return a.r > b.r;
    return a.l < b.l;
}
int n;
void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++)
    {
        a[i].l = read(), a[i].r = read();
        if (a[i].l == a[i].r)
        printf("%d %d %d\n", a[i].l, a[i].r, a[i].l);
    }
    sort(a + 1, a + 1 + n, cmp);
    int i = 2;
    for (i = i; i <= n; i ++)
    {
        if (a[i].l == a[i - 1].l)// 1 5  1 3
            printf("%d %d %d\n", a[i].l, a[i - 1].r, a[i].r + 1);
        else if (a[i].r == a[i - 1].r)// 1 5  3 5
            printf("%d %d %d\n", a[i - 1].l, a[i - 1].r, a[i].l - 1);
        if (a[i].l == a[i].r) 
            a[i].l = a[1].l, a[i].r = a[1].r, i ++;
    }
    
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