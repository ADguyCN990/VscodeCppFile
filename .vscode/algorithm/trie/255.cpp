#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define MAXM MAXN*35
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

struct BalanceTree
{
    int son[MAXM][2];
    int idx;
    int cnt[MAXM];//子节点的个数（包括自己）
    ll base=10000000;//保证非负
    void clear()
    {
        idx=0;
        memset(son,0,sizeof son);
        memset(cnt,0,sizeof cnt);
    }
    void insert(ll x,int y)//插入或删除
    {
        int now=0;
        x+=base;
        for(int i=31;i>=0;i--)
        {
            int u=(x>>i)&1;
            if(!son[now][u]) son[now][u]=++idx;
            now=son[now][u];
            cnt[now]+=y;
        }
    }
    int getRank(ll x)//返回小于x的数的个数
    {
        int now=0;
        int ans=0;
        x+=base;
        for(int i=31;i>=0;i--)
        {
            int u=(x>>i)&1;
            if(u)
            {
                ans+=cnt[son[now][0]];
            }   
            if(cnt[son[now][u]])
                now=son[now][u];
            else
                break;
        }
        return ans;
    }
    int getValue(ll x)//查询第x个小的数是什么
    {
        int now=0;
        ll ans=0;
        for(int i=31;i>=0;i--)
        {
            if(x>cnt[son[now][0]])
            {
                ans+=(1<<i);
                x-=cnt[son[now][0]];
                if(cnt[son[now][1]])
                    now=son[now][1];
                else
                    break;
            }
            else
            {
                if(cnt[son[now][0]])
                    now=son[now][0];
                else
                    break;
            }
        }
        return ans-base;//插入的时候多加了1e7，返回的时候要减掉
    }

};

void solve()
{
    BalanceTree trie;
    trie.clear();
    int n;
    n=read();
    while(n--)
    {
        int opt,x;
        opt=read(),x=read();
        if(opt==1)
        {
            trie.insert(x,1);
        }
        else if(opt==2)
        {
            trie.insert(x,-1);
        }
        else if(opt==3)
        {
            printf("%d\n",trie.getRank(x)+1);
        }
        else if(opt==4)
        {
            printf("%d\n",trie.getValue(x));
        }
        else if(opt==5)
        {
            printf("%d\n",trie.getValue(trie.getRank(x)));
        }
        else if(opt==6)
        {
            printf("%d\n",trie.getValue(trie.getRank(x+1)+1));
        }
    }

}

int main()
{
    solve();
    return 0;
}