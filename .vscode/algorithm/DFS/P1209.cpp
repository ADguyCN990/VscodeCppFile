#include<bits/stdc++.h>
using namespace std;
#define MAXN 205
#define ll long long
int m,s,n;
int a[MAXN];
int d[MAXN];
int ans=0x3f3f3f3f;
bool cmp(int a,int b) {return a>b;}
void solve()
{
    cin>>m>>s>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(m>n)//木板比牛还多
    {
        cout<<n<<endl;
        return;
    }
    sort(a+1,a+1+n);
    ans=a[n]-a[1]+1;
    for(int i=2;i<=n;i++)
    {
        d[i-1]=a[i]-a[i-1]-1;
    }
    sort(d+1,d+n,cmp);
    for(int i=1;i<m;i++)
    {
        ans-=d[i];
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}