#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
#define ll long long
ll a[MAXN];
int pre[MAXN];
ll n;
ll get(int x,int y,string s)
{
    ll tmp;
    cout<<s<<" "<<x<<" "<<y<<endl;
    cout.flush();
    cin>>tmp;
    return tmp;
}

void solve()
{
    cin>>n;
    memset(pre,-1,sizeof(pre));
    pre[0]=1;
    int u=-1;int v=-1;
    for(int i=2;i<=n;i++)
    {
        a[i]=get(1,i,"XOR");
        if(pre[a[i]]!=-1)
        {
            u=pre[a[i]];v=i;
        }
        pre[a[i]]=i;
    }
    if(u!=-1)
    {
        ll tmp=get(u,v,"AND");
        a[1]=a[u]^tmp;
        a[u]=tmp;a[v]=tmp;
        for(int i=2;i<=n;i++)
        {
            if(i==u||i==v) continue;
            a[i]=a[i]^a[1];
        }
            
    }
    else
    {
        u=pre[n-1];
        u==2?v=3:v=2;
        //a+b=a^b+2*(a&b)
        ll x=n-1;
        ll y=a[v]+2*get(1,v,"AND");
        ll z=(a[u]^a[v])+2*get(u,v,"AND");
        a[1]=(x+y-z)/2;
        for(int i=2;i<=n;i++)
            a[i]=a[1]^a[i];
    }
    cout<<"!";
    for(int i=1;i<=n;i++)
        cout<<" "<<a[i];
    cout<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    // int T;
    // cin>>T;
    // while(T--)
    // {
        solve();
    //}
    return 0;
}