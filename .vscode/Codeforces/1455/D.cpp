#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 505
ll n,x;
ll a[MAXN];
ll b[MAXN];
ll ans;

void solve()
{
    cin>>n>>x;
    ans=0x3f3f3f3f;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n==1)
    {
        cout<<0<<endl;
        return;
    }
    int flag=1;
    for(int i=1;i<n;i++)
    {
        if(a[i]>a[i+1])
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
    {
        cout<<0<<endl;
        return;
    }
    //a[i]大于x才能互换，x只会越来越大
    for(int i=1;i<=n;i++)//如果能换，必定有一个值变成了x，枚举被替换的位置，看看能不能变出这个序列
    {
        b[i]=x;
        for(int j=1;j<=n;j++)
        {
            if(i==j) continue;
            b[j]=a[j];
        }
        sort(b+1,b+1+n);
        int now=x;//当前的“x”
        ll temp=0;//交换的次数
        int f=1;//是否合法
        for(int j=1;j<=n;j++)
        {
            if(a[j]==b[j]) continue;
            if(now>=a[j])//换不了
            {
                f=0;
                break;
            }
            if(now<b[j-1])//换完后依旧不是非递减序列
            {
                f=0;
                break;
            }
            now=a[j];
            temp++;
        }
        if(f==1)
            ans=min(temp,ans);
    }
    if(ans==0x3f3f3f3f) cout<<-1<<endl;
    else cout<<ans<<endl;
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