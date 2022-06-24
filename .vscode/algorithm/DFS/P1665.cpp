#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 505
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
pii p[MAXN];
int id[5];
int n;
int cnt=0;

int get(pii a,pii b)
{
    return (a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second);
}

bool check(pii a,pii b,pii c,pii d)
{
    int x[10];
    x[1]=get(a,b);
    x[2]=get(b,c);
    x[3]=get(c,d);
    x[4]=get(a,d);
    x[5]=get(a,c);
    x[6]=get(b,d);
    sort(x+1,x+7);
    if(x[1]==x[2]&&x[2]==x[3]&&x[3]==x[4]&&x[5]==(x[1]+x[2])&&x[6]==(x[2]+x[3])) return true;
    return false;
}

void dfs(int now,int pre)
{
    if(now==5)
    {
        //cout<<id[1]<<" "<<id[2]<<" "<<id[3]<<" "<<id[4]<<endl;
        bool flag=check(p[id[1]],p[id[2]],p[id[3]],p[id[4]]);
        if(flag) cnt++;
        return;
    }

    for(int i=pre+1;i<=n;i++)
    {
        id[now]=i;
        dfs(now+1,i);
        id[now]=0;
    }
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>p[i].first>>p[i].second;
    dfs(1,0);
    cout<<cnt<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}