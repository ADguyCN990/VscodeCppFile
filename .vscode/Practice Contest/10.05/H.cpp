#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll T,n,m;
ll a[MAXN];//记录的是pos
ll b[MAXN];//记录的是val

ll get_sum(ll x,ll y)//从x到y的温度总和(x<=y)
{
    if(x>y) return 0;
    //处理时x可能小于0，实际上不会小于0，求和时要把少的这部分加上去。
    if(y<0) return 0;
    ll error=0;
    if(x<0) error=-x;
    error=(error+1)*error/2;//这就是少的那部分（如果x为负数）
    return (x+y)*(y-x+1)/2+error;
}

bool check()
{
    ll max_sum=0;ll min_sum=0;//和的最值
    ll top=0;ll bot=0;//温度的峰值
    for(int i=1;i<=m;i++)
    {
        max_sum+=b[i];
        min_sum+=b[i];
    }
    //处理开头的温度（位置<b[1]的部分）
    top=b[1]+a[1]-1;//可能的最高温度
    bot=b[1]-(a[1]-1);//可能的最低温度
    max_sum+=get_sum(b[1]+1,top);//计算最高温度和
    min_sum+=get_sum(bot,b[1]-1);//计算最低温度和

    //处理结尾的温度（位置>b[m]的部分）
    top=b[m]+(n-a[m]);//可能的最高温度
    bot=b[m]-(n-a[m]);//可能的最低温度
    max_sum+=get_sum(b[m]+1,top);//计算最高温度和
    min_sum+=get_sum(bot,b[m]-1);//计算最低温度和

    for(int i=1;i<m;i++)//处理中间部分的温度
    {
        ll d_pos=a[i+1]-a[i];//位置的差值
        ll d_val=abs(b[i+1]-b[i]);//温度差的绝对值
        ll minx=min(b[i],b[i+1]);ll maxx=max(b[i],b[i+1]);
        if(d_val>d_pos)//温度变化太快，直接非法
        {
            return false;
        }
        top=maxx+(d_pos-d_val)/2;//可能的温度最高值
        bot=minx-(d_pos-d_val)/2;//可能的温度最低值,这个值算出来可能小于0

        //累加时注意奇偶性 可能是1 2 3 3 2 1这种情况，也可能是1 2 1这种情况
        if(d_val%2==d_pos%2)//温度和得再减掉一个峰值
        {
            max_sum+=get_sum(maxx,top)+get_sum(minx,top)-max(0ll,top);
            min_sum+=get_sum(bot,minx)+get_sum(bot,maxx)-max(0ll,bot);
        }
        else
        {
            max_sum+=get_sum(maxx,top)+get_sum(minx,top);
            min_sum+=get_sum(bot,minx)+get_sum(bot,maxx);
        }

        max_sum-=(minx+maxx);//减掉重复计算的已知值
        min_sum-=(minx+maxx);//减掉重复计算的已知值
    }
    cout<<"min_sum: "<<min_sum<<" "<<"max_sum: "<<max_sum<<endl;
    if(T>=min_sum&&T<=max_sum) return true;
    else return false;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>T>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i]>>b[i];
    }
    if(check()==false) cout<<"No"<<endl;
    else cout<<"Yes"<<endl;
    return 0;
}