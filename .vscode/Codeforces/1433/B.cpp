#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
vector <int> v;
void solve()
{
    int n;
    cin>>n;
    v.clear();
    for(int i=1;i<=n;i++)
    {
        int t;
        cin>>t;
        v.emplace_back(t);
    }
    int ans=0;
    int tmp=0;
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]==1)
        {
            if(cnt)
            ans+=tmp;
            tmp=0;
            cnt++;
        }
        else
            tmp++;
    }
    cout<<ans<<endl;
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