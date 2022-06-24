#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
string s;
ll hor;ll ver;
void solve()
{
    cin>>n>>m>>s;
    hor=0;//水平方向
    ver=0;//竖直方向
    ll nowx=0,nowy=0;
    ll min_hor=0;ll max_hor=0;ll min_ver=0;ll max_ver=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='U') ver--;
        else if(s[i]=='D') ver++;
        else if(s[i]=='R') hor++;
        else if(s[i]=='L') hor--;
        min_hor=min(min_hor,hor);max_hor=max(max_hor,hor);
        min_ver=min(min_ver,ver);max_ver=max(max_ver,ver);
        //要预留一些空间给min_hor和min_ver
        if(-min_hor+max_hor<m&&-min_ver+max_ver<n)
        {
            nowx=-min_ver;
            nowy=-min_hor;
        }
        else break;
    }
    cout<<nowx+1<<" "<<nowy+1<<endl;
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