#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
ll a[MAXN];
ll n;
int visit[MAXN];
    //向上取整
    //要改变的有3,4,5，... ，n,以n=200000为例
    //碰到141 除 a[n]变成142  141除142变成1
    //碰到12 除 a[n]变成12    12除12变成1
    //碰到3 除 a[n] 变成4     3除4变成1
    //4再连续除以两次2变成1
void solve()
{
    cin>>n;
    if(n<=2)
    {
        cout<<0<<endl;
        return;
    }
    for(int i=1;i<=n;i++) visit[i]=0;
    ll tmp=n;
    ll cnt=n-3;//除了1,2，n以外的所有数都和n碰一下变成1
    while(tmp>2)
    {
        if(int(sqrt(tmp))*int(sqrt(tmp))==tmp)
        {
            visit[int(sqrt(tmp))]=1;//这个数要开平方根，进行后续的操作
            tmp=(int)(sqrt(tmp));
        }
        else
        {
            visit[(int)(sqrt(tmp)+1)]=1;
            tmp=(int)(sqrt(tmp))+1;
        }
        cnt++;
    }
    cnt++;//最后n还得除以2才能变成1
    cout<<cnt<<endl;
    for(int i=3;i<n;i++)
    {
        if(visit[i]==0) cout<<i<<" "<<n<<endl;
    }
    tmp=n;//开始进行sqrt操作
    while(tmp>2)
    {
        if(int(sqrt(tmp))*(int)(sqrt(tmp))==tmp)
            tmp=(int)(sqrt(tmp));
        else
            tmp=(int)(sqrt(tmp))+1;
        cout<<n<<" "<<tmp<<endl;
        if(tmp==2)//最后一次操作
        {
            cout<<n<<" "<<tmp<<endl;
        }
        else
        cout<<tmp<<" "<<n<<endl;//两次操作把n变成tmp，tmp变成1
        
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}