#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005

int S, L, n;
string s[MAXN];
string ss[MAXN];
bool vis[505][505];
int last[MAXN];
map<string, int> mp;
int ans[MAXN];
int indgr[MAXN];

struct node {
    int id;
    int val;
    bool operator< (const node &a) const {
        return val > a.val;
    }
}a[MAXN];

int head[MAXN], tot;
struct EDGE {
    int to, next;
}edge[20000005];
void add(int from, int to) {
    edge[++tot].to = to, edge[tot].next = head[from], head[from] = tot;
}

void topu() {
    priority_queue<node> q;
    for (int i = 1; i <= n; i++)
        if (!indgr[i])
            q.push(a[i]);
    int cnt = 0;
    while (q.size()) {
        int now = q.top().id;
        int val = q.top().val;
        //cout << "val: " << s[val] << "\n";
        //cout << cnt << endl;
        ans[++cnt] = now;
        //cout << ans[cnt] << endl;
        q.pop();
        for (int i = head[now]; i; i = edge[i].next) {
            int to = edge[i].to;
            indgr[to]--;
            if (!indgr[to])
                q.push(a[to]);
        }
    }
    
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> S >> L >> n;
    for (int i = 1; i <= S; i++) cin >> s[i];
    sort(s + 1, s + 1 + S);
    for (int i = 1; i <= S; i++) mp[s[i]] = i;
    for (int i = 1; i <= S; i++) last[i] = -1;
    for (int i = 1; i <= L; i++) {
        string x, y;
        cin >> x >> y;
        int u = mp[x], v = mp[y];
        vis[u][v] = vis[v][u] = true;
    }

    for (int i = 1; i <= n; i++) {
        string t;
        cin >> t;
        a[i].val = mp[t], a[i].id = i;
        for (int j = 1; j <= S; j++) {
            if (last[j] < 0 || vis[j][a[i].val]) continue;
            add(last[j], i);
            indgr[i]++;
        }
        last[a[i].val] = i;
    }
    topu();
    for (int i = 1; i <= n; i++) {
        cout << s[a[ans[i]].val] << " ";
    }
    cout << endl;
    return 0;
}