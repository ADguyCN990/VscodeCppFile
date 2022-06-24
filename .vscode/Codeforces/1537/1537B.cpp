#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int t;
ll n,m,x,y;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>x>>y;
        if(x!=1&&y!=1&&x!=n&&y!=m)
        {
            cout<<1<<" "<<1<<" "<<n<<" "<<m<<endl;
        }
        else
        {
            cout<<n<<" "<<1<<" "<<1<<" "<<m<<endl;
        }
    }
    return 0;
}