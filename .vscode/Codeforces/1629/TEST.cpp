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
int a[6][6];

void work(int x, int y)
{
    a[x + 1][y] ++;
    a[x - 1][y] ++;
    a[x][y + 1] ++;
    a[x][y - 1] ++;
}

void solve()
{
    work(1, 1), work(2, 2), work(3, 3), work(4, 4), work(5, 5);
    work(1, 5), work(2, 4), work(4, 2), work(5, 1);
    work(3, 2), work(3, 4), work(2, 1), work(2, 5), work(4, 1), work(4, 5);
    for (int i = 1; i <= 5; i ++)
    {
        for (int j = 1; j <= 5; j ++)
        {
            printf("%d ", a[i][j]);
        }
        puts("");
    }
}

int main()
{
    solve();
    return 0;
}