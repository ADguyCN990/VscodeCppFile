#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
char s[MAXN];
ll n,q,l,r;
ll sum1[MAXN];
ll sum0[MAXN];
void solve()
{
    cin>>n>>q;
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
    {
        sum1[i]=0;
        sum0[i]=0;
    }
    for(int i=1;i<=n;i++)
    {
        sum1[i]=sum1[i-1];
        sum0[i]=sum0[i-1];
        if(s[i]=='1') sum1[i]++;
        else if(s[i]=='0') sum0[i]++;
    }
    
    while(q--)
    {
        cin>>l>>r;
        int cnt_l=0;int cnt_r=0;
        if(s[l]=='0') cnt_l=sum0[l-1];
        else cnt_l=sum1[l-1];
        if(s[r]=='1') cnt_r=sum1[n]-sum1[r];
        else cnt_r=sum0[n]-sum0[r];
        if(cnt_l==0&&cnt_r==0)
        {
            cout<<"NO"<<endl;
        }
        else
            cout<<"YES"<<endl;
    }
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