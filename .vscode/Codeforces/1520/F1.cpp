#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
void solve()
{
    int n;int useless;int k;
    cin>>n>>useless>>k;
    int l=1;int r=n;
    //从左出现的第一个0的位置
    ll ans=n;
    while(l<=r)
    {
        int mid=(l+r)/2;
        cout<<"?"<<" "<<1<<" "<<mid<<endl;//[1,mid]1的个数
        int temp;
        cin>>temp;
        temp=mid-temp;//[1,mid]0的个数
        if(temp>=k)
        {
            ans=mid;
            r=mid-1;          
        }
        else l=mid+1;

    }
    cout<<"!"<<" "<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}