#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 400005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

struct node
{
    ll val;
    ll id;
}a[MAXN],c[MAXN],ask[MAXN];//a为原数组，c为差分数组，ask为询问的k用于维护离线查询的结果
ll ans[MAXN];//离线查询后的答案
ll f[MAXN],sum[MAXN];//前缀和,f用于统计某段区间内原先自己拥有的货物的数量，sum用于统计货物价值总和
ll n,m,q;

bool cmp(node a,node b) {return a.val<b.val;}

ll work(int l,int r)
{
    int num=f[r]-f[l-1];//统计区间内有多少个自己的商品
    //cout<<"l: "<<l<<" r: "<<r<<" size: "<<num<<endl;
    return sum[r]-sum[r-num];
}

void solve()
{
    n=read(),m=read(),q=read();
    ll now=0;//当前拥有的货物价值
    rep(i,1,n+m)
    {
        ll tmp=read();
        if(i<=n) now+=tmp;
        a[i].val=tmp;
        if(i<=n) a[i].id=1;
        else a[i].id=0;
    }
    sort(a+1,a+1+n+m,cmp);
    // rep(i,1,n+m)
    // {
    //     cout<<a[i].val<<" "<<a[i].id<<endl;
    // }
    // cout<<"————————————————————"<<endl;
    rep(i,1,n+m)
    {
        sum[i]=sum[i-1]+a[i].val;
        f[i]=f[i-1]+a[i].id;
    }

    rep(i,1,q)//离线处理
    {
        ll tmp=read();
        ask[i].val=tmp,ask[i].id=i;
    }
    sort(ask+1,ask+1+q,cmp);

    rep(i,1,n+m-1)//差分
    {
        c[i].val=a[i+1].val-a[i].val;
        c[i].id=i;//第i和第i+1个区间
    }
    sort(c+1,c+n+m,cmp);
    //rep(i,1,n+m-1) cout<<"val: "<<c[i].val<<" "<<"id: "<<c[i].id<<endl;
    set <ll> s;
    rep(i,1,n+m) s.insert(i);
    s.insert(n+m+1);//作为哨兵，必须得加
    ll l=1;
    rep(i,1,q)
    {
        //cout<<"!!! "<<ask[i].val<<endl;
        while(l<n+m&&c[l].val<=ask[i].val)//若此时某两段区间的差值小于k，则计算完他们的贡献后合并他们
        {
            auto it=s.upper_bound(c[l].id); //这是upper，减去1以后即为最大的小于等于k的位置   
            auto pre=it;
            auto nxt=it;
            pre--,nxt++;
            //cout<<*pre<<" "<<*it<<" "<<*nxt<<endl;
            now -= work(*pre, *it - 1);
			now -= work(*it, *nxt - 1);
			now += work(*pre, *nxt - 1);
            s.erase(it);
            // cout<<"now: "<<endl;
            // for(auto x:s) cout<<x<<" ";
            // cout<<endl;
            l++;
        }
        ans[ask[i].id]=now;
    }
    rep(i,1,q) cout<<ans[i]<<" ";
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}