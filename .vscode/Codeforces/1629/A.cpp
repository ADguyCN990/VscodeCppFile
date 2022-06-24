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
int n, k;
struct node
{
    int val;
    int b;
}a[MAXN];
bool cmp(node a, node b) {return a.val < b.val;}

void solve()
{
    n = read(), k = read();    
    for (int i = 1; i <= n; i ++)
    {
        a[i].val = read();
    }
    for (int i = 1; i <= n; i ++) a[i].b = read();
    sort(a + 1, a + 1 + n, cmp);
    for (int i = 1; i <= n; i ++)
    {
        if (k < a[i].val)
        {
            printf("%d\n", k);
            return;
        }
        k += a[i].b;
    }
    printf("%d\n", k);
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