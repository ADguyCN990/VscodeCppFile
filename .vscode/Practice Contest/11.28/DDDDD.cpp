#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
char s[MAXN];
int nxt[MAXN];
int d[MAXN];//差分数组

int q,n;
void getnext()
{
    nxt[1] = 0;
    int j = 0;
    for(int i=1;i<=n;i++)
    {
        while(j >= 1 && s[j] != s[i])
        {
            j = nxt[j-1];
        }
        if(s[j] == s[i]) j++;
        nxt[i] = j;
    }
    return;
}

void gettnext()//预处理next[str.length()]的next值不为0的数量
{
    int j=n;
    while(j > 0)
    {
        d[nxt[j]] += 1;
        j = nxt[j]-1;
    }
    d[0] = 0;
    for(int i=1;i<=n;i++)
    {
        d[i] += d[i-1];
    }
}

void solve()
{
    scanf("%s",s);
    n=strlen(s)-1;
    getnext();
    gettnext();
    scanf("%d",&q);
    while(q--)
    {
        int x;
        scanf("%d",&x);
        x=min(x-1,n-x+1);
        printf("%d\n",d[x]);
    }
}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}