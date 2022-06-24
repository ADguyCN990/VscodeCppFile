#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 10005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
#define pb emplace_back
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

ll get(ll x,ll y)
{
    cout<<"? "<<x<<" "<<y<<endl;
    ll ans;
    cin>>ans;
    return ans;
}

ll n;
int a[MAXN];
ll mx=1;//n的下标
void solve()
{
    cin>>n;
    rep(i,2,n)
    {
        int x=get(mx,i);
        int y=get(i,mx);
        if(x<y)
        {
            a[i]=y;
        }
        else if(x>y)
        {
            a[mx]=x;
            mx=i;
        }
    }
    a[mx]=n;
    if(mx!=1)
    {
        a[1]=get(1,mx);
    }
    cout<<"! ";
    cout.flush();
    rep(i,1,n)
    {
        cout<<a[i]<<" ";
        cout.flush();
    }
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}