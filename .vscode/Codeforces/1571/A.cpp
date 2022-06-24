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
void solve()
{
    scanf("%s",s+1);
    int len=strlen(s+1);
    int cnt1=0,cnt2=0,cnt3=0;
    for(int i=1;i<=len;i++)
    {
        if(s[i]=='<') cnt1++;
        else if(s[i]=='=') cnt2++;
        else cnt3++;
    }
    if(cnt2&&!cnt1&&!cnt3)
    {
        puts("=");
    }
    else if(cnt1&&!cnt3)
    {
        puts("<");
    }
    else if(cnt3&&!cnt1)
    {
        puts(">");
    }
    else puts("?");
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