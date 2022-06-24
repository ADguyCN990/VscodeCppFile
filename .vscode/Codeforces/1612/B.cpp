#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n,a,b;
int vis[105];
//左边的一半排列最小的是a，右边的一半排列最大的是b
void solve()
{
    cin>>n>>a>>b;
    vector <int> v;
    memset(vis,0,sizeof(vis));
    v.emplace_back(a),vis[a]=1;
    for(int i=n,cnt=1;i>0&&cnt<=n/2;i--,cnt++)
    {
        if(i!=b&&i!=a) 
        {
            v.emplace_back(i);
            vis[i]=1;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
            v.emplace_back(i);
    }
    for(int i=0;i<n/2;i++)
    {
        if(v[i]<a)
        {
            cout<<-1<<endl;
            return;
        }
    }
    for(int i=n/2;i<n;i++)
    {
        if(v[i]>b)
        {
            cout<<-1<<endl;
            return;
        }
    }
    for(auto x:v)
        cout<<x<<" ";
    cout<<endl;
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