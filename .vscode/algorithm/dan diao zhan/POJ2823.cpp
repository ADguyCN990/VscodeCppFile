#include<stdio.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define MAXN 1000005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define pb emplace_back
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int n,k;
int a[MAXN];
int q[MAXN],hh=1,tt;
void solve()
{
    n=read(),k=read();
    rep(i,1,n) a[i]=read();
    //求最小
    rep(i,1,n)
    {
        while(hh<=tt&&a[i]<=a[q[tt]]) tt--;
        q[++tt]=i;
        if(i-k>=q[hh]) hh++;
        if(i>=k) printf("%d ",a[q[hh]]);
    }
    puts("");
    hh=1,tt=0;
    rep(i,1,n)
    {
        while(hh<=tt&&a[i]>=a[q[tt]]) tt--;
        q[++tt]=i;
        if(i-k>=q[hh]) hh++;
        if(i>=k) printf("%d ",a[q[hh]]);
    }
}

int main()
{
    solve();
    return 0;
}