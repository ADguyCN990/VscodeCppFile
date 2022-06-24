#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
int t,n,x;
int a[MAXN];
int b[MAXN];

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n>>x;
        for(int i=1;i<=n;i++) 
        {
            cin>>a[i];
            b[i]=a[i];
        }
        if(n>=2*x)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        if(n==1)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        sort(a+1,a+1+n);
        int f=1;
        for(int i=n-x+1;i<=x;i++)
        {
            if(a[i]!=b[i])
            {
                f=0;
                break;
            }
        }
        if(f) cout<<"YES"<<endl;
        else cout<<"No"<<endl;
    }

    return 0;
}