#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<int, int> pii;
int n;
bool asknode(int x, int y) {
    cout << "? 1 " << x << " " << y << endl;
    string s;
    cin >> s;
    if (s == "Yes") return true;
    else return false;
}

bool askseg(int x, int y, int xx, int yy) {
    cout << "? 2 " << x << " " << y << " " << xx << " " << yy << endl;
    string s;
    cin >> s;
    if (s == "Yes") return true;
    else return false;
}

bool asktri(int x, int y, int xx, int yy, int a, int b) {
    cout << "? 3 " << x << " " << y << " " << xx << " " << yy << " " << a << " " << b << endl;
    string s;
    cin >> s;
    if (s == "Yes") return true;
    return false;
}

void output(int x, int y) {
    cout << "! " << x << " " << y << endl;
}

int main() {
    cin >> n;
    bool sb = asktri(1, 1, 1, n, n, 1);
    if (sb) {
        //左下角  
        int l = 1, r = n;
        int ans;
        while (l <= r) {
            int mid = l + r >> 1;
            if (asktri(1, 1, 1, mid, mid, 1)) {
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }     
        pii L = {1, ans}, R = {ans, 1};
        while (L.first + 2 <= R.first) {
            int midx = L.first + R.first >> 1;
            int midy = L.second + R.second >> 1;
            if (L.first + 2 <= R.first) break;
            if (askseg(L.first, L.second, midx, midy)) {
                
                R.first = midx - 1;
                R.second = midy + 1;
            }
            else {
                L.first = midx + 1;
                L.second = midy - 1;
            }
        }
        for (int i = L.first; i <= R.first; i++) {
            int x = L.first + (i - L.first);
            int y = L.second - (i - L.first);
            if (asknode(x, y)) {
                output(x, y);
                return 0;
            }
        }
    }
    else {
        //右上角
        int l = 1, r = n;
        int ans;
        while (l <= r) {
            int mid = l + r >> 1;
            if (asktri(n, n, mid, n, n, mid)) {
                ans = mid;
                l = mid + 1;
            }
            else 
                r = mid - 1;
        }
        pii L = {ans, n}, R = {n, ans};
        while (L.first + 2 <= R.first) {
            int midx = L.first + R.first >> 1;
            int midy = L.second + R.second >> 1;
            if (L.first + 2 <= R.first) break;
            if (askseg(L.first, L.second, midx, midy)) {
                
                R.first = midx - 1;
                R.second = midy + 1;
            }
            else {
                L.first = midx + 1;
                L.second = midy - 1;
            }
        }
        for (int i = L.first; i <= R.first; i++) {
            int x = L.first + (i - L.first);
            int y = L.second - (i - L.first);
            if (asknode(x, y)) {
                output(x, y);
                return 0;
            }
        }
    }

    return 0;
}