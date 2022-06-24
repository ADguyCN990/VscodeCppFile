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
    string s;
    cin >> s;
    int len = s.length();
    bool flag = false;
    for (int i = len - 1; i > 0; i --)
    {
        int a = s[i - 1] - '0';
        int b = s[i] - '0';
        if (a + b >= 10)
        {
            flag = true;
            s[i - 1] = 1 + '0';
            s[i] = '0' + ((a + b) % 10);
            break;
        }
    }
    if (flag)
    {
        cout << s << endl;
        return;
    }
    int a = s[0] - '0';
    int b = s[1] - '0';
    reverse(s.begin(), s.end());
    s.pop_back();
    reverse(s.begin(), s.end());
    s[0] = '0' + a + b;
    cout << s << endl;
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