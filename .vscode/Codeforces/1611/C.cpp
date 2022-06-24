#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n;
int a[MAXN];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n==1)
    {
        cout<<1<<endl;
        return;
    }
    if(a[1]!=n&&a[n]!=n)
    {
        cout<<-1<<endl;
        return;
    }
    if(a[1]==n)
    {
        cout<<a[1]<<" ";
        for(int i=n;i>=2;i--)
            cout<<a[i]<<" ";
    }
    else if(a[n]==n)
    {
        for(int i=n-1;i>=1;i--)
        {
            cout<<a[i]<<" ";
        }
        cout<<a[n];
    }
    cout<<endl;
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