#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
#define ull unsigned long long
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
unordered_map <string, int> hashmap; 
bool check(string s)
{
    int len = s.size();
    for (int i = 0, j = len - 1; i <= j; i ++, j --)
    {
        if (s[i] != s[j]) return false;
    }
    return true;
}
int n;
void solve()
{
    hashmap.clear();
    string s;
    cin >> n;
    bool flag = false;
    for (int i = 1; i <= n; i ++)
    {
        cin >> s;
        if (flag) continue;
        if (check(s))
        {
            flag = true;continue;
        }
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        int len = s.size();
        if (hashmap.count(tmp))
        {
            flag = true;continue;
        }
        if (len == 2)
        {
            for (int i = 0; i < 26; i ++)
            {
                char u = 'a' + i;
                if (hashmap.count(tmp + u))
                {
                    flag = true;
                    break;
                }
            }
        }
        if (len == 3)
        {
            string t = tmp.substr(0, 2);
            if (hashmap.count(t))
            {
                flag = true;continue;
            }
        }
        hashmap[s] ++;
    }
    if (flag) puts("YES");
    else puts("NO");
}

int main()
{
    ios::sync_with_stdio(false);cin.tie();cout.tie(0);
    int T;
    cin >> T;
    while(T--)
    {
        solve();
    }

    return 0;
}