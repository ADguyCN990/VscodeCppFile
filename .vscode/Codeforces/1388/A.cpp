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
int n;
void solve()
{
    n = read();
    if (n >= 31)
    {
        puts("YES");
        if (n - 30 == 6)
            puts("6 10 15 5");
        else if (n - 30 == 10)
            puts("6 10 15 9");
        else if (n - 30 == 14)
            puts("6 10 7 21");
        else
            printf("6 10 14 %d\n", n - 30);
    }
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