#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
typedef pair<int,int> pii;
vector <pii> ans;
#define INF 0x3f3f3f3f
int n;
void solve()
{
    ans.clear();
    cin>>n;
    int now=n;
    for(int i=n-1;i;i--)
    {
        ans.push_back({i,now});
        now=(now+1+i)/2;
    }
    cout<<now<<endl;
    for(int i=0;i<ans.size();i++)
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }

    return 0;
}