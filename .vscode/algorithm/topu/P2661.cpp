#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
int ans=0x3f3f3f3f;//最小环的个数
int f[MAXN];
ll n;
int cnt;
int findx(int x,int &cnt)
{
    cnt++;
    if(x==f[x]) return x;
    else return findx(f[x],cnt);
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=n;i++)
    {
        int temp;
        cnt=0;
        cin>>temp;
        int goal=findx(temp,cnt);
        if(goal==i)
        {
            ans=min(ans,cnt);
        }
        else f[i]=temp;
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}