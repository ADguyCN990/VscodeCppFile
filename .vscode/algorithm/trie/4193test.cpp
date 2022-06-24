
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int s[400003];
int l[400003];
int r[400003];
struct emm{
    int nxt[2];
}a[12800003];
int cnt=0;
int b[33];
void add(int x)
{
    int j=-1;
    memset(b,0,sizeof(b));
    while(x)
    {
        b[++j]=x&1;
        x>>=1;
    }
    int k=0;
    for(int j=32;j>=0;--j)
    {
        if(!a[k].nxt[b[j]])
          a[k].nxt[b[j]]=++cnt;
        k=a[k].nxt[b[j]];
    }
    return;
}
int find(int x)
{
    int now=0,k=0;
    for(int j=32;j>=0;--j)
    {
        if(a[k].nxt[1-b[j]])
        {
            now+=(1<<j);
            k=a[k].nxt[1-b[j]];
        }
        else k=a[k].nxt[b[j]];
    }
    return now;
}
int main()
{
    //freopen("a.in","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
      scanf("%d",&s[i]);
    int x=0;
    for(int i=1;i<=n;++i)
    {
        x^=s[i];//这里的x为前缀和
        add(x);
        l[i]=max(l[i-1],find(x));
    }
    //重做一次找r[i]
    memset(a,0,cnt+1);
    x=0,cnt=0;
    for(int i=n;i;--i)
    {
        x^=s[i];
        add(x);
        r[i]=max(r[i+1],find(x));
    }
    int ans=0;
    for(int i=1;i<=n;i++) printf("%d %d\n",l[i],r[i]);
    for(int i=1;i<n;++i)
    ans=max(ans,l[i]+r[i+1]);
    cout<<ans;
    return 0;
}