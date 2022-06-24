#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int n;

void dfs(int l1,int r1,int l2,int r2)
{
    if(l1>r1||l2>r2) return;
    for(int i=l1;i<=r1;i++)
    {
        if(s1[i]==s2[l2])
        {
            dfs(l1,i-1,l2+1,l2-l1+i);
            dfs(i+1,r1,l2-l1+i+1,r2);
            cout<<s1[i];
        }
    }
    
}

void solve()
{
    cin>>s1>>s2;//1为中序，2为前序
    n=s1.length();
    dfs(0,n-1,0,n-1);
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}