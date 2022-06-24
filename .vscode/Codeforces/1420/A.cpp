#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<ll,ll> pii;
#define INF 0x3f3f3f3f
ll n;

struct node
{
    int val;
    int id;
}a[MAXN];

bool cmp(node a,node b)
{
    if(a.val==b.val) return a.id<b.id;
    return a.val<b.val;
}

void solve()
{
    cin>>n;
    int flag=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].val;
        a[i].id=i;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        if(n-i+1!=a[i].id) 
        {
            flag=0;
            break;
        }
    }
    if(!flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    ll T;
    cin>>T;
    while(T--)
    {
        solve();
    }

    return 0;
}