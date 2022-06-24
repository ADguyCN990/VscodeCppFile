#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1005
typedef pair<int,int> pii;
pii p[MAXN];
int n;
int m;
void solve()
{
    cin>>m>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].first>>p[i].second;
        if(p[i].first>p[i].second) swap(p[i].first,p[i].second);
    }
    sort(p+1,p+1+n);
    int last=-1;
    int cnt=1;
    //区间选点，使得任意pair内至少存在一个断点
    for(int i=1;i<=n;i++)
    {
        if(p[i].first>=last)
        {
            cnt++;
            last=p[i].second;
        }
        else if(p[i].second<last) last=p[i].second;//小区间替代大区间，这样才能保证合法性
    }
    cout<<cnt<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}