#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
ll n;
ll a[MAXN];
int f[MAXN];
int check1(int i)//是否为波峰
{   
    if(i>1&&i<n&&a[i]>a[i-1]&&a[i]>a[i+1]) return 1;
    return 0;
}
int check2(int i)//是否为波谷
{
    if (i>1&&i<n&&a[i]<a[i-1]&&a[i]<a[i+1]) return 1;
    return 0;
}
void solve()
{
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) f[i]=0;
    for(int i=2;i<n;i++) 
    {
        if(check1(i)||check2(i)) f[i]=1;
        else f[i]=0;
        sum+=f[i];
    }
    int tmp_sum=sum;
    for(int i=2;i<n;i++)
    {
        int tmp=a[i];
        a[i]=a[i-1];
        tmp_sum=min(tmp_sum,sum-f[i-1]-f[i]-f[i+1]+check1(i-1)+check1(i)+check1(i+1)+check2(i-1)+check2(i)+check2(i+1));
        a[i]=a[i+1];
        tmp_sum=min(tmp_sum,sum-f[i-1]-f[i]-f[i+1]+check1(i-1)+check1(i)+check1(i+1)+check2(i-1)+check2(i)+check2(i+1));
        a[i]=tmp;
        //cout<<"!!! "<<sum<<endl;
    }
    cout<<tmp_sum<<endl;
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