#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n;
    int mx=0X3f3f3f3f;
    cin>>n;
    int a,b;
    for(int i=1;i<=n;i++)
    {
        cin>>a>>b;
        mx=min(mx,b/a);
    }
    cout<<mx;
    return 0;
}