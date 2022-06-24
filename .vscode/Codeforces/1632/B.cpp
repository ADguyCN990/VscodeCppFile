#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
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
void solve()
{
    int n;
    n = read();
    n --;
    int mx = 0;
    for (int i = 31; i >= 0; i --)
    {
        int u = 1 << i;
        if (u & n) 
        {
            mx = u;
            break;
        }
    }
    for (int i = n; i >= 1; i --)
    {
        printf("%d ", i);
        if (i == mx) printf("0 ");
    }
    puts("");
}

int main()
{
    int T;
    T=read();
    while(T--)
    {
        solve();
    }

    return 0;
}