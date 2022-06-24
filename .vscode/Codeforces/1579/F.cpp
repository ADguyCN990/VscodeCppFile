#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
int a[MAXN];
int t,n,d;
ll ans;
//pair<当前轮数，当前元素下标>
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>> q;//优先队列，小的先出队
        cin>>n>>d;
        ans=0;
        for(int i=0;i<n;i++) 
        {
            cin>>a[i];
            if(a[i]==0) q.push(make_pair(0,i));
        }
        while(!q.empty())
        {
            pair<ll,ll> x=q.top();q.pop();
            ll now=x.second;
            ll step=x.first;
            ll next=(now+d)%n;
            if(a[next]==0) continue;
            else
            {
                a[next]=0;
                ans=max(ans,step+1);
                q.push(make_pair(step+1,next));
            }
        }
        int ok=1;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=0) 
            {
                ok=0;
                break;
            }
        }
        if(ok) cout<<ans<<endl;
        else
        cout<<-1<<endl;
    }
    return 0;
}