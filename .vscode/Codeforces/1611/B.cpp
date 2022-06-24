#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f

void solve()
{
    ll a,b;
    cin>>a>>b;
    if(a>b) swap(a,b);
    ll sum=a+b;
    ll dx=b-a;
    if(dx/2>=a)
    {
        cout<<a<<endl;
        return;
    }
    cout<<sum/4<<endl;
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