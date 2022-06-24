#include<bits/stdc++.h>
using namespace std;
string s;
int t,n;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>s;
        int cnt=0;
        for(int i=0;i<s.length();i++) if(s[i]=='0') cnt++;
        if(cnt==1) cout<<"BOB"<<endl;
        else if(cnt%2==1) cout<<"ALICE"<<endl;
        else cout<<"BOB"<<endl;
    }

    return 0;
}