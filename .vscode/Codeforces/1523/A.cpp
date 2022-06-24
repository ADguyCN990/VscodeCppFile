#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 2005
ll t,n,m;
void solve()
{
    cin>>n>>m;
    string s;
    cin>>s;
    s='0'+s;
    int i;
    int cnt=0;
    for(int i=1;i<=n;i++) if(s[i]=='1') cnt++;
    for(i=n;i>=1;i--)
    {
        if(s[i]=='1') break;
    }
    if(i!=0)
    for(int temp=1;temp<=m&&i+temp<=n;temp++) s[i+temp]='1';
    for(i=1;i<=n;i++)
    {
        if(s[i]=='1')  break;
    }
    if(i<=n)
    for(int temp=1;temp<=m&&i-temp>0;temp++) s[i-temp]='1';
    while(i<=n&&cnt>1)
    {
        int j=i+1;
        for(j=i+1;s[j]=='0';j++) {}
        ll dx=j-i-1;
        if(dx/2<=0)//一个数都不变
        {
            i=j;
            continue;
        }
        else if(dx/2>0&&dx/2<=m)
        {
            for(int k=1;k<=dx/2;k++)
            {
                s[i+k]='1';s[j-k]='1';
            }
            i=j;
            continue;
        }
        else if(dx/2>m)
        {
            for(int k=1;k<=m;k++)
            {
                s[i+k]='1';s[j-k]='1';
            }
            i=j;
            continue;
        }
    }

    cout<<s.substr(1,n)<<endl;
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        solve();   
    }


    return 0;
}