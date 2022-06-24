#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
#define MAXM 200005
char s[MAXN];
int cnt[MAXN];//每个字符对abc的贡献
int n,m;

void solve()
{
    cin>>n>>m;
    cin>>s+1;
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(i+2>n) break;
        if(s[i]=='a'&&s[i+1]=='b'&&s[i+2]=='c')
        {
            cnt[i]++;cnt[i+1]++;cnt[i+2]++;ans++;
        }   
    }
    while(m--)
    {
        int i;
        char c;
        cin>>i>>c;
        if(c==s[i])
        {
            cout<<ans<<endl;
            continue;
        }
        if(cnt[i])
        {
            if(s[i]=='a')
                cnt[i]--,cnt[i+1]--,cnt[i+2]--;
            else if(s[i]=='b')
                cnt[i-1]--,cnt[i]--,cnt[i+1]--;
            else if(s[i]=='c')
                cnt[i-2]--,cnt[i-1]--,cnt[i]--;
            ans--;
        }
        s[i]=c;
        if(c=='a'&&i+2<=n&&s[i+1]=='b'&&s[i+2]=='c')
            cnt[i]++,cnt[i+1]++,cnt[i+2]++,ans++;
        else if(c=='b'&&i>=2&&i+1<=n&&s[i-1]=='a'&&s[i+1]=='c')
            cnt[i-1]++,cnt[i]++,cnt[i+1]++,ans++;
        else if(c=='c'&&i>=3&&s[i-2]=='a'&&s[i-1]=='b')
            cnt[i-2]++,cnt[i-1]++,cnt[i]++,ans++;
        cout<<ans<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}