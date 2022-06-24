#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200*200+5
int f[MAXN];
int n,m;

int findx(int x)
{
    if(x==f[x]) return x;
    else return f[x]=findx(f[x]);
}



int get(int x,int y)
{
    return (x-1)*n+y;
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=n*n;i++) f[i]=i;
    for(int i=1;i<=m;i++)
    {
        int u,v;
        char c;
        cin>>u>>v>>c;
        if(c=='D')
        {
            int fx=findx(get(u,v));
            int fy=findx(get(u+1,v));
            if(fx==fy)
            {
                cout<<i<<endl;
                return;
            }
            else
                f[fy]=fx;
        }
        else if(c=='R')
        {
            int fx=findx(get(u,v));
            int fy=findx(get(u,v+1));
            if(fx==fy)
            {
                cout<<i<<endl;
                return;
            }
            else 
                f[fy]=fx;
        }
    }
    cout<<"draw"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}