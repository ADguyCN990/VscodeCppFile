#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
ll n;
struct node
{
    int left;
    int right;
}a[MAXN];//记录根节点的左右儿子编号

int dfs(int rt)
{
    if(a[rt].left==0&&a[rt].right==0)//遍历到了叶子节点
        return 1;
    int len_l=dfs(a[rt].left);
    int len_r=dfs(a[rt].right);
    return 1+max(len_l,len_r);
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].left>>a[i].right;
    }
    cout<<dfs(1)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}