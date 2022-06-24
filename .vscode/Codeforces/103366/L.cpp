#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
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
int dx[MAXN];
int n;
void solve()
{
    int a, b, c, d, mx;
    int n;
    mx = 0;
    n = read();
    for (int i = 1; i <= n; i ++)
    {
        a = read(), b = read(), c = read(), d = read();
        dx[a] ++, dx[c + 1] --;
        mx = max({mx, a, c});
    }
    for (int i = 1; i <= mx; i ++)
    {
        cout <<dx[i] <<" ";
    }
    cout << endl;
    int cnt = 0;
    int sum = 0;
    for (int i = 1; i <= n; i ++)
    {
        int pre = sum;
        sum += dx[i];
        if (sum == 0 || pre == 0) cnt ++;
    }
    printf("%d\n", cnt);
}

int main()
{
    solve();
    return 0;
}