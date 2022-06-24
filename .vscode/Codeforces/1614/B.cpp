#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
//参观建筑的次数
int n;
struct node
{
    ll num;
    int id;
}a[MAXN];
int pos[MAXN];
bool cmp(node a,node b) {return a.num>b.num;}
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].num;
        a[i].id=i;
    }
    sort(a+1,a+1+n,cmp);
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        if(i&1)
        {
            pos[a[i].id]=(i+1)/2;
        }
        else
            pos[a[i].id]=-(i+1)/2;
        ans+=(i+1)/2*a[i].num;
    }
    cout<<ans*2<<endl;
    cout<<0<<" ";
    for(int i=1;i<=n;i++)
        cout<<pos[i]<<" ";
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