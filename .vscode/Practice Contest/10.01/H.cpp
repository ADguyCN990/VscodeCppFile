#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll t,n,k,p,v,type;
struct node
{
    ll type;
    ll speed;
    ll pos;
}a[MAXN];
bool cmp(node a,node b){return a.pos<b.pos;}
ll L[MAXN],R[MAXN];//用于记录相对位置，如果前后两辆车类型相同则缩为一个点
struct c
{
    ll now_pos;//过了x秒后的位置
    ll index;//用于识别x秒后这是哪辆车
}car[MAXN];//存放x秒后车辆的状态
bool cmpp(c a,c b) {return a.now_pos<b.now_pos;}
bool check(ll x)//过了x秒后，查看当前状态有没有翻车
{
    for(int i=1;i<=n;i++)
    {
        car[i].now_pos=a[i].pos+a[i].speed*x;
        car[i].index=i;
    }
    sort(car+1,car+1+n,cmpp);
    for(int i=1;i<=n;i++)
    {
        if(i!=1&&car[i].now_pos==car[i-1].now_pos&&a[car[i].index].type!=a[car[i-1].index].type)//两辆车在同一位置且不是同一种类型
        {
            return false;
        }
        if(i<L[car[i].index]||i>R[car[i].index]) return false;//已经被前面的车追上或者追上了后面的车（早就车祸了）
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    cin>>n>>k;//车辆的数量和车辆的种类
    for(int i=1;i<=n;i++) cin>>a[i].pos>>a[i].speed>>a[i].type;
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)//记录相对位置
    {
        if(a[i].type==a[i-1].type) L[i]=L[i-1];
        else L[i]=i;
    }
    for(int i=n;i>0;i--)//记录相对位置
    {
        if(a[i].type==a[i+1].type) R[i]=R[i+1];
        else R[i]=i;
    }
    ll l=0;ll r=2e9+100;ll ans=-1;
    while(l<=r)//对发生车祸的具体时间进行二分答案
    {
        ll mid=(l+r)/2;
        if(check(mid))//在这个时间段还未发生过车祸
        {
            l=mid+1;
        }
        else
        {
            r=mid-1;
            ans=mid-1;
        }
    }
    cout<<ans<<endl;
    

    return 0;
}