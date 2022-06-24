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
ll gcd(ll a,ll b)
{
    if(a<b) swap(a,b);
    ll tmp;
    while(b)
    {
       tmp=b;
       b=a%b;
       a=tmp; 
    }
    return a;
}
int n,m;
ll a[MAXN];
ll b[MAXN];//差分
char opt[10];
ll l,r,d;
struct node
{
    int l,r;
    ll sum;//差分前缀和,[l,r]
    ll mx;//最大公约数,gcd(a,b)等价于gcd(a,b-a)，所以在差分上求gcd等价于在原数组上求gcd，差分还可以转化为单点维护
}tree[MAXN<<2];

void pushup(node &rt,node &le,node &ri)
{
    rt.sum=le.sum+ri.sum;
    rt.mx=gcd(le.mx,ri.mx);
}

void pushup(int rt)
{
    tree[rt].sum=tree[rt<<1].sum+tree[rt<<1|1].sum;
    tree[rt].mx=gcd(tree[rt<<1].mx,tree[rt<<1|1].mx);
}

void build(int rt,int l,int r)
{
    tree[rt].l=l;tree[rt].r=r;
    if(l==r)
    {
        tree[rt].mx=b[l];
        tree[rt].sum=b[l];
        return;
    }
    int mid=l+r>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    pushup(rt);
}

void update(int rt,int pos,ll x)//差分思想将区间维护转化成单点维护
{
    if(tree[rt].l==tree[rt].r&&tree[rt].l==pos)
    {
        tree[rt].sum+=x;
        tree[rt].mx+=x;
        return;
    }
    int mid=tree[rt].l+tree[rt].r>>1;
    if(pos<=mid) 
        update(rt<<1,pos,x);
    else if(mid+1<=pos)
        update(rt<<1|1,pos,x);
    pushup(rt);
}

ll get(int rt,int l,int r)//求某个位置的差分前缀和
{
    if(tree[rt].l>=l&&tree[rt].r<=r)
    {
        return tree[rt].sum;
    }
    int mid=tree[rt].l+tree[rt].r>>1;
    if(mid>=r)
        return get(rt<<1,l,r);
    else if(mid+1<=l)
        return get(rt<<1|1,l,r);
    else
        return get(rt<<1,l,r)+get(rt<<1|1,l,r);
}

ll query(int rt,int l,int r)//求区间gcd
{
    if(tree[rt].l>=l&&tree[rt].r<=r)
    {
        return tree[rt].mx;
    }
    int mid=tree[rt].l+tree[rt].r>>1;
    if(mid>=r)
        return query(rt<<1,l,r);
    else if(mid+1<=l)
        return query(rt<<1|1,l,r);
    else
        return gcd(query(rt<<1,l,r),query(rt<<1|1,l,r));
}

void solve()
{
    n=read(),m=read();
    rep(i,1,n) a[i]=read();
    rep(i,1,n) b[i]=a[i]-a[i-1];
    build(1,1,n);
    while(m--)
    {
        scanf("%s",opt);
        if(opt[0]=='Q')
        {
            l=read(),r=read();
            ll start=get(1,1,l);
            ll ans=abs(gcd(start,query(1,l+1,r)));
            printf("%lld\n",ans);
        }
        else if(opt[0]=='C')
        {
            l=read(),r=read(),d=read();
            update(1,l,d);
            if(r+1<=n)
                update(1,r+1,-d);
        }
    }
}

int main()
{
    solve();
    return 0;
}