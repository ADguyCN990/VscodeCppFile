#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 400005
vector <int> a;
vector <int> b;
ll n;
int visit[MAXN];

int check1(int mid)//L 前n-mid和后n-mid做比较，想办法让L尽可能小,取max
{
    int pos=mid;
    for(int i=0;i<n-mid;i++)
    {
        if(b[i+pos]<a[i]) return 0;
    }
    return 1;
}

int check2(int mid)//R 后mid和前mid作比较，想办法让R尽可能大，取min
{
    int pos=n-mid;
    for(int i=0;i<mid;i++)
    {
        if(b[i]>a[i+pos]) return 0;
    }
    return 1;
}

void solve()
{
    a.clear();b.clear();
    cin>>n;
    int L=n;int R=n;
    int l=0;int r=n;
    for(int i=1;i<=2*n;i++) visit[i]=0;
    for(int i=1;i<=n;i++)
    {
        int tmp;
        cin>>tmp;
        visit[tmp]=1;
    }
    for(int i=1;i<=2*n;i++)
    {
        if(visit[i]==1) a.emplace_back(i);
        else b.emplace_back(i);
    }
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check1(mid)==1)
        {            
            r=mid-1;
            L=mid;
        }
        else
        {
            l=mid+1;
        }
    }
    l=0;r=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check2(mid)==1)
        {
            R=mid;
            l=mid+1;
        }
        else 
        {
            r=mid-1;
        }
    }
    //cout<<"L: "<<L<<" R: "<<R<<endl;
    cout<<R-L+1<<endl;
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