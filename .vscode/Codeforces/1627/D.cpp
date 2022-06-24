#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000000
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
ll gcd(ll a,ll b)
{
    if(a<b) swap(a,b);
    ll tmp;
    while(b)
    {
       tmp=b;
       b=a%b;
       a=tmp; 
    }
    return a;
}
int n;
int a[MAXN + 5];
int cnt[MAXN + 5];
void solve()
{
    n = read();
    int mx = 0;
    vector <int> ans;
    for (int i = 1; i <= n; i ++) a[i] = read(), cnt[a[i]] ++, mx = max(mx, a[i]);
    for (int i = 1; i <= mx; i ++)
    {
        int tmp = 0;
        for (int j = i; j <= mx; j += i)
        {
            if (cnt[j]) tmp = gcd(tmp, j);
        }
        if (tmp == i) ans.pb(i);
    }
    //for (int x : ans) printf("%d ", x);
    int len = ans.size();
    printf("%d\n", len - n);
}

int main()
{
    solve();
    return 0;
}