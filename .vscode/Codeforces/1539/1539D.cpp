#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define ll long long
ll n;
struct node
{
    ll a;
    ll b;
}a[MAXN];
bool cmp(node a,node b){return a.b<b.b;}
//贪心思路：不可能打折的放最前面，如果某件商品能打折了就全买
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    ll now=0;//已经购买的商品总数
    ll ans=0;//最终需要付的钱
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i].a>>a[i].b;
    }
    sort(a+1,a+1+n,cmp);
    int p1=1;//当前购买的商品 
    int p2=n;
    while(p1<=p2)
    {
        if(now>=a[p1].b)//可以直接买了,那就全买
        {
            ans+=a[p1].a;
            now+=a[p1].a;
            p1++;
        }
        else//得先去垫刀
        {
            if(a[p2].a>a[p1].b-now)
            {
                a[p2].a-=(a[p1].b-now);
                ans+=2*(a[p1].b-now);
                now+=(a[p1].b-now);
            }
            else
            {
                ans+=2*a[p2].a;
                now+=a[p2].a;
                p2--;
            }      
        }
    }
    cout<<ans<<endl;
    return 0;
}