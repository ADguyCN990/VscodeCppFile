#include<bits/stdc++.h>
using namespace std;
string s;
int n,q;
#define MAXN 100005
#define ll long long
ll sum[MAXN];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>q;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        ll temp=(ll)(s[i]-'a'+1);
        sum[i+1]=sum[i]+temp;
    }
    while(q--)
    {
       int l,r;
       cin>>l>>r;
       cout<<sum[r]-sum[l-1]<<endl;
    }
    return 0;
}