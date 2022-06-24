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
int a[MAXN];
int n;
vector <string> ans;
void solve()
{
    int mx = 0;
    ans.clear();
    n = read();
    for (int i = 1; i <= n; i ++) a[i] = read(), mx = max(mx, a[i]);
    string s = "";
    for (int i = 1; i <= max(1, mx); i ++)
        s += 'a';
    ans.pb(s);
    for (int i = n; i >= 1; i --)
    {
        int pos = a[i];
        if (pos <= s.length() - 1)
        {
            if (s[pos] == 'a') s[pos] = 'b';
            else s[pos] = 'a';
        }    
        ans.pb(s);
    }
    reverse(ans.begin(), ans.end());
    for (string x : ans) cout << x << endl;
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