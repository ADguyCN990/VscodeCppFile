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
struct node
{
    int id;
    int s;
}a[MAXN];
bool cmp(node a, node b) {return a.s > b.s;}
int n;
void solve()
{
    n = read();
    for (int i = 1; i <= n; i ++)
    {
        string s;
        cin >> s;
        int len = s.length();
        int num = 0;
        for (int i = 0; i < len; i ++)
        {
            int u;
            if (s[i] == 'X') u = 9;
            else u = s[i] - '0';
            num = num * 10 + u;
        }
        a[i].id = i;
        a[i].s = num;
    }
    sort(a + 1, a + 1 + n, cmp);
    cout << a[1].id << endl;
}

int main()
{
    solve();
    return 0;
}