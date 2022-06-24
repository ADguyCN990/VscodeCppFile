#include<bits/stdc++.h>
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
char s[MAXN];

bool check(int l, int n)
{
    for (int i = l, j = n; i <= j; i ++, j --)
    {
        if (s[i] != s[j]) return false;
    }
    return true;
}

void solve()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1);
    bool flag = check(1, n);
    if (flag)
    {
        puts("Yes");
        return;
    }
    int cnt = 0;
    while (s[n] == 'a') n --, cnt ++;
    int l = 1;
    while (s[l] == 'a') l ++;
    if (l > cnt)
    {
        puts("No");
        return;
    }
    flag = check(l, n);
    if (flag)
    {
        puts("Yes");
        return;
    }
    puts("No");
}

int main()
{
    solve();
    return 0;
}