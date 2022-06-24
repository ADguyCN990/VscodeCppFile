#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int n;
int a[MAXN];
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+1+n);
    for(int i=2,cnt=1;cnt<=n/2;i++,cnt++)
    {
        cout<<a[i]<<" "<<a[1]<<endl;
    }
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