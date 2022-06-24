#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int d[6]={1,-1,5,-5,10,-10};
int vis[105];

int bfs(int a,int b)
{
    int cnt=0;
    queue <pair<int,int>> q;
    q.push({a,0});
    vis[a]=1;
    while(q.size())
    {
        int x=q.front().first,num=q.front().second;q.pop();
        cnt++;
        if(x==b) return num;
        for(int i=0;i<6;i++)
        {
            int now=x+d[i];
            if(now<0||now>40) continue;
            if(vis[now]) continue;
            vis[now]=1;
            q.push({now,num+1});
        }
    }
    
}

void solve()
{
    int a,b;
    cin>>a>>b;
    cout<<bfs(a,b)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}