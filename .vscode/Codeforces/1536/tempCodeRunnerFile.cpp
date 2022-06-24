#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
ll t,n;
string s;
string ans;
void solve()
{
    queue <string> q;
    for(int i=0;i<26;i++)
    {
        char temp=('a'+i);
        string tmp=temp+"";
        q.push(tmp);
    }
    while(!q.empty())
    {
        string x=q.front();
        q.pop();
        if(s.find(x)==-1)
        {
            ans=x;
            return;
        }
        for(int i=0;i<26;i++)
        {
            x.push_back('a'+i);
            q.push(x);
            x.pop_back();
        }
    }

}
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        cin>>s;
        ans="";
        solve();
        cout<<ans<<endl;
    }
    return 0;
}