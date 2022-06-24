#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
ll a[MAXN];
ll n;
int visit[MAXN];
    //向上取整
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
            visit[int(sqrt(tmp))]=1;//这个数要开平方
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
        cout<<n<<" "<<tmp<<endl;//把n碰成1
        n=tmp;//现在n变成了1，tmp继承了n的意志变成了新的BOSS
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