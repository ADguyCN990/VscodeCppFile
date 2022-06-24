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
char s[MAXN];
int cnt0, cnt1;
void solve()
{
    cnt0 = 0, cnt1 = 0;
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    for (int i = 1; i <= len ; i ++)
    {
        if (s[i] == '0') cnt0 ++;
        else cnt1 ++;
    }
    if (cnt0 == cnt1 && len == 2)
    {
        puts("0");
        return;
    }
    else if (cnt0 == cnt1)
    {
        printf("%d\n", cnt1 - 1);
        return;
    }
    printf("%d\n", min(cnt0, cnt1));
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