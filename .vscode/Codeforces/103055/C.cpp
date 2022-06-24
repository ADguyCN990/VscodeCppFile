    #include<bits/stdc++.h>
    using namespace std;
    #define ll long long
    int n = 8;
    struct node {
        ll x, y, z;
    }a[10];

    ll dis(int i, int j) {
        return (a[i].x - a[j].x) * (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y) + (a[i].z - a[j].z) * (a[i].z - a[j].z);
    }

    void solve() {
        for (int i = 1; i <= n; i++) {
            cin >> a[i].x >> a[i].y >> a[i].z;
        }
        vector<ll> ans;
        for (int i = 1; i <= n; i++) {
            for (int j = i + 1; j <= n; j++) {
                ans.push_back(dis(i, j));
            }
        }
        sort(ans.begin(), ans.end());
        ll one = ans[0], two = one * 2, three = one * 3;
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i] == one)
                a++;
            else if (ans[i] == two)
                b++;
            else if (ans[i] == three)
                c++;
        }
        if (a == 12 && b == 12 && c == 4) {
            puts("YES");
        }
        else
            puts("NO");
    }

    int main() {
        int t;
        cin >> t;
        while (t--)
            solve();
        return 0;
    }