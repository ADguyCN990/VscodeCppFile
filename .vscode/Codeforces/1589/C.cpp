#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
int a[MAXN];
int n;
int b[MAXN];
void solve()
{
    
    cin>>n;
    for(int i=1;i<=n;i++) 
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    for(int i=1;i<=n;i++)
    {
        if(a[i]+1!=b[i]&&a[i]!=b[i])
        {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}