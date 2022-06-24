#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 80005
vector<int> num;
int read() {
    int x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
int find(int x) {
    return lower_bound(num.begin(), num.end(), x) - num.begin() + 1;
}

struct Query {
    int opt;
    int num;
}q[MAXN];

struct node {
    int l, r, cnt;
}tree[MAXN << 5];
int n;
int rt[MAXN], idx;

int build(int l, int r) {
    int now = ++idx;
    tree[now].cnt = 0;
    if (l < r) {
        int mid = l + r >> 1;
        tree[now].l = build(l, mid);
        tree[now].r = build(mid + 1, r);
        return now;
    }
    return now;
}

int insert(int pre, int L, int R, int pos) {
    int now = ++idx;
    tree[now] = tree[pre];
    tree[now].cnt++;
    if (L < R) {
        int mid = L + R >> 1;
        if (pos <= mid) tree[now].l = insert(tree[pre].l, L, mid, pos);
        if (pos >= mid + 1) tree[now].r = insert(tree[pre].r, mid + 1, R, pos);
        return now;
    }
    return now;
}

int remove(int pre, int L, int R, int pos) {
    int now = ++idx;
    tree[now] = tree[pre];
    tree[now].cnt--;
    if (L < R) {
        int mid = L + R >> 1;
        if (pos <= mid) tree[now].l = remove(tree[pre].l, L, mid, pos);
        if (pos >= mid + 1) tree[now].r = remove(tree[pre].r, mid + 1, R, pos);
        return now;
    }
    return now;
}

int query(int rt, int L, int R) {
    if (L == R) {
        return L;
    }
    int mid = L + R >> 1;
    if (tree[tree[rt].r].cnt > 0) return query(tree[rt].r, mid + 1, R);
    else if (tree[tree[rt].l].cnt > 0) query(tree[rt].l, L, mid);
    else return -1;
}

int main() {
    n = read();
    for (int i = 1; i <= n; i++) {
        char s[10];
        int x;
        scanf("%s", s);
        if (s[0] == 'a') {
            scanf("%d", &x);
            q[i].opt = 1;
            q[i].num = x;
            num.push_back(x);
        }
        else if (s[0] == 's') {
            q[i].opt = 2;
            q[i].num = 0;
        }
        else {
            scanf("%d", &x);
            q[i].opt = 3;
            q[i].num = x;
            num.push_back(x);
        }
    }
    sort(num.begin(), num.end());
    num.erase(unique(num.begin(), num.end()), num.end());
    int len = num.size();
    rt[0] = build(1, len);
    stack<int> st;
    puts("");
    for (int i = 1; i <= n; i++) {
        if (q[i].opt == 1) {
            st.push(q[i].num);
            rt[i] = insert(rt[i - 1], 1, len, find(q[i].num));
            int pos = query(rt[i], 1, len);
            if (pos == -1) {
                puts("-1");
                continue;
            }
            printf("%d\n", num[pos - 1]);
        }
        else if (q[i].opt == 2) {
            int x = st.top();
            st.pop();
            rt[i] = remove(rt[i - 1], 1, len, find(x));
            int pos = query(rt[i], 1, len);
            if (pos == -1) {
                puts("-1");
                continue;
            }
            printf("%d\n", num[pos - 1]);
        }
        else {
            rt[i] = rt[q[i].num - 1];
            int pos = query(rt[i], 1, len);
            if (pos == -1) {
                puts("-1");
                continue;
            }
            printf("%d\n", num[pos - 1]);
        }
    }
    return 0;
}