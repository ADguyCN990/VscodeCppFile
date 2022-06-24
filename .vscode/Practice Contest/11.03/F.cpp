#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
int c[MAXN];//树状数组求逆序对
ll n;ll a[MAXN];
ll q,l,r;//q次询问，交换a[l]和a[r]
int lowbit(int x) {return x&(-x);}

void insert(int x)
{
    while(x<=MAXN-5)
    {
        c[x]++;
        x+=lowbit(x);
    }
}

int query(int x)
{
    int ans=0;
    while(x)
    {
        ans+=c[x];
        x-=lowbit(x);
    }
    return ans;
}
void solve()
{
    memset(c,0,sizeof(c));
    cin>>n;
    ll ans=0;//逆序对数量
    for(int i=1;i<=n;i++) 
    {
        cin>>a[i];
        a[i]++;//狗币东西，从0开始算起的
        ans+=(i-1)-query(a[i]);
        insert(a[i]);
    }
    ll cnt=ans;//过程中处理时用的值
    cin>>q;
    while(q--)
    {
        cin>>l>>r;
        if(l==r) continue;
        int cnt1=0;int cnt2=0;
        for(int i=l+1;i<r;i++)
        {
            if(a[i]<a[l]) cnt1++;
            if(a[i]>a[r]) cnt2++;
        }
        cnt=cnt-cnt1-cnt2;//减去原先所有的逆序对
        if(a[l]>a[r]) cnt--;
        swap(a[l],a[r]);
        cnt1=0;cnt2=0;
        for(int i=l+1;i<r;i++)
        {
            if(a[i]>a[r]) cnt1++;
            if(a[i]<a[l]) cnt2++;
        }
        cnt=cnt+cnt1+cnt2;//算上所有新产生的逆序对
        if(a[l]>a[r]) cnt++;
        ans=min(cnt,ans);
    }
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