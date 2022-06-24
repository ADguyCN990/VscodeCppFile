#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
int t,n,m;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if(n==1||n==m) cout<<2<<endl;
        else if(m==1) cout<<n+1<<endl;
        else 
        {
            cout<<3<<endl;
        }
    }

    return 0;
}