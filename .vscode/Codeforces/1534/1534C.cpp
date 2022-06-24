#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define MAXN 400005
int visit[MAXN];//有没有拜访过这组数据
ll a[MAXN];
ll b[MAXN];
ll pos[MAXN];//根据a[i]的值找到其所在的位置
ll cnt=0,start;//统计环的个数，记录环的起点
ll t,n;
void dfs(int now)//now是当前遍历的a数组的值
{
    visit[pos[now]]=1;
    if(b[pos[now]]==start)
    {
        cnt++;
        return;
    }
    int now_pos=pos[now];//当前所在的位置
    dfs(b[now_pos]);
}
ll quickpow(ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n%2==1)
        {
            ans=(ans*a)%mod;
            n--;
        }
        else if(n%2==0)
        {
            a=(a*a)%mod;
            n/=2;
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        cnt=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++)
        {
            cin>>b[i];
            pos[a[i]]=i;
            visit[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            if(visit[i]==0)
            {
                start=a[i];
                dfs(a[i]);
            }
        }
        cout<<quickpow(2,cnt)<<endl;
    }
    return 0;
}

