#include<bits/stdc++.h>
using namespace std;
#define MAXN 55
#define ll long long
ll a[MAXN];
ll t,n;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        ll sum=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            sum+=a[i];
        }
        if(sum==n) cout<<0<<endl;
        else if(sum<n) cout<<1<<endl;
        else
        {
            cout<<sum-n<<endl;
        }
        
    }
    return 0;
}