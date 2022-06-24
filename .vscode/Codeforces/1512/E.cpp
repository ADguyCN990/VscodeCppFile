#include<bits/stdc++.h>
using namespace std;
#define MAXN 505
#define ll long long
ll n,l,r,m;
int visit[MAXN];

void solve()
{
    cin>>n>>l>>r>>m;
    for(int i=1;i<=n;i++) visit[i]=0;
    ll cnt=r-l+1;
    ll max_t=(n+n-r+l)*(r-l+1)/2;
    ll min_t=(r-l+2)*(r-l+1)/2;
    if(m>max_t||m<min_t)
    {
        cout<<-1<<endl;
        return;
    }
    ll dx=m-min_t;
    ll extra=dx/cnt;//每位多加的数
    ll mod=dx%cnt;//剩余的数，还要加
    //cout<<"dx: "<<dx<<" extra: "<<extra<<" mod: "<<mod<<endl;
    for(int i=1;i<=cnt;i++) visit[i+extra]=1;
    if(cnt+extra+mod<=n&&mod!=0)
    {
        visit[cnt+extra]=0;
        visit[cnt+extra+mod]=1;
    }
    else if(mod!=0)
    {
        visit[n]=1;
        
        visit[n-mod]=0;
    }
    vector <ll> mid;
    vector <ll> v;
    for(int i=1;i<=n;i++) 
    {
        if(visit[i]==1) mid.emplace_back(i);
        else v.emplace_back(i);
    }
    //cout<<"v_size: "<<v.size()<<" mid_size: "<<mid.size()<<endl;
    int cnt_=-1;
    for(int i=0;i<l-1;i++) 
    {
        cout<<v[i]<<" ";
        cnt_=i;
    }
    for(int i=0;i<mid.size();i++) cout<<mid[i]<<" ";
    for(int i=cnt_+1;i<v.size();i++) cout<<v[i]<<" ";
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