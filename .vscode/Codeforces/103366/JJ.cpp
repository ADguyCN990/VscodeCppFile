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
int n, k;
int a[MAXN];
map <int, int> idx;

bool check(int mid)
{
    set <pii> ss; // first表示编号（最近访问时间），second表示a[i]
    idx.clear();
    int cnt = 0; //表示贡献
    for (int i = 1; i <= n; i ++)
    {
        if (idx.count(a[i])) //之前已经出现过，发生冲突
        {
            cnt ++;
            ss.erase({idx[a[i]], a[i]});
            ss.insert({i, a[i]}); //修改最近访问时间
            idx[a[i]] = i;
            continue;
        }
        if (ss.size() == mid) //队列满了，排出队头
        {
            pii head = *ss.begin();
            idx.erase(head.second);
            ss.erase(head);
        }
        // 推入队列
        ss.insert({i, a[i]});
        idx[a[i]] = i;
    }
    return cnt >= k; 
}

void solve()
{
    n = read(), k = read();
    for (int i = 1; i <= n; i ++) a[i] = read();
    int l = 1, r = n, ans = -1;
    while (l <= r) //二分容量大小
    {
        int mid = l + r >> 1;
        if (check(mid))
        {
            ans = mid;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    if (ans == -1) puts("cbddl");
    else printf("%d\n", ans);
}

int main()
{
    solve();
    return 0;
}