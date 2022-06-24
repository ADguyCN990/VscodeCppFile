#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
typedef pair<int,int> pii;
pii p[MAXN];//小于等于first的人比他大，大于等于second的人比他小
int n;

bool check(int mid)
{
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        //前面的最多人最多去i-1人，后面的人最多去n-i个
        //一共去mid个，前面的人为cnt个，后面的人为mid-1-cnt个
        if(p[i].second>=cnt&&p[i].first>=mid-1-cnt)
            cnt++;
    }
    //cout<<cnt<<endl;
    return cnt>=mid;
}

void solve()
{
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        cin>>p[i].first>>p[i].second;
    }
    int l=-1,r=n+1;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else    
            r=mid-1;
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