#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t;
int n;
void solve()
{
    cin>>n;
    if(n%11==0)
    {
        cout<<"Yes"<<endl;
        return;
    }
    while(n>=0)
    {
        if(n%11==0)
        {
            cout<<"Yes"<<endl;
            return;
        }
        n-=111;
    }
    cout<<"No"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        solve();
    }
    return 0;
}