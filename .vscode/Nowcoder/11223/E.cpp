#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

ll n, k;
struct node {
    int id;
    int val;
    friend bool operator< (node a, node b) {
        return a.val < b.val;
    }
}a[MAXN];
int q[MAXN];
int findx(int x) {
    int l = 1, r = n;
    int ans;
    while (l <= r) {
        int mid = l + r >> 1;
        if (a[mid].val <= x) {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    return ans;
}

int main() {
    n = read(), k = read();
    for (int i = 1; i <= n; i++) {
        a[i].val = read();
        a[i].id = i;
    }
    sort(a + 1, a + 1 + n);
    //[1, 4 * k + 2]
    for (int i = 1; i <= n; i++) {
        int pos = findx(4 * a[i].val + 2);
        if (pos - 1 >= k) q[a[i].id] = 1;
    }
    for (int i = 1; i <= n; i++) printf("%d ", q[i]);
    return 0;
}