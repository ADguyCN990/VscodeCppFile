#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll n;
ll a[MAXN];
int query(int inx)
{
    int ans;
    cout<<"? "<<inx<<endl;
    cout.flush();
    cin>>ans;
    return ans;
}

void solve()
{
    cin>>n;
    a[0]=0x3f3f3f3f;a[n+1]=0x3f3f3f3f;
    int l=1;int r=n;
    while(l<r)
    {
        int mid=(l+r)>>1;
        int val=query(mid);int val1=query(mid+1);
        if(val>val1)
        {
            l=mid+1;
        } 
        else if(val<val1)
        {
            r=mid;
        }
    }
    cout<<"! "<<l<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}