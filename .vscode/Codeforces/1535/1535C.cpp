#include<bits/stdc++.h>
using namespace std;
int t;
string s;
#define ll long long
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>s;
        ll temp=0;//连续问号的个数
        ll ans=0;
        ll temp_val=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]!='?')
            {
                if(s[i]==s[i-1]) temp_val=temp;//之前一个原先是问号，连接前面了的后面的连接不上了，
                temp=0;
            }
            else if(s[i]=='?')
            {
                if(s[i-1]=='1') s[i]='0';
                else s[i]='1';
                temp++; 
            }
            temp_val++;
            ans+=temp_val;
        }
        cout<<ans<<endl;
    }

    return 0;
}

