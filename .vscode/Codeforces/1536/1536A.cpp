#include<bits/stdc++.h>
using namespace std;
#define MAXN 305
#define ll long long
ll n,t,a[MAXN];

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        sort(a+1,a+1+n);
        if(a[n]<abs(a[n]-a[1])) 
        {
            cout<<"NO"<<endl;
            continue;
        }
        cout<<"YES"<<endl<<a[n]+1<<endl;
        for(int i=0;i<=a[n];i++) cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}