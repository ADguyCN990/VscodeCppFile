#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 5005
int a[5005];
ll z,f,sum1,sum2;//正数，负数，Alice，Bob
ll n;
bool cmp(int a,int b){return a>b;}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]>0) z+=a[i];
        else if(a[i]<0) f+=a[i];
    }
    if(z>-f)
    {
        sort(a+1,a+1+n,cmp);
    }
    else sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
    {
        if(i&1==1) sum1+=a[i];
        else sum2+=a[i];
    }
    if(z>-f) cout<<sum1-sum2<<endl;
    else cout<<sum2-sum1<<endl;

    return 0;
}