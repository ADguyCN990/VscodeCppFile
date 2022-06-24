#include<bits/stdc++.h>
using namespace std;
#define ll long long 
string s;
ll n,k;//当前长度为n，要求通过两种操作变出一个长度为k的字典序最小的字符串

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>k>>s;
    string temp=s;
    ll cnt=1;
    for(int i=0;i<n;i++)
    {
        if(s[i]>s[i%cnt]) break;
        else if(s[i]<s[i%cnt]) cnt=i+1;
    }
    for(int i=0;i<k;i++) cout<<s[i%cnt];
    return 0;
}