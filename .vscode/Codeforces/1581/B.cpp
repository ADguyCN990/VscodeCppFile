#include<bits/stdc++.h>
using namespace std;
#define ll long long 
//n个点m条边构成的图，两点间最长的路要小于k-1
ll n,m,k,t;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>k;
        if(k<=1)
        {
            cout<<"No"<<endl;
            continue;
        }
        if(m<n-1||m>(n-1)*n/2)
        {
            cout<<"No"<<endl;
            continue;
        }
        if(n==1&&m==0)
        {
            cout<<"Yes"<<endl;
            continue;
        }

        if(k==2||(k==3&&m!=n*(n-1)/2))
        {
            cout<<"No"<<endl;
            continue;
        }

        cout<<"Yes"<<endl;
    }

    return 0;
}