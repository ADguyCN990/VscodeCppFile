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
ll n,m;
ll l,r,k,dx,opt;
ll a[MAXN];
ll b[MAXN];
struct node
{
    int l,r,len;
    ll sum;
    ll add;
}tree[MAXN<<2];

void pushup(int rt)
{
    tree[rt].sum=tree[rt<<1].sum+tree[rt<<1|1].sum;
}
void work(node &ans,ll add)
{
    ans.add+=add;
    ans.sum+=ans.len*add;
}
void pushdown(int rt)
{
    work(tree[rt<<1],tree[rt].add);
    work(tree[rt<<1|1],tree[rt].add);
    tree[rt].add=0;
}
void build(int rt,int l,int r)
{
    tree[rt].l=l;tree[rt].r=r;tree[rt].len=r-l+1;
    if(l==r)
    {
        tree[rt].sum=b[l];
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
        return tree[rt].sum;
    }
    pushdown(rt);
    int mid=tree[rt].l+tree[rt].r>>1;
    ll ans=0;
    if(mid>=l)
        ans+=query(rt<<1,l,r);
    if (mid+1<=r)
        ans+=query(rt<<1|1,l,r);
    return ans;
}

void preupdate(int rt,int pos,ll x)
{
    if(tree[rt].r==tree[rt].l&&tree[rt].l==pos)
    {
        tree[rt].sum+=x;
        return;
    }
    pushdown(rt);
    int mid=tree[rt].l+tree[rt].r>>1;
    if(pos<=mid)
        preupdate(rt<<1,pos,x);
    else if(mid+1<=pos)
        preupdate(rt<<1|1,pos,x);
    pushup(rt);
}

void update(int rt,int l,int r,ll x)
{
    if(tree[rt].l>=l&&tree[rt].r<=r)
    {
        work(tree[rt],x);
        return;
    }
    pushdown(rt);
    int mid=tree[rt].l+tree[rt].r>>1;
    if(mid>=l)
        update(rt<<1,l,r,x);
    if(mid+1<=r)
        update(rt<<1|1,l,r,x);
    pushup(rt);
}

void solve()
{
    n=read();m=read();
    rep(i,1,n) 
    {
        a[i]=read();
        b[i]=a[i]-a[i-1];
    }
    build(1,1,n);
    while(m--)
    {
        opt=read();
        if(opt==1)
        {
            l=read(),r=read(),k=read(),dx=read();
            ll e=k+dx*(r-l);
            preupdate(1,l,k);
            if(l!=r)
                update(1,l+1,r,dx);
            if(r+1<=n)
                preupdate(1,r+1,-e);
        }
        else
        {
            l=read();
            printf("%lld\n",query(1,1,l));
        }
    }
}

int main()
{
    solve();
    return 0;
}