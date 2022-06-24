#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 50
ll V,n;
ll a[MAXN],k;
int cnt=1;//能预处理出来的重量的总数,0也算从1开始枚举
ll pre[1<<25];//能预处理出的重量
ll ans=0;
bool cmp(ll a,ll b) {return a>b;}

void dfs1(int now,ll sum)//预处理前面一半所有可能的重量
{
    if(now==k)
    {
        pre[++cnt]=sum;
        return;
    }
    dfs1(now+1,sum);
    if(sum+a[now+1]<=V)//可行性剪枝
        dfs1(now+1,sum+a[now+1]);
}

bool check(int mid,ll sum)
{
    if(pre[mid]+sum<=V) return true;
    return false;
}

void dfs2(int now,ll sum)
{
    if(now==n)
    {
        int l=1,r=cnt;
        int tmp;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(check(mid,sum))
            {
                tmp=mid;
                r=mid-1;//还可以选的更大
            }  
            else 
                l=mid+1;
        }
        ans=max(ans,sum+pre[tmp]);
        return;
    }
    dfs2(now+1,sum);
    if(sum+a[now+1]<=V)
        dfs2(now+1,sum+a[now+1]);
}

void solve()
{
    cin>>V>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n,cmp);
    k=n/2+2;
    dfs1(0,0);
    sort(pre+1,pre+1+cnt,cmp);
    cnt=unique(pre+1,pre+1+cnt)-(pre+1);
    dfs2(k,0);
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}