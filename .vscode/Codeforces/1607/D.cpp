#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
string s;
ll a[MAXN];
ll n;
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    cin>>s;
    int b=0;//红色r是只能加，蓝色b是只能减
    //蓝色放最下面，红色放最上面
    vector <int> v;
    vector <int> pos;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='R') 
        {
            v.emplace_back(a[i+1]);
        }
        else if(s[i]=='B') 
        {
            pos.emplace_back(a[i+1]);
            b++;
        }
    }
    sort(v.begin(),v.end());
    sort(pos.begin(),pos.end());
    for(int i=0;i<pos.size();i++)
    {
        int now=i+1;
        if(pos[i]<now)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    for(int i=0;i<v.size();i++)
    {
        int now=b+i+1;
        if(v[i]>now)
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
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