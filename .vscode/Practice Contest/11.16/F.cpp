#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
ll n;
vector <pair<pair<int,int>,int>> ans;
map <int,vector<int>> mp;
int f[MAXN];

int findx(int x)
{
    if(x==f[x]) return x;
    else return f[x]=findx(f[x]);
}

void merge(int x,int y,int num)
{
    int fx=findx(x);
    int fy=findx(y);
    if(fy!=fx) 
    {
        f[fy]=fx;
        ans.push_back({{x,y},num});
    }
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) f[i]=i;
    for(int i=1;i<=n;i++)
    {
        int m;
        cin>>m;
        while(m--)
        {
            int k;
            cin>>k;
            mp[k].emplace_back(i);
        }
    }
    for(auto i:mp)
    {
        for(int j=1;j<i.second.size();j++)
        {
            merge(i.second[j-1],i.second[j],i.first);
        }
    }
    if(ans.size()!=n-1)
        cout<<"impossible"<<endl;
    else
        for(auto i:ans)
        {
            cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
        }
        
        
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}