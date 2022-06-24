#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
int a[MAXN];
int n;
int ans;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    ans=a[n];//最后一个人肯定全拿
    for(int i=n-1;i>0;i--)
    {
        ans=abs(ans-a[i]);
    }
    cout<<ans<<endl;
    return 0;
}