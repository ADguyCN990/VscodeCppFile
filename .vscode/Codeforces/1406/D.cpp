#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
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

ll n,q;
ll a[MAXN];
ll d[MAXN];//a的差分数组
ll sum;//正差分和
void work(int pos,ll val,ll now)//维护差分数组的正差分值
{
    if(d[pos]>0&&now<=0) sum-=d[pos];
    else if(d[pos]<=0&&now>0) sum+=now;
    else if(d[pos]>=0&&now>=0) sum+=val;
    d[pos]=now;
    
}

void solve()
{
    n=read();
    sum=0;
    rep(i,1,n) a[i]=read();
    d[1]=a[1];
    rep(i,2,n) d[i]=a[i]-a[i-1];
    //差分数组下，最小化max(b[i],c[i]) 即为最小化 max(b[n],c[1]) 
    rep(i,2,n)
    {
        if(d[i]>0)
            sum+=d[i];
    }
    ll b1=(d[1]-sum)/2;//b的差分数组中的b[1]
    ll c1=d[1]-b1;//c的差分数组中的c[1]
    cout<<max(b1+sum,c1)<<endl;
    q=read();
    while(q--)
    {
        ll l,r,val;//改变了l和r+1处的值
        l=read(),r=read(),val=read();
        //处理d[l]的部分
        if(l==1) 
            d[l]+=val;
        else
            work(l,val,d[l]+val);
        //处理d[r+1]的部分
        if(r==n) 
            d[r+1]-=val;//这个d[r+1]不会对正差分和产生贡献，因为求b[n]不会用到d[n+1]
        else
            work(r+1,-val,d[r+1]-val);
        b1=(d[1]-sum)/2;
        c1=d[1]-b1;
        cout<<max(b1+sum,c1)<<endl;
    }
}

int main()
{
    solve();
    return 0;
}