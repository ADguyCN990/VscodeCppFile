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
int cnt[15];
int sum, mx, mxid;
bool check()
{
    sum = 0;
    mx = 0;
    mxid = 0;
    for (int i = 0; i <= 9; i ++)
    {
        if (cnt[i] > mx)
        {
            mx = cnt[i];
            mxid = i;
        }
        sum += cnt[i];
    }
    if (mxid == 0)
    {
        if (mx > sum / 2) return false;
        return true;
    }

    if (mx > (sum + 1) / 2)
        return false;
    return true;
}

void solve()
{
    for (int i = 0; i <= 9; i ++) cnt[i] = read();
    bool flag = check();
    if (!flag)
    {
        puts("-1");
        return;
    }
    if (sum == 0)
    {
        puts("-1");
        return;
    }
    int now = 0; //当前选择的数
    int to = 0;
    for (int j = 1; j <= sum; j ++)
    {
        
        int left = sum - j + 1;
        if (j % 2 == 1 && now == mxid || j % 2 == 0 && to == mxid) 
        {
            if (j % 2 == 1) left -= cnt[now];
            else left -= cnt[to];
        }
        if (cnt[mxid] * 2 - 1 == left)
        {
            int num = cnt[mxid] - 1;
            for (int k = 1; k <= num; k ++)
            {
                while(cnt[now] == 0 || now == mxid ) now ++;
                printf("%d %d ", mxid, now);
                cnt[now] --;
            }
            printf("%d\n", mxid);
            return;
        }
        if (j == 1)
        {
            while (now == 0 || cnt[now] == 0) now ++;
            printf("%d \n", now);
            cnt[now] --;
            continue;
        }
        if (j == 2)
        {
            while (cnt[to] == 0 || now == to) to ++;
            printf("j: %d \n", to);
            cnt[to] --;
            continue;
        }
        else if (j % 2 == 1)
        {
            while (cnt[now] == 0 || now == to) now ++;
            printf("%d \n", now);
            cnt[now] --;
        }
        else if (j % 2 == 0)
        {
            while (cnt[to] == 0 || now == to) to ++;
            printf("!!!%d \n", to);
            cnt[to] --;
        }
        
    }
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