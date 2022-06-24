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
const int N=1000000;
int prime[N+5];
void getprime()
{
    for(int i=2;i<=N;i++)
    {
        if(!prime[i])
            prime[++prime[0]]=i;
        for(int j=1;j<=prime[0]&&prime[j]<=N/i;j++)
        {
            prime[prime[j]*i]=1;
            if(i%prime[j]==0)
                break;
        }
    }
}

bool check(int n)
{
    for (int i = 2; i * i <= n; i ++)
    {
        if (n % i == 0) return false;
    }
    return true;
}

ll n;

void solve()
{
    n = read();
    if (n == 1)
    {
        puts("-1");
        return;
    }
    ll tmp = 1;
    for (int i = 1; ; i ++)
    {
        if (tmp * prime[i] <= n) 
            tmp = tmp * prime[i];
        else
            break;
    }
    printf("%lld ", tmp);
    for (int i = n; i >= 2; i --)
    {
        if (check(i))
        {
            printf("%d\n", i);
            return;
        }
    }
}

int main()
{
    int T;
    getprime();
    T=read();
    while(T--)
    {
        solve();
    }

    return 0;
}