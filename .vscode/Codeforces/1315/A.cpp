#include<bits/stdc++.h>
using namespace std;
int n,m,x,y;
int t;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>m>>x>>y;
        int ans1=max(0,(n-x-1)*m);
        int ans2=max(0,x*m);
        int ans3=max(0,n*(m-y-1));
        int ans4=max(0,n*y);
        cout<<max(max(ans1,ans2),max(ans3,ans4))<<endl;
    }

    return 0;
}