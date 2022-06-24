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

int n,m,p;
char opt[10];
int a[MAXN];
struct segmenttree
{
    int l,r,mx;
}tree[MAXN<<2];

void pushup(int rt)
{
    tree[rt].mx=max(tree[rt<<1].mx,tree[rt<<1|1].mx);
}

void build(int rt,int l,int r)
{
    tree[rt].l=l;tree[rt].r=r;
    if(l==r)
    {
        tree[rt].mx=a[l];
        return;
    }
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    pushup(rt);
}

void update(int rt,int pos,int x)
{
    int l=tree[rt].l;
    int r=tree[rt].r;
    int mid=(l+r)/2;
    if(l==r&&l==pos)
    {
        tree[rt].mx=x;
        return;
    }
    if(pos<=mid)
        update(rt<<1,pos,x);
    else if(pos>mid)
        update(rt<<1|1,pos,x);
    pushup(rt);
}

int query(int rt,int l,int r)
{
    if(tree[rt].l>=l&&tree[rt].r<=r)
    {
        return tree[rt].mx;
    }
    if(tree[rt].l>r||tree[rt].r<l)
    {
        return 0;
    }
    return max(query(rt<<1,l,r),query(rt<<1|1,l,r));
}

void solve()
{
    m=read(),p=read();
    int pre=0;
    int x;
    n=200000;
    int nn=0;
    build(1,1,n);
    while(m--)
    {
        scanf("%s",opt);
        x=read();
        if(opt[0]=='A')
        {
            nn++;
            update(1,nn,(x+pre)%p);
            //printf("debug: %d\n",a[n]);
        }
        else if(opt[0]=='Q')
        {
            pre=query(1,nn-x+1,nn);
            printf("%d\n",pre);
        }
    }
}

int main()
{
    solve();
    return 0;
}