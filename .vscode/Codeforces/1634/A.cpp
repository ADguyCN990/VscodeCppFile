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
int n, k;
char s[MAXN];
void solve()
{
    n = read(), k = read();
    scanf("%s", s + 1);
    if (k == 0)
    {
        puts("1");
        return;
    }
    if (k == 1)
    {
        bool flag = true;
        for (int i = 1, j = n; i <= j; i ++, j --)
        {
            if (s[i] != s[j])
            {
                flag = false;
                break;
            }
        }
        if (!flag)
            puts("2");
        else
            puts("1");
        return;
    }
    bool flag = true;
    for (int i = 1, j = n; i <= j; i ++, j --)
    {
        if (s[i] != s[j])
        {
            flag = false;
            break;
        }
    }
    if (!flag)
        puts("2");
    else
        puts("1");
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