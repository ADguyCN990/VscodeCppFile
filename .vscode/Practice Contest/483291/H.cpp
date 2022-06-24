#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define per(i, x, y) for(int i = x; i >= y; i--)
#define pb emplace_back
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

int n;
int a[MAXN];//原数组
int c[MAXN];//树状数组，表示树状数组节点i节点覆盖的范围和

int lowbit(int x)//返回非负整数x在二进制表示下最低位1及其后面的0构成的数值
{
    return x&-x;
}

void add(int x,int k)//将原序列中第x个数加上k
{
    for(int i=x;i<=n;i+=lowbit(i)) c[i]+=k;
}

int ask(int x)//查询序列前x个数的和
{
    int sum=0;
    for(int i=x;i;i-=lowbit(i)) sum+=c[i];
    return sum;
}
void solve() {
    n = read();
    int cnt = 0;
    int mn = INF;
    for (int i = 1; i <= n; i++) {
        int x = read();
        mn = min(mn, x);
        if (mn == x)
            cnt++;
    }
    printf("%d\n", cnt);
}

int main() {
    solve();
    return 0;
}