#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
string s,t;
ll n;
void solve()
{
    cin>>n;
    cin>>s>>t;
    int cnt=0;//s>t的个数
    int cnt2=0;//t>s的个数
    for(int i=0;i<n;i++)
    {
        if(s[i]>t[i]) cnt++;
        else if(s[i]<t[i]) cnt2++;
    }
    if(cnt>cnt2) cout<<"RED"<<endl;
    else if(cnt==cnt2) cout<<"EQUAL"<<endl;
    else cout<<"BLUE"<<endl;
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