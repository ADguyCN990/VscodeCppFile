#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll n;
ll a[MAXN];
ll b[MAXN];//用一个桶来维护每个答案的构成序列的最末尾的那个数
//b[i]表示当前异或结果为i的最小大小(这个数字要尽可能小)
vector <int> ans;
void solve()
{
    cin>>n;
    for(int i=0;i<=512;i++) b[i]=0x3f3f3f3f;//将b赋为非法状态
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)//枚举最末尾的那个数
    {
        b[a[i]]=min(b[a[i]],a[i]);
        for(int j=0;j<=512;j++)
        {
            if(a[i]>=b[j])//可以往结尾多添加一个值或者更改结尾的值
            {   
                b[j^a[i]]=min(b[j^a[i]],a[i]);
            }
        }
    }
    for(int i=0;i<=512;i++)
    {
        if(b[i]!=0x3f3f3f3f) ans.emplace_back(i);
    }
    cout<<ans.size()<<endl;
    for(auto i:ans) cout<<i<<" ";
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}