#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll n;
ll a[MAXN];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    priority_queue<int,vector<int>,greater<int>> q;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
        q.push(a[i]);
        while(sum<0)
        {
            sum-=q.top();
            q.pop();
        }
    }   
    cout<<q.size()<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}