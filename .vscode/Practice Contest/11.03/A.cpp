#include<bits/stdc++.h>
using namespace std;
#define ll long long
map <string,int> mp;

void pre()
{
    mp["C"]=1;
    mp["C#"]=2;
    mp["D"]=3;
    mp["D#"]=4;
    mp["E"]=5;
    mp["F"]=6;
    mp["F#"]=7;
    mp["G"]=8;
    mp["G#"]=9;
    mp["A"]=10;
    mp["A#"]=11;
    mp["B"]=12;
}

void solve()
{
    string x,y,z;
    cin>>x>>y>>z;
    int a=mp[x];int b=mp[y];int c=mp[z];
    if(a>b) b+=12;
    if(b>c) c+=12;
    if(b-a==4&&c-b==3) cout<<"Major triad"<<endl;
    else if(b-a==3&&c-b==4) cout<<"Minor triad"<<endl;
    else cout<<"Dissonance"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    pre();
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}