#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
int n,m;
int a[MAXN];
int c[MAXN];

int lowbit(int x) {return x&-x;}

int ask(int x)
{
    int sum=0;
    for(int i=x;i;i-=lowbit(i)) sum+=c[i];
    return sum;
}

void add(int x,int k)
{
    for(int i=x;i<=n;i+=lowbit(i)) c[i]+=k;
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>c[i];
    for(int i=1;i<=n;i++) a[i]=c[i]-c[i-1];
    memset(c,0,sizeof c);
    for(int i=1;i<=n;i++) add(i,a[i]);
    while(m--)
    {
        char c;
        cin>>c;
        if(c=='Q')
        {
            int x;
            cin>>x;
            cout<<ask(x)<<endl;
        }
        else
        {
            int l,r,k;
            cin>>l>>r>>k;
            add(l,k),add(r+1,-k);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}