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
map <char, char> mp;
char s[MAXN];
int n;
void solve()
{
    mp['C'] = '1';
    mp['D'] = '2';
    mp['E'] = '3';
    mp['F'] = '4';
    mp['G'] = '5';
    mp['A'] = '6';
    mp['B'] = '7';
    scanf("%s", s + 1);
    n = strlen(s + 1);
    vector <char> ans;
    int now = 0;
    for (int i = 1; i <= n; i ++)
    {
        if (s[i] == '<')
            now --;
        else if (s[i] == '>')
            now ++;
        else
        {
            ans.pb(mp[s[i]]);
            if (now > 0)
                for (int j = 1; j <= now; j ++) 
                    ans.pb('*');
            else if (now < 0)
                for (int j = 1; j <= abs(now); j ++)
                    ans.pb('.');
        }
    }
    for (char x : ans)
        printf("%c", x);
}

int main()
{
    solve();
    return 0;
}