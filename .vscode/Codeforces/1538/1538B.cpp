#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
ll t,n;
ll a[MAXN];
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
        if(sum%n!=0)
        {
            cout<<-1<<endl;
            continue;
        }
        sum/=n;
       ll k=0;
       for(int i=1;i<=n;i++) if(a[i]>sum) k++;
       cout<<k<<endl;
    }
    return 0;
}