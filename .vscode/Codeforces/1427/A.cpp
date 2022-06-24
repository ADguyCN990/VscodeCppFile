#include<bits/stdc++.h>
using namespace std;
#define MAXN 55
int n;
int a[MAXN];
bool cmp(int a,int b) {return a>b;}

void solve()
{
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++) cin>>a[i],sum+=a[i];
    if(sum==0)
    {
        cout<<"NO"<<endl;
        return;
    }
    cout<<"YES"<<endl;
    if(sum<0) sort(a+1,a+1+n);
    else sort(a+1,a+1+n,cmp);
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