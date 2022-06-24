#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
map <string,int> last;
map <string,int> mp;
int n,k;
struct node
{
    string s;
    int num;
    int time;
}a[MAXN];

bool cmp(node a,node b)
{
    if(a.num==b.num) return a.time>b.time;
    return a.num>b.num;
}

void solve()
{
    cin>>n>>k;
    cin.ignore();
    int cnt=0;
    for(int i=1;i<=3*n;i++)
    {
        string s;
        getline(cin,s);
        mp[s]++;
        last[s]=i;
        //cin.ignore();
    }
    for(auto x:mp)
    {
        string s=x.first;
        int num=x.second;
        int time=last[s];
        a[++cnt]={s,num,time};
    }
    sort(a+1,a+1+cnt,cmp);
    for(int i=1;i<=k;i++)
    {
        cout<<a[i].s<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}