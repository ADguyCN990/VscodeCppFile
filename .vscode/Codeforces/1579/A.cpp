#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t;
string s;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>s;
        int a=0;int b=0;int c=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='A') a++;
            else if(s[i]=='B') b++;
            else if(s[i]=='C') c++;
        }
        if(b==a+c) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

    return 0;
}