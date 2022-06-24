#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
#define MAXM 1<<9
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

int lowbit(int x) {return x & -x;}

int n=9;
char s[MAXN];
int ones[MAXM];   //某个二进数中包含多少个1
int mp[MAXM];   //lowbit求出来的值最后的1是第几位

//使用二进制状态压缩来记录某个点的可行状态，某一位上为1表示该数可选，一开始重置为 2^9-1表示均可选
int row[15],col[15],g[15][15];

void pre()
{
    for(int i = 0; i<MAXM; i++)
    {
        int cnt = 0;//计数
        int j = i;
        while(j)
        {
            j -= lowbit(j);
            cnt++;
        }
        ones[i] = cnt;
    }
    for(int i = 0; i < n; i++)
    {
        mp[1 << i] = i;// 1 0  10 1 100 2 1000 3
    }
}

void init()
{
    for(int i = 0; i < n; i++) col[i]=row[i]=(1<<9)-1;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            g[i][j] = (1 << 9) - 1;
    
}

int merge(int x,int y)
{
    return row[x] & col[y] & g[x / 3][y / 3];
}

bool dfs(int cnt)
{
    if(!cnt) return true;

    //每次都从可选方案数最少的点开始拓展状态，搜索顺序剪枝

    int mn = INF;   //最少方案数
    int x, y;   //最少方案数的点的坐标
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int k = i * n + j;
            if(s[k] != '.') continue;
            int sum = ones[merge(i, j)];
            if(sum < mn)
            {
                mn = sum;
                x = i;
                y = j;
            }
        }
    }

    //找到了那个点，开始拓展状态

    for(int i = merge(x, y); i; i -= lowbit(i))
    {
        int now = mp[lowbit(i)];//求出某个能取的数

        //拓展状态
        row[x] -= 1 << now;
        col[y] -= 1 << now;
        g[x / 3][y / 3] -= 1 << now;
        s[x * 9 + y] = '1' + now;

        if(dfs(cnt-1)) return true;

        //恢复现场
        row[x] += 1 << now;
        col[y] += 1 << now;
        g[x / 3][y / 3] += 1 << now;
        s[x * 9 + y] = '.';

    }


    return false;
}

void solve()
{
    init();
    int cnt=0;  //有多少个数需要填写
    for(int i = 0, k = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++, k++)
        {
            if(s[k] != '.')
            {
                int now = s[k] - '1';
                int result = 1 << now;
                row[i] -= result;
                col[j] -= result;
                g[i / 3][j / 3] -= result;
            }
            else
                cnt++;
        }
    }
    dfs(cnt);
    puts(s);
}

int main()
{
    pre();
    while(1)
    {
        scanf("%s",s);
        if(s[0]=='e') break;
        solve();
    }

    return 0;
}