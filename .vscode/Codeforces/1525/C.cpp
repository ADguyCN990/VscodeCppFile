#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
ll n,m,N;
ll begin_id[MAXN];char begin_dir[MAXN];
struct node
{
    ll val;//下标
    char dir;//方向
}a[MAXN];
bool cmp(node a,node b)
{
    return a.val<b.val;
}
void debug()
{
    for(int i=1;i<=n;i++) cout<<a[i].val<<" ";
    cout<<endl;
    for(int i=1;i<=n;i++) cout<<a[i].dir<<" ";
    cout<<endl;
}
void solve_()
{
    sort(a+1,a+1+n,cmp);
    
}

void solve()
{
    cin>>N>>m;
    for(int i=1;i<=N;i++) cin>>begin_id[i];
    for(int i=1;i<=N;i++) cin>>begin_dir[i];
    //先处理奇数
    n=0;
    for(int i=1;i<=N;i++)
    {
        if(begin_id[i]%2==1) 
        {
            a[++n].val=begin_id[i];
            a[n].dir=begin_dir[i];
        }
    }
    solve_();
    n=0;
    for(int i=1;i<=N;i++)
    {
        if(begin_id[i]%2==0)
        {
            a[++n].val=begin_id[i];
            a[n].dir=begin_dir[i];
        }
    }
    solve_();
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