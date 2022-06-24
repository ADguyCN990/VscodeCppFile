#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve()
{
    string s;
    cin>>s;
    int dx1=0x3f3f3f3f;
    int dx2=0x3f3f3f3f;
    int dx3=0x3f3f3f3f;
    int dx4=0x3f3f3f3f;
    //00
    int f=0;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]=='0'&&f==0) f=1;
        else if(s[i]=='0'&&f==1) 
        {
            dx1=s.length()-1-i-1;
            break;
        }
    }
    //25
    f=0;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]=='5'&&f==0) f=1;
        else if(s[i]=='2'&&f==1) 
        {
            dx2=s.length()-1-i-1;
            break;
        }
    }
    //50
    f=0;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]=='0'&&f==0) f=1;
        else if(s[i]=='5'&&f==1) 
        {
            dx3=s.length()-1-i-1;
            break;
        }
    }
    //75
    f=0;
    for(int i=s.length()-1;i>=0;i--)
    {
        if(s[i]=='5'&&f==0) f=1;
        else if(s[i]=='7'&&f==1) 
        {
            dx4=s.length()-1-i-1;
            break;
        }
    }
    //cout<<dx1<<" "<<dx2<<" "<<dx3<<" "<<dx4<<endl;
    cout<<min({dx1,dx2,dx3,dx4})<<endl;
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