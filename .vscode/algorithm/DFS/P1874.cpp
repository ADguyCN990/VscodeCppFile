#include<bits/stdc++.h>
using namespace std;
#define MAXN 45
#define ll long long
char s[MAXN];
ll n;
ll len;
ll sum[MAXN];//后缀和 

ll get(int l,int r)
{
    int ans=0;
    for(int i=l;i<=r;i++)
    {
        ans=ans*10+(s[i]-'0');
    }
    return ans;
}

bool dfs(ll now,ll start,ll depth,ll val)//当前深度，上次把加号放在了start和start+1之间，最大深度，当前已知的和
{
    if(now>depth) return false;//迭代加深
    if(val>n) return false;//可行性剪枝
    if(val+get(start+1,len)==n&&now==depth) return true;//因为字符串末尾没有加号，记得加上最后一串
    if(val+sum[start+1]>n) return false;//可行性剪枝，最小的情况下依然大于n
    if(val+get(start+1,len)<n) return false;//可行性剪枝，最大的情况下依然小于n
    //cout<<now<<" "<<val<<endl;
    for(int i=start+1;i<len;i++)//i到i+1位放个减号
    {
        if(dfs(now+1,i,depth,val+get(start+1,i)))
            return true;
    }
    return false;
}   

void solve()
{
    cin>>s+1;
    cin>>n;
    len=strlen(s+1);
    for(int i=len;i;i--)
    {
        sum[i]=sum[i+1]+(s[i]-'0');
    }
    for(ll i=0;i<len;i++)
    {
        bool flag=dfs(0,0,i,0);
        if(flag)
        {
            cout<<i<<endl;
            return;
        }      
    }
    cout<<-1<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}