#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 300005
ll n;ll a[MAXN];
int cnt[MAXN];
int ans[MAXN];
void special_judge()
{
    for(int i=1;i<=n;i++) ans[i]=1;
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]>1||cnt[i]<1) 
        {
            ans[1]=0;
            return;
        }
    }
    ans[1]=1;
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cnt[i]=0;
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    special_judge();
    int l=1;int r=n;
    int now=1;//最小值
    cnt[0]=1;
    while(l<=r)
    {
        if(a[l]==now&&cnt[now-1]==1)
        {
            now++;
            l++;
        }
        else if(a[r]==now&&cnt[now-1]==1)
        {
            r--;
            now++;
        }
        else
        {
            if(cnt[now-1]==1&&cnt[now]!=0) 
                now++;
            for(int i=n-now+1;i>1;i--){
                ans[i]=0;
            }
            break;
        }
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i];
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