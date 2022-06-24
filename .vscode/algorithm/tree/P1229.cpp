#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s,t;
void solve()
{
    cin>>s>>t;
    int n=s.length();
    int ans=0;
    for(int i=0;i<n;i++)//这是前序
    {
        for(int j=1;j<n;j++)//这是后序
        {
            //当且仅当只有一个儿子时会出现错误
            if(s[i]==t[j]&&s[i+1]==t[j-1]) ans++;
        }
    }
    cout<<(1<<ans)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}