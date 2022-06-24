#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 500005
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
    int val;
}a[MAXN];
char s[MAXN];
int n;

void solve()
{
    n = read();
    scanf("%s", s + 1);
    a[1] = {0, 3, -1};
    a[2] = {3, INF, -1};
    a[3] = {1, 2, 0};
    for (int i = 1; i <= n; i ++)
    {
        int now = i + 3;
        if (s[i] == 'L') // 插入到 a[i - 1] 的前边
        {
            a[now].l = a[now - 1].l;
            a[now].r = now - 1;
            a[now].val = i;
            a[a[now - 1].l].r = now;
            a[now - 1].l = now; 
        }
        else //插入到 a[i - 1] 的后边
        {
            a[now].l = now - 1;
            a[now].r = a[now - 1].r;
            a[now].val = i;
            a[a[now - 1].r].l = now;
            a[now - 1].r = now;
        }
    }
    for (int i = 1; i != 2; i = a[i].r)
    {
        if (i == 1) continue;
        printf("%d ", a[i].val);
    }
}

int main()
{
    solve();
    return 0;
}