#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define ll long long
ll n,m,q;
ll a[MAXN];
ll sum[MAXN];
map <ll,int> mp;//统计某个数是否出现过

void dfs(int l,int r)//类似于搜索树
{
    if(l<1||l>n||r<1||r>n||l>r) return;
    if(a[l]==a[r])
    {
        mp[(r-l+1)*a[l]]=1;
        return;
    }
    int val=(a[l]+a[r])/2;
    int pos=upper_bound(a+l,a+1+r,val)-(a+1);//小于等于pos的是left，大于pos的是右子树  
    mp[sum[pos]-sum[l-1]]=1;
    mp[sum[r]-sum[pos]]=1;
    dfs(l,pos);dfs(pos+1,r);   
}

void solve()
{
    mp.clear();
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    sum[1]=a[1];
    for(int i=2;i<=n;i++) sum[i]=sum[i-1]+a[i];
    dfs(1,n);
    mp[sum[n]]=1;
    while(m--)
    {
        ll tmp;
        cin>>tmp;
        if(mp[tmp]==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
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