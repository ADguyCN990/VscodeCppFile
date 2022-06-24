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
char mt[MAXN];
int nxt[MAXN];
void init(){
    nxt[0] = -1;
    int mtlen = strlen(mt);
    for (int i=1;i<mtlen;i++){
        int temp = nxt[i-1];
        while(mt[temp+1] != mt[i] && temp > -1){
            temp = nxt[temp];
        }
        if (mt[temp+1]==mt[i]) nxt[i] = temp + 1;
        else nxt[i] = -1;
    }
}

void solve()
{
    int len;
    len = read();
    scanf("%s", mt);
    init();
    for (int i = 1; i <= len; i ++) printf("%d\n", nxt[i]);
}

int main()
{
    solve();
    return 0;
}