#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
bool cmp(ll a,ll b) {return a>b;}
void solve()
{
    ll n,x;
    ll sum=0;
    ll a[MAXN];
    cin>>n>>x;
    //值达到x后直接爆炸
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum==x)
    {
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
    int f=0;
    sort(a+1,a+1+n,cmp);
    sum=0;
    for(int i=1;i<=n;i++)
    {
        if(sum+a[i]<x) sum+=a[i];
        else if(sum+a[i]>x) break;
        else if(sum+a[i]==x)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(a[i]!=a[j]) 
                {
                    swap(a[i],a[j]);
                    sum+=a[i];
                    break;
                }
            }
        }
    }
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
    
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