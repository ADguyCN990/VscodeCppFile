#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
char s[MAXN];
void solve()
{
    int n;
    cin>>n;
    cin>>s+1;
    int cnt0=0;int cnt1=0;
    for(int i=1;i<n;i++)
    {
        if(s[i]=='1'&&s[i+1]=='1')
            cnt1++;
        else if(s[i]=='0'&&s[i+1]=='0')
            cnt0++;
    }
    cout<<max(cnt1,cnt0)<<'\n';
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