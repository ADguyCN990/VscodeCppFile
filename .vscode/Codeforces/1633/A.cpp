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

int check(int n, int i)
{
    string a = to_string(n);
    string b =to_string(i);
    int num = 0;
    for (int i = 0; i < a.length(); i ++)
    {
        if (a[i] == b[i]) num ++;
    }
    return num;
}

void solve()
{
    int n;
    n = read();
    if (n % 7 == 0)
    {
        printf("%d\n", n);
        return;
    }
    int ans;
    int mn = -1;
    if (n < 100)
    {
        for (int i = 10; i < 100; i ++)
        {
            int tmp = check(n, i);
            if (tmp > mn && i % 7 == 0)
            {
                mn = tmp;
                ans = i;
            }
        }
    }
    else
    {
        for (int i = 100 ; i <= 999; i ++)
        {
            int tmp = check(n, i);
            if (tmp > mn && i % 7 == 0)
            {
                mn = tmp;
                ans = i;
            }
        }
    }
    printf("%d\n", ans);
}

int main()
{
    int T;
    T = read();
    while(T--)
    {
        solve();
    }

    return 0;
}