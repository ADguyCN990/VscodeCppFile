#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
ll t,n;
vector <ll> v;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        v.clear();
        for(int i=1;i<=n;i++) 
        {
            ll temp;cin>>temp;v.push_back(temp);
        }
        sort(v.begin(),v.end());
        if(n==2)
        {
            cout<<v[0]<<" "<<v[1]<<endl;
            continue;
        }
        int f=-1;
        ll dx=999999999999;
        for(int i=0;i<n-1;i++)
        {
           if(v[i+1]-v[i]<dx)
           {
               dx=v[i+1]-v[i];
               f=i;
           }
        }
        for(int i=f+1;i<n;i++) cout<<v[i]<<" ";
        for(int i=0;i<=f;i++)   cout<<v[i]<<" ";
        cout<<endl;
    }
    return 0;
}