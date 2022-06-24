#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
int n;
int a[MAXN];
int c[MAXN];//还是类似桶
int h[MAXN];//表示高度
int lowbit(int x) {return x&-x;}

int ask(int x)
{
    int sum=0;
    for(int i=x;i;i-=lowbit(i)) sum+=c[i];
    return sum;
}

int add(int x,int k)
{
    for(int i=x;i<=n;i+=lowbit(i)) c[i]+=k;
}

void solve()
{
    cin>>n;
    for(int i=2;i<=n;i++) cin>>a[i];
    for(int i=1;i<=n;i++) add(i,1);
    for(int i=n;i>0;i--)//从后往前枚举排名
    {
        int l=1,r=n;//二分可以得出当前排名所对应的高度
        int ans;
        while(l<=r)
        {
            int mid=(l+r)>>1;
            if(ask(mid)<a[i]+1)
            {
                l=mid+1;
            }
            else if(ask(mid)>=a[i]+1)
            {
                ans=mid;
                r=mid-1;
            }
               
        }
        h[i]=ans;
        add(ans,-1);//这个高度已经被找出来了，减去他的所有贡献
    }
    for(int i=1;i<=n;i++)
        cout<<h[i]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}