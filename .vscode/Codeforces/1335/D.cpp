#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 15
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

int a[MAXN][MAXN];
char s[15];
int n = 9;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void solve() {
    for (int i = 1; i <= n; i++) {
        scanf("%s", s + 1);
        for (int j = 1; j <= n; j++) {
            int u = s[j] - '0';
            a[i][j] = u; 
        }
    }
    a[1][1] = a[1][2];
    a[2][4] = a[2][5];
    a[3][7] = a[3][8];
    a[4][2] = a[4][3];
    a[5][5] = a[5][6];
    a[6][8] = a[6][9];
    a[7][3] = a[7][4];
    a[8][6] = a[8][7];
    a[9][9] = a[9][8];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            printf("%d", a[i][j]);
        }
        puts("");
    }
}

int main() {
    int T;
    T = read();
    for (int i = 1; i <= T; i ++) {
        solve();
    }

    return 0;
}