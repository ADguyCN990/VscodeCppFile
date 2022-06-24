#include<bits/stdc++.h>
using namespace std;


void solve()
{
    string s;
    cin>>s;
    stack <char> st;
    for(int i=0;i<s.length();i++)
    {
        if(st.empty()) 
        {
            st.push(s[i]);
            continue;
        }
        if(st.top()=='A'&&s[i]=='B') st.pop();
        else if(st.top()=='B'&&s[i]=='B') st.pop();
        else st.push(s[i]);
    }
    cout<<st.size()<<endl;
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