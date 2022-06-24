#include<bits/stdc++.h>
using namespace std;
string s;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>s;
    set <char> ss;
    for(int i=0;i<s.length();i++)
    {
        ss.insert(s[i]);
    }
    if(ss.size()==1) cout<<-1<<endl;
    else cout<<2<<endl;
    return 0;
}