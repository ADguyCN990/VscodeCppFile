#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
char s[MAXN];
int visit[MAXN];
ll n;
//更改字符串任意位置上的字符，问最少几次操作能使这个字符串不包含回文
void solve()
{
    scanf("%s",s+1);
    int n=strlen(s+1);
    ll ans=0;
    for(int i=1;i<=n;i++) visit[i]=0;
    for(int i=2;i<=n;i++)
    {
        if(s[i]==s[i-1]&&visit[i-1]==0)
        {
            visit[i]=1;
            ans++;
            //i++;
        }
        else if(i>2&&s[i-2]==s[i]&&visit[i-2]==0)
        {
            visit[i]=1;
            ans++;
            //i+=2;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}