#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll a[MAXN];
ll t,n;
bool cmp(ll a,ll b){return a>b;}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n,cmp);
    //偶数Alice涨分，奇数Bob上分
    ll sum_a=0;ll sum_b=0;
    for(int i=1;i<=n;i++)
    {
        if(i%2==1)//Alice出手
        {
            if(a[i]%2==0) sum_a+=a[i];
        }
        else if(i%2==0)//Bob出手
        {
            if(a[i]%2==1) sum_b+=a[i];
        }
    }
    if(sum_a>sum_b) cout<<"Alice"<<endl;
    else if(sum_a==sum_b) cout<<"Tie"<<endl;
    else cout<<"Bob"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        solve();
    }

    return 0;
}