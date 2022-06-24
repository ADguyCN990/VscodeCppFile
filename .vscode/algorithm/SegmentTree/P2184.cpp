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
int n,m;
int opt,l,r;
struct node
{
    int l,r;
    int hh,tt;
}tree[MAXN<<2];

void pushup(int rt)
{
    tree[rt].hh=tree[rt<<1].hh+tree[rt<<1|1].hh;
    tree[rt].tt=tree[rt<<1].tt+tree[rt<<1|1].tt;
}

void build(int rt,int l,int r)
{
    tree[rt].l=l;
    tree[rt].r=r;
    if(l==r)
    {
        tree[rt].hh=0;
        tree[rt].tt=0;
        return;
    }
    int mid=l+r>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    pushup(rt);
}

void update(int rt,int pos,int hh,int tt)
{
    if(tree[rt].l==tree[rt].r&&tree[rt].l==pos)
    {
        tree[rt].hh+=hh;
        tree[rt].tt+=tt;
        return;
    }
    int mid=tree[rt].l+tree[rt].r>>1;
    if(pos<=mid)
        update(rt<<1,pos,hh,tt);
    else if(pos>=mid+1)
        update(rt<<1|1,pos,hh,tt);
    pushup(rt);
}

ll queryh(int rt,int l,int r)
{
    if(tree[rt].l>=l&&tree[rt].r<=r)
    {
        return tree[rt].hh;
    }
    int mid=tree[rt].l+tree[rt].r>>1;
    if(mid>=r)
        return queryh(rt<<1,l,r);
    else if(mid+1<=l)
        return queryh(rt<<1|1,l,r);
    else 
        return queryh(rt<<1,l,r)+queryh(rt<<1|1,l,r);
}

ll queryt(int rt,int l,int r)
{
    if(tree[rt].l>=l&&tree[rt].r<=r)
    {
        return tree[rt].tt;
    }
    int mid=tree[rt].l+tree[rt].r>>1;
    if(mid>=r)
        return queryt(rt<<1,l,r);
    else if(mid+1<=l)
        return queryt(rt<<1|1,l,r);
    else 
        return queryt(rt<<1,l,r)+queryt(rt<<1|1,l,r);
}

void solve()
{
    n=read(),m=read();
    build(1,1,n);
    while(m--)
    {
        opt=read();l=read();r=read();
        if(opt==1)
        {
            update(1,l,1,0);
            update(1,r,0,1);
        }
        else
        {
            printf("%lld\n",queryh(1,1,r)-queryt(1,1,l-1));
        }
    }
}

int main()
{
    solve();
    return 0;
}