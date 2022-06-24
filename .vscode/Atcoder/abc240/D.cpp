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
    int cnt;
};
void solve() {
    int n = read();
    stack<node> st;
    for (int i = 1; i <= n; i++) {
        int x = read();
        node tmp;
        if (i == 1 || st.empty()) {
            tmp.id = x;
            tmp.cnt = 1;
            st.push(tmp);
            puts("1");
            continue;
        }
        node pre = st.top();
        if (x == pre.id) {
            tmp.id = x;
            tmp.cnt = pre.cnt + 1;
            st.push(tmp);
            if (st.size() && st.top().cnt == x) {
                while (st.size() && st.top().id == x) st.pop();
            }
        }
        else {
            tmp.id = x;
            tmp.cnt = 1;
            st.push(tmp);
        }
        if (st.empty())
            puts("0");
        else
            printf("%d\n", st.size());
    }
}

int main() {
    solve();
    return 0;
}