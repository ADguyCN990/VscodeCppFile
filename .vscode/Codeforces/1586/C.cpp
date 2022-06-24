#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
ll n,m,q;
string s[MAXN];
ll fail[MAXN];
void init()
{
    for(int i=0;i<=m;i++) 
    {
        fail[i]=0;
    }
}
void solve()
{
    cin>>n>>m;
    init();
    for(int i=1;i<=n;i++)
    {
        string temp;
        cin>>temp;
        s[i]="#"+temp;
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(s[i+1][j]=='X'&&s[i][j+1]=='X')
            {
                fail[j]++;
            }
        }
    }
    for(int i=2;i<=m;i++)
    {
        fail[i]=fail[i]+fail[i-1];
       // cout<<i<<" : "<<fail[i]<<endl;
    }
    cin>>q;
    while(q--)
    {
        int l,r;
        cin>>l>>r;
        if(fail[r-1]-fail[l-1]==0) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //int T;
    //cin>>T;
    //while(T--)
    //{
        solve();
    //}
    return 0;
}