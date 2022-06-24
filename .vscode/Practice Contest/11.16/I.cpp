#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
ll n;
ll a[MAXN];
set <pii> s;
bool check()
{
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[i+1])
            return false;
    }
    return true;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        s.insert({a[i],-i});
    }
    for(int i=1;i<=n;i++)
    {
        auto x=*s.begin();
        if(x.first<a[i])//出现了逆序对
        {
            reverse(a+i,a+1-x.second);
            if(check())
                cout<<i<<" "<<-x.second<<endl;
            else
                cout<<"impossible"<<endl;
            return;
        }
        s.erase({a[i],-i});
    }
    cout<<1<<" "<<1<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();

    return 0;
}