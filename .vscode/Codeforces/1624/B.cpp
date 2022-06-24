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
ll a, b, c;
bool check(ll a, ll b, ll c)
{
    ll mid = a + c >> 1;
    if (mid % b == 0 && (a + c) % 2 == 0)
        return true;
    if (b > c)
    {
        mid = b + b - c;
        if (mid % a == 0)
            return true;
    }
    else
    {
        mid = b - (c - b);
        if (mid % a == 0 && mid > 0)
            return true;
    }
    if (b > a)
    {
        mid = b + b - a;
        if (mid % c == 0)
            return true;
    }
    else
    {
        mid = b - (a - b);
        if (mid % c == 0 && mid > 0)
            return true;
    }
    return false;
}

void solve()
{
    
    a = read(), b = read(), c = read();
    bool flag1 = check(a, b, c);
    if (flag1 )
        puts("YES");
    else 
        puts("NO");
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