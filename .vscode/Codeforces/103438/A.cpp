#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
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
int n;
char s[MAXN],t[MAXN];
void solve()
{
    cin>>n;
    cin>>s+1>>t+1;
    int r=0;
    ll ans=0;
    bool flag=false;
    for(int i=1;i<=n;i++)
    {
        if(r<i) 
        {
            r=i;
            flag=true;
            while(s[r]>=t[r]&&r<=n)
            {
                if(s[r]==t[r]) r++;
                else if(s[r]>t[r])
                {
                    flag=false;
                    break;
                }
            }
        }
        if(s[i]<t[i]) ans+=n-i+1;
        else if(s[i]==t[i])
        {
            if(flag)   
            ans+=n-r+1;
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}