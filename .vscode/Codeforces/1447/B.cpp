#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 15
ll n,m;
ll mp[MAXN][MAXN];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int cnt=0;//负数的个数
int f=0;
ll ans;

bool ok(int x,int y)
{
    if(x>n||x<1||y>m||y<1) return false;
    return true;
}

void work(int x,int y)
{
    for(int i=0;i<4;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(ok(xx,yy)&&mp[xx][yy]<0&&mp[x][y]<0)
        {
            mp[xx][yy]=-mp[xx][yy];
            mp[x][y]=-mp[x][y];
            cnt-=2;
            return;
        }
    }
}

void solve()
{
    vector <ll> v;
    cin>>n>>m;
    cnt=0;f=0;ans=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>mp[i][j];
            if(mp[i][j]==0) f=1;
            if(mp[i][j]<0) cnt++;
            ans+=abs(mp[i][j]);
            v.emplace_back(abs(mp[i][j]));
        }
    }
    if(f==1)
    {       
        cout<<ans<<endl;
        return;  
    }
    sort(v.begin(),v.end());
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            work(i,j);
    //cout<<"cnt: "<<cnt<<endl;
    ans-=(cnt%2)*v[0]*2;
    cout<<ans<<endl;   
    
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