#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 2005
int t,n;
ll a[MAXN];
ll pre[MAXN];//前缀异或和
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=1;i<=n;i++) 
        {
            cin>>a[i];
            pre[i]=pre[i-1]^a[i];
        }
        if(pre[n]==0)
        {
            cout<<"Yes"<<endl;
            continue;
        }
        int cnt=0;
        ll f=pre[n];
        for(int i=1;i<=n;i++)
        {
            if(pre[i]==f)
            {
                cnt++;
                if(f==pre[n]) f=0;
                else f=pre[n];
            }
        }
        if(cnt>=2) cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
    return 0;

}
