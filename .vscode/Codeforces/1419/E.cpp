#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
ll read()
{
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
ll n;
const int N=100000;

bool isprime(ll x)
{
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
            return false;
    }
    return true;
}

ll factor[200005];//质因数
ll ans[200005];//因数
int fatcnt=0;//质因数个数
int tot=0;//因数个数
map <ll,int> vis;
void getfactors(ll x)//筛选质因数（不能重复）
{
    fatcnt=0;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            factor[++fatcnt]=i;
            while(x%i==0)
                x/=i;
        }
    }
    if(x!=1)
        factor[++fatcnt]=x;
}
void getAllFactors(ll x)//筛选因数（不能重复）
{
    tot=0;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            ans[++tot]=i;
            if(i*i==x) continue;
            ans[++tot]=x/i;
        }
    }
    ans[++tot]=x;
}

void solve()
{
    n=read();
    getfactors(n);
    getAllFactors(n);
    if(tot==3&&isprime(ans[1])&&isprime(ans[2]))
    {   
        cout<<ans[1]<<" "<<ans[2]<<" "<<ans[3]<<endl;
        cout<<1<<endl;
        return;
    }
    vis.clear();
    rep(i,1,fatcnt-1)
    {
        vis[factor[i]*factor[(i+1)]]=1;
    }
    vis[factor[1]*factor[fatcnt]]=1;//作为中介值先处理好
    rep(i,1,fatcnt)
    {
        int p=factor[i];
        rep(j,1,tot)
        {
            int x=ans[j];
            if(x%p==0&&!vis.count(x))
            {
                vis[x]=1;
                cout<<x<<" ";
            }
        }
        if(fatcnt==2&&i==1) continue;//例如 18,会导致重复输出6
        cout<<factor[i]*factor[i%fatcnt+1]<<" ";
    }
    cout<<endl;
    cout<<0<<endl;

}

int main()
{
    int T;
    T=read();
    while(T--)
    {
        solve();
    }

    return 0;
}