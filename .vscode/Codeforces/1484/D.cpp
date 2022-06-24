#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
ll n;
ll a[MAXN];//存放元素
int visit[MAXN];//标记有没有被删除
int R[MAXN];//存放每个下标右边的下标
vector <int> pos;//存放可能出现被删除元素的位置的左端
vector <int> tmp;//每次处理时用的临时存储结构
vector <int> ans;

ll gcd(ll a,ll b)
{
    if(a<b) swap(a,b);
    ll temp;
    while(b)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}

void init()
{
    for(int i=1;i<=n;i++)
    {
        visit[i]=0;
    }
    pos.clear();tmp.clear();ans.clear();
}

void solve()
{
    cin>>n;
    init();
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        R[i]=i+1;
        pos.emplace_back(i);
    }
    R[n]=1;
    while(pos.size()>0)
    {
        tmp.clear();
        for(auto i:pos)
        {
            if(visit[i]==1) continue;
            if(gcd(a[i],a[R[i]])==1)//可以删除右边的元素
            {   
                tmp.emplace_back(i);
                visit[R[i]]=1;
                ans.emplace_back(R[i]);
                R[i]=R[R[i]];
                
            }
        }
        pos=tmp;
    }
    cout<<ans.size()<<" ";
    for(auto x:ans) cout<<x<<" ";
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