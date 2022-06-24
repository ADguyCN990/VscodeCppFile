#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll t,n;
#define MAXN 200005
ll a[MAXN];

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        deque <ll> q;
        for(int i=1;i<=n;i++)
        {
            if(i==1||a[i]<q.front()) q.push_front(a[i]);
            else q.push_back(a[i]);
        }
        for(int i=1;i<=n;i++)
        {
            ll ans=q.front();
            q.pop_front();
            cout<<ans<<" ";
        }
        cout<<endl;
    } 
    return 0;
}