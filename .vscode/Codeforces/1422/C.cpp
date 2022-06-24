#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define mod 1000000007
#define INF 0x3f3f3f3f
char s[MAXN];
int a[MAXN];
ll dp[MAXN];

void solve()
{
    cin>>s+1;
    dp[0]=0;
    int n=strlen(s+1);
    for(int i=1;i<=n;i++) a[i]=s[i]-'0';
    
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}