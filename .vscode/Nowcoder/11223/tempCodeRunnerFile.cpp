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

struct node {
    int id;
    int val;
    friend bool operator< (node a, node b) {
        return a.val < b.val;
    }
}a[MAXN];

struct block {
    int cnt;
    int val;
}b[MAXN];

int ans = INF;//大于等于ans的都能胜利

int n, k, cnt;
int st[MAXN];
void solve() {
    n = read(), k = read();
    for (int i = 1; i <= n; i++) {
        a[i].val = read();
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n);
    cnt = 1;
    b[1].val = a[1].val;
    b[1].cnt = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i].val == a[i - 1].val) 
            b[cnt].cnt++;
        else
            b[++cnt].val = a[i].val, b[cnt].cnt = 1;
    }
    int now = 0; //目前能打败的人数
    for (int i = 1; i <= cnt; i++) {
        now += b[i].cnt - 1;
        int tmp = now;
        if (tmp >= k) {
            ans = b[i].val;
            break;
        }
        int nxtcnt = b[i + 1].cnt;
        if (nxtcnt >= 2) {
            if (b[i].val * 2 >= b[i + 1].val)
                tmp += 2;
            else if (b[i].val * 2 < b[i + 1].val && b[i].val > b[i + 1].val / 2)
                tmp++;
            else if (b[i].val * 2 > b[i + 2].val / 2)
                tmp++;
            if (tmp >= k) {
                ans = b[i].val;
                break;
            }
        }
        else if (nxtcnt == 1) {
            if (b[i].val * 2 >= b[i + 1].val && b[i].val >= b[i + 2].val / 2)
                tmp += 2;
            else if (b[i].val * 2 >= b[i + 1].val / 2)
                tmp++;
            if (tmp >= k) {
                ans = b[i].val;
                break;
            }
        }
        now++; //把自己补上
    }
    for (int i = 1; i <= n; i++)
        if (a[i].val >= ans)
            st[a[i].id] = 1;
    for (int i = 1; i <= n; i++) printf("%d ", st[i]);
}

int main() {
    solve();
    return 0;
}