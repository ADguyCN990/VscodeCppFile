#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    string s;
    cin>>s;
    int len=s.length();
    for(int i=1;i<=4-len;i++) s='0'+s;
    cout<<s<<endl;
    return 0;
}