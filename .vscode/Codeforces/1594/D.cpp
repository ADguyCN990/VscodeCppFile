#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
int f[MAXN<<1];//2-SAT
int cnt[MAXN<<1];//与其同阵营的人数
int findx(int x)
{
    if(x==f[x]) return x;
    return f[x]=findx(f[x]);
}
void merge(int x,int y)
{
    int fx=findx(x);
    int fy=findx(y);
    if(fx!=fy)
    {
        cnt[fx]+=cnt[fy];
        cnt[fy]=0;
        f[fy]=fx;
    }
}
int t,n,m;
void solve()
{
    int ans=0;
    for(int i=1;i<=n;i++)//遍历[1,n]cnt，默认为1，表示去哪个阵营都可以。如果连过边，就为0（除非是父亲）
    {
        if(findx(i)==findx(i+n)) 
        {
            cout<<-1<<endl;
            return;
        }
        ans=ans+max(cnt[i],cnt[i+n]);
        //cout<<cnt[i]<<" "<<cnt[i+n]<<endl;
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=2*n;i++)
        {
            f[i]=i;
            if(i<=n) cnt[i]=1;
            else if(i>n) cnt[i]=0;
        }
        while(m--)
        {
            int i,j;
            string s;
            cin>>i>>j>>s;
            if(s=="imposter")//i和j不是同一阵营的人
            {
                merge(i,j+n);merge(i+n,j);
            }
            else//i和j是同一阵营的人
            {
                merge(i,j);merge(i+n,j+n);
            }
        }
        solve();//计算两大阵营的人数
    }
    return 0;
}