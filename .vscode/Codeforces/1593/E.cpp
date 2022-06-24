#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 400005
ll n,k;
ll cnt[MAXN];
ll deep[MAXN];
vector <ll> mp[MAXN];//邻接表建图

void init()//初始化
{
    for(int i=1;i<=n;i++) 
    {
        cnt[i]=0;
        deep[i]=-1;
        mp[i].clear();
    }
}
void build_map()//邻接表建图，包含连边个数(当做叶子)和连边的具体元素
{
    for(int i=1;i<n;i++)
    {
        ll father,son;
        cin>>father>>son;
        cnt[son]++;cnt[father]++;
        mp[son].emplace_back(father);
        mp[father].emplace_back(son);
    }
}
void bfs()
{
    queue <int> q;
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]==1)//他是叶子
        {
            deep[i]=1;
            q.push(i);//把被删除的元素推入队列，在bfs中进行更新操作
        }
    }
    while(!q.empty())
    {
        int now=q.front();q.pop();
        for(auto x:mp[now])//遍历他的所有邻居
        {
            cnt[x]--;
            if(cnt[x]<=1&&deep[x]==-1)
            {
                deep[x]=deep[now]+1;
                q.push(x);
            }
        }
    }
}
void solve()
{
    cin>>n>>k;
    init();
    if(n==1)//只有一个节点
    {
        cout<<0<<endl;
        return;
    }
    build_map();
    bfs();
    ll ans=0;
    for(int i=1;i<=n;i++) if(deep[i]>k) ans++;
    cout<<ans<<endl;
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


/*
    private node
    {
        public int data;
        public node next;       
    }
    public node(int x,node n)
    {
        this.data=x;this.next=n;
    }
    private node front;
    private node back;
    private int currentsize;
    private node []linkedlist;
    private static int MIN CAPACITY=100;

    front=null;back=null;currentsize=0;
    public push(int x)
    {

    }


*/