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
int n,m;
int a[MAXN];
struct segmentnode
{
    int l,r;
    ll sum,lmx,rmx,mx;//mx表示最大区间和，lsum表示最大前缀和，rsum表示最大后缀和
}tree[MAXN<<2];

void pushup(int rt)
{
    int suml=tree[rt<<1].mx;
    int sum=tree[rt<<1].rmx+tree[rt<<1|1].lmx;
    int sumr=tree[rt<<1|1].mx;

    tree[rt].sum=tree[rt<<1].sum+tree[rt<<1|1].sum;

    tree[rt].mx=max({suml,sum,sumr});
    tree[rt].lmx=max(tree[rt<<1].lmx,tree[rt<<1].sum+tree[rt<<1|1].lmx);
    tree[rt].rmx=max(tree[rt<<1|1].rmx,tree[rt<<1|1].sum+tree[rt<<1].rmx);
}

void build(int rt,int l,int r)
{
    tree[rt].l=l,tree[rt].r=r;
    if(l==r)
    {
        tree[rt].sum=a[l];
        tree[rt].mx=a[l];
        tree[rt].lmx=a[l],tree[rt].rmx=a[l];
        //printf("l: %d,r: %d,lsum: %lld,sum: %lld,rsum: %lld\n",tree[rt].l,tree[rt].r,tree[rt].lsum,tree[rt].sum,tree[rt].rsum);
        return;
    }
    int mid=l+r>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    pushup(rt);
    //printf("l: %d,r: %d,lsum: %lld,sum: %lld,rsum: %lld\n",tree[rt].l,tree[rt].r,tree[rt].lsum,tree[rt].sum,tree[rt].rsum);
}

segmentnode query(int rt,int l,int r)
{
    if(tree[rt].l>=l&&tree[rt].r<=r)
        return tree[rt];
    int mid=(tree[rt].l+tree[rt].r)>>1;
    if(mid>=r)
        return query(rt<<1,l,r);
    else if(mid+1<=l)
        return query(rt<<1|1,l,r);
    else
    {
        auto left=query(rt<<1,l,r);
        auto right=query(rt<<1|1,l,r);
        segmentnode ans;
        ans.sum=left.sum+right.sum;
        ans.lmx=max(left.lmx,left.sum+right.lmx);
        ans.rmx=max(right.rmx,right.sum+left.rmx);
        ans.mx=max({left.mx,right.mx,left.rmx+right.lmx});
        return ans;
    }
}

void update(int rt,int pos,ll x)
{
    if(tree[rt].l==tree[rt].r&&pos==tree[rt].l)
    {
        tree[rt].sum=x;
        tree[rt].mx=x;
        tree[rt].lmx=x,tree[rt].rmx=x;
        return;
    }
    int mid=tree[rt].l+tree[rt].r>>1;
    if(pos<=mid)
        update(rt<<1,pos,x);
    else if(pos>mid)
        update(rt<<1|1,pos,x);
    pushup(rt);

}

void solve()
{
    n=read(),m=read();
    rep(i,1,n) a[i]=read();
    build(1,1,n);
    while(m--)
    {
        int opt,x,y;
        opt=read(),x=read(),y=read();
        if(opt==1)//查询
        {
            if(x>y) swap(x,y);
            printf("%lld\n",query(1,x,y).mx);
        }
        else if(opt==2)//修改
        {
            update(1,x,y);
        }
    }
}

int main()
{
    solve();
    return 0;
}