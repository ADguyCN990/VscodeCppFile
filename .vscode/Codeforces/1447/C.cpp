#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll n,V;
ll sum[MAXN];
struct node
{
    int id;
    int val;
}a[MAXN];

bool cmp(node a,node b) {return a.val<b.val;}//降序排序

void solve()
{
    cin>>n>>V;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].val;
        a[i].id=i;
    }
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
        sum[i]=sum[i-1]+a[i].val;
    int l=1;int r=1;
    while(l<=n&&r<=n)
    {
        if(sum[r]-sum[l-1]<(V+1)/2)
            r++;
        else if(sum[r]-sum[l-1]>V)
        {
            if(l==r)
            {
                l++;
                r++;
            }
            else
                l++;         
        }
        else
        {
            cout<<r-l+1<<endl;
            for(int i=l;i<=r;i++) cout<<a[i].id<<" ";
            cout<<endl;
            return;
        }
    }
    cout<<-1<<endl;
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