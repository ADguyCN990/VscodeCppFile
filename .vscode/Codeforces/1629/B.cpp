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
    int l, r, k;
    l = read(), r = read(), k = read();
    int odd = 0;
    if (l == r)
    {
        if (l == 1)
        {
            puts("NO");
        }
        else
            puts("YES");
        return;
    }
    if (l & 1 && r & 1)
    {
        odd = r - l + 2 >> 1;
    }
    else
        odd = r - l + 1 >> 1;
    if (k >= odd) puts("YES");
    else puts("NO");
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