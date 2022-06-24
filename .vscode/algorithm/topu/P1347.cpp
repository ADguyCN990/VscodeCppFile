#include<bits/stdc++.h>
using namespace std;
#define MAXN 30
#define ll long long
int indgr[MAXN];int original_indgr[MAXN];
vector <int> mp[MAXN];
set <int> ss;//用于获得当前元素个数
ll n,m;
ll sum,ans;//遍历的点的数量和拓扑链的最大层数
struct node
{
    int u;
    ll val;//层数
};
int step;
int have;

void output()
{
    queue <int> q;
    memset(indgr,0,sizeof(indgr));
    for(int i=0;i<26;i++)
    {
        for(auto j:mp[i])
        {
            indgr[j]++;
        }
    }
    for(int i=0;i<26;i++)
    {
        if(indgr[i]==0&&ss.count(i))
        {
            q.push(i);
            cout<<(char)(i+'A');
        }
    }
    while(!q.empty())
    {
        int now=q.front();q.pop();
        for(auto j:mp[now])
        {
            indgr[j]--;
            if(indgr[j]==0)
            {
                cout<<(char)('A'+j);
                q.push(j);
            }
        }
    }
    
}

void topp()
{
    queue <node> q;
    for(int i=0;i<26;i++)
    {
        if(indgr[i]==0&&ss.count(i))//首先必须得保证这个字母出现过
        {
            q.push(node{i,1});
            sum++;
        }
    }
    while(!q.empty())
    {
        node now=q.front();q.pop();
        int u=now.u;ll val=now.val;
        for(auto v:mp[u])
        {
            indgr[v]--;
            if(indgr[v]==0)
            {
                sum++;
                q.push(node{v,val+1});
                ans=max(val+1,ans);
            }
        }
    }
    if(ans==n)//最长拓扑链长度为n
    {
        printf("Sorted sequence determined after %d relations: ",step);
        output();
        cout<<".";
        exit(0);
    }
    if(sum!=have)//有环
    {
        printf("Inconsistency found after %d relations.",step);
        exit(0);
    }
    
}

void solve()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        step=i;
        string s;
        cin>>s;
        char a=s[0];char c=s[2];
        mp[a-'A'].emplace_back(c-'A');
        ss.insert(a-'A');ss.insert(c-'A');
        have=ss.size();
        original_indgr[c-'A']++;
        sum=0;ans=0;
        memcpy(indgr,original_indgr,sizeof(original_indgr));
        topp();
    }
    printf("Sorted sequence cannot be determined.");
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}
