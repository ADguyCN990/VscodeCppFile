#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 600005
#define MAXM MAXN*32
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
int n,m;
int son[MAXM][2],sum[MAXN],mx[MAXM],tot;
int rt[MAXM];//版本号

void insert(int id,int last,int now)
//id表示当前插入的前缀和编号为i，last表示上个版本下和现在这个版本上和now同等意义的点
{
    mx[now]=id;//更新最新版本信息
    for(int i=31;i>=0;i--)//枚举每一位
    {
        int u=(sum[id]>>i)&1;//取出当前位数
   //如果前一个节点存在当前节点没有的分支，就把当前这个节点的空的路径指过去，相当于复制
        if(last) 
            son[now][!u]=son[last][!u];
        son[now][u]=++tot;//正常的插入操作
        
        //可以注意到此时只复制了!u这个点的信息，u方向的还没复制过
        //不是说不用复制了
        //而是因为now现在插入的数字是u，而last版本下这条路径也是u，所以暂时不需要复制
        last=son[last][u],now=son[now][u];//同步往下走（递归）
        mx[son[now][u]]=id;//更新当前点的最新版本信息
    }
}

ll query(int now,int l,ll x)
{
    ll ans=0;
    for(int i=31;i>=0;i--)
    {
        int u=(x>>i)&1;
        if(mx[son[now][!u]]>=l)
        //1.!u这个点要出现过
		//2.!u这个点的最新版本出现时间要大于等于l
        //2包含1，只要满足2那么1也一定满足
        {
            now=son[now][!u];
            ans=ans*2+!u;
        }
        else
        {
            now=son[now][u];
            ans=ans*2+u;
        }
    }
    return ans;
}

void solve()
{
    n=read(),m=read();
    mx[0]=-114514;
    rt[0]=++tot;
    sum[0]=0;
    insert(0,0,rt[0]);
    rep(i,1,n)
    {
        ll tmp;
        tmp=read();
        sum[i]=sum[i-1]^tmp;
        rt[i]=++tot;
        insert(i,rt[i-1],rt[i]);
    }
    while(m--)
    {
        char s[10];
        scanf("%s",s);
        if(s[0]=='A')//插入一个数
        {
            ll x;
            x=read();
            n++;//多了一个数
            sum[n]=sum[n-1]^x;//更新前缀和
            rt[n]=++tot;//新增一个版本
            insert(n,rt[n-1],rt[n]);
        }
        else
        {
            ll x,l,r;
            l=read(),r=read(),x=read();
            //query返回的是从r-1这个版本进去，最早版本为l-1，与sum[n]^x异或后最大的数
            printf("%lld\n",query(rt[r-1],l-1,sum[n]^x)^(sum[n]^x));
        }
    }

}

int main()
{
    solve();
    return 0;
}