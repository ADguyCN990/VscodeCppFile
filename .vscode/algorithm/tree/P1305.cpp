#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 10005
ll n;
string s;
ll r;
struct node
{
   char left;
   char right;
}a[MAXN];

void dfs(char rt)
{
    if(rt=='*') return;
    cout<<rt;
    dfs(a[rt].left);
    dfs(a[rt].right);
    return;
}

void solve()
{
    cin>>n;
    cin>>s;
    r=s[0];
    a[r].left=s[1];a[r].right=s[2];
    for(int i=2;i<=n;i++)
    {
        cin>>s;
        char b=s[1];char c=s[2];
        a[s[0]].left=b;a[s[0]].right=c;
    }
    dfs(r);
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}