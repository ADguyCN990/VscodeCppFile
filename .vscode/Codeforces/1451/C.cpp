#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll n,k;
string a,b;
int cnta[30];
int cntb[30];

void solve()
{
    cin>>n>>k;
    cin>>a>>b;
    memset(cnta,0,sizeof(cnta));
    memset(cntb,0,sizeof(cntb));
    for(int i=0;i<a.length();i++) cnta[a[i]-'a']++;
    for(int i=0;i<b.length();i++) cntb[b[i]-'a']++;
    for(int i=0;i<26;i++)
    {
        if(cnta[i]<cntb[i]||(cnta[i]-cntb[i])%k!=0)
        {
            cout<<"NO"<<endl;
            return;
        }
        cnta[i]-=cntb[i];
        cnta[i+1]+=cnta[i];
    }
    cout<<"YES"<<endl;
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