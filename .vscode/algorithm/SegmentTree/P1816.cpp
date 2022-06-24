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
ll n;
ll a[MAXN];
struct node
{
    int l,r;
    int mn;
}tree[MAXN<<2];

void pushup(int rt)
{
    tree[rt].mn=min(tree[rt<<1].mn,tree[rt<<1|1].mn);
}

void build(int rt,int l,int r)
{
    tree[rt].l=l;
    tree[rt].r=r;
    if(l==r)
    {
        tree[rt].mn=a[l];
        return;
    }
    int mid=l+r>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    pushup(rt);
}

ll query(int rt,int l,int r)
{
    if(tree[rt].l>=l&&tree[rt].r<=r)
    {
        return tree[rt].mn;
    }
    int mid=tree[rt].l+tree[rt].r>>1;
    ll ans=INF;
    if(mid>=l)
        ans=min(ans,query(rt<<1,l,r));
    if(mid+1<=r)
        ans=min(ans,query(rt<<1|1,l,r));
    return ans;
}
ll m;
void solve()
{
    n=read(),m=read();
    rep(i,1,n) a[i]=read();
    build(1,1,n);
    while(m--)
    {
        int l,r;
        l=read(),r=read();
        printf("%lld ",query(1,l,r));
    }
}

int main()
{
    solve();
    return 0;
}