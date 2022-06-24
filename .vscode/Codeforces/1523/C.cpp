#include<bits/stdc++.h>
using namespace std;
#define MAXN 1005
#define ll long long

void solve()
{
    ll n;
    cin>>n;
    vector <int> v;
    for(int i=1;i<=n;i++)
    {
        int temp;
        cin>>temp;
        if(temp>1)
        {
            while(!v.empty()&&v.back()+1!=temp)
            {
                v.pop_back();
            }
            v.pop_back();
        }   
        v.emplace_back(temp);
        for(int j=1;j<=v.size();j++)
        {
            cout<<v[j-1];
            if(j!=v.size()) cout<<".";
        }
        cout<<endl;
    }
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
