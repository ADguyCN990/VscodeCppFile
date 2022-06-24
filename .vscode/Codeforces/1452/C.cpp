#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
char s[MAXN];
void solve()
{
    cin>>s+1;
    int n=strlen(s+1);
    int ans=0;
    int cnt1=0;int cnt2=0;
    for(int i=1;i<=n;i++)
    {
        if(s[i]=='(') cnt1++;
        else if(s[i]=='[') cnt2++;
        else if(s[i]==')')
        {
            if(cnt1>0)
            {
                cnt1--;
                ans++;
            }
        }
        else if(s[i]==']')
        {
            if(cnt2>0)
            {
                cnt2--;
                ans++;
            }
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}