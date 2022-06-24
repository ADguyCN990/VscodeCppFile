#include<bits/stdc++.h>
using namespace std;
#define MAXN 25
int n;
int a[MAXN];
int vis[MAXN];
int sum;
int ans;
bool cmp(int a,int b) {return a>b;}
bool dfs(int now,int tot)//当前已经处理完的边，当前边已经选了多少长度
{
    if(now==4) return true;
    if(tot==ans) return dfs(now+1,0);

    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(tot+a[i]>ans) continue;
            vis[i]=1;
            if(dfs(now,tot+a[i]))
                return true;
            vis[i]=0;
            if(tot+a[i]==ans) return false;
            if(tot==0) return false;
        }
    }

    return false;
}
void solve()
{
    sum=0;
    cin>>n;
    memset(vis,0,sizeof vis);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    if(sum%4)
    {
        cout<<"no"<<endl;
        return;
    }
    ans=sum/4;
    sort(a+1,a+1+n,cmp);
    bool flag=dfs(0,0);
    if(flag) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
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