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
    s+=s;
    for(int i=1;i<=n;i++)
    {
        if(s.substr(0,i)<s.substr(i,i)) 
        {
            temp=s.substr(0,i);
            break;
        }
    }
    ll len=(ll)(temp.length());
    for(int i=1;i<=k/len;i++) cout<<temp;
    for(int i=0;i<k%len;i++) cout<<temp[i];

    return 0;
}