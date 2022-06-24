#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
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
ll a[MAXN];
struct node
{
    int l,r,lazy;
    ll sum;
}tree[MAXN<<2];

void pushup(int rt) {tree[rt].sum=tree[rt<<1].sum+tree[rt<<1|1].sum;}

void pushdown(int rt)
{
    if(tree[rt].lazy)
    {
        tree[rt<<1].lazy+=tree[rt].lazy;
        tree[rt<<1|1].lazy+=tree[rt].lazy;
        tree[rt<<1].sum+=tree[rt].lazy*(tree[rt<<1].r-tree[rt<<1].l+1);
        tree[rt<<1|1].sum+=tree[rt].lazy*(tree[rt<<1|1].r-tree[rt<<1|1].l+1);
        tree[rt].lazy=0;
    }
}

void build(int rt,int l,int r)
{
    tree[rt].l=l;tree[rt].r=r;
    if(l==r)
    {
        tree[rt].sum=a[l];
        tree[rt].lazy=0;
        return;
    }
    int mid=l+r>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    pushup(rt);
}

void update(int rt,int l,int r,int x)
{
    if(tree[rt].l>=l&&tree[rt].r<=r)
    {
        tree[rt].lazy+=x;
        tree[rt].sum+=(tree[rt].r-tree[rt].l+1)*x;
        return;
    }
    int mid=tree[rt].l+tree[rt].r>>1;
    pushdown(rt);
    if(mid>=l)
        update(rt<<1,l,r,x);
    if(mid+1<=r)
        update(rt<<1|1,l,r,x);
    pushup(rt);
}

ll query(int rt,int l,int r)
{
    if(tree[rt].l>=l&&tree[rt].r<=r)
    {
        return tree[rt].sum;
    }
    pushdown(rt);
    int mid=tree[rt].l+tree[rt].r>>1;
    ll ans=0;
    if(mid>=l)
        ans+=query(rt<<1,l,r);
    if(mid+1<=r)
        ans+=query(rt<<1|1,l,r);
    return ans;
}

int n,m;
ll l,r,d;
char opt[10];
void solve()
{
    n=read(),m=read();
    rep(i,1,n) a[i]=read();
    build(1,1,n);
    while(m--)
    {
        scanf("%s",opt);
        if(opt[0]=='C')
        {
            l=read(),r=read(),d=read();
            update(1,l,r,d);
        }
        else
        {
            l=read(),r=read();
            printf("%lld\n",query(1,l,r));
        }
    }
}

int main()
{
    solve();
    return 0;
}