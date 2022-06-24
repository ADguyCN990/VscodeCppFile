#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
int n;
int a[MAXN];
int c[MAXN];
int small[MAXN],big[MAXN];

int lowbit(int x) {return x&(-x);}

void add(int x,int k)
{
    for(int i=x;i<=n;i+=lowbit(i)) c[i]+=k;
}

int ask(int x)
{
    int sum=0;
    for(int i=x;i;i-=lowbit(i))
    {
        sum+=c[i];
    }
    return sum;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        int y=a[i];
        small[i]=ask(y-1);
        big[i]=ask(n)-ask(y);
        add(y,1);
    }
    memset(c,0,sizeof c);
    ll ans1=0,ans2=0;
    for(int i=n;i>=1;i--)
    {
        int y=a[i];
        ll tmp1=ask(y-1);
        ll tmp2=ask(n)-ask(y);
        ans1+=small[i]*tmp1;
        ans2+=big[i]*tmp2;
        add(y,1);
    }  
    cout<<ans1<<" "<<ans2<<endl; 
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}