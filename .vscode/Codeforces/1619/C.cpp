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

void solve()
{
    ll s,a;
    string ans="";
    a=read(),s=read();
    while(s)
    {
        int aa=a%10;
        int ss=s%10;
        a/=10,s/=10;
        ss-=aa;
        if(ss>=0)
        {
            ans=to_string(ss)+ans;
            continue;
        }
        if(s%10!=1)
        {
            cout<<-1<<endl;
            return;
        }
        ss=ss+s%10*10;
        s/=10;
        ans=to_string(ss)+ans;
    }  
    if(a!=0||s!=0)
    {
        cout<<-1<<endl;
        return;
    }
    reverse(ans.begin(),ans.end());
    while(ans[ans.size()-1]=='0') ans.pop_back();
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
}

int main()
{
    int T;
    T=read();
    while(T--)
    {
        solve();
    }

    return 0;
}