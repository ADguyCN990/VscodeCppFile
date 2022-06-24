#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll n,m;
ll a[MAXN];

void solve()
{
    cin>>n>>m;
    double ans=1;
    int pos=0;//分界线，pos右边都是排好序后的排列
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i!=a[i]) pos=i;
    }
    int k;double p;
    for(int i=1;i<=m;i++)
    {
        cin>>k>>p;//有p的概率[1,k]能排序
        if(k>=pos) ans*=(1-p);//只有k后的数全部都没排列才有可能出现非法情况
    }
    if(pos==0)//原本已经完成排序
    {
        cout<<1<<endl;
        return;
    }
    cout<<1-ans<<endl;
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