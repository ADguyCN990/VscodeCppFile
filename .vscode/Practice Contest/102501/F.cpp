#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define pi acos(-1.0)
const int N = 500010;
const double eps = 1e-8;

inline bool equals(double a, double b) {
    return fabs(a - b) < eps;
}

struct Point {
    double x, y;
    Point() {}
    Point(double x, double y) :x(x), y(y) {};
    Point operator + (Point& b) {
        return Point(x + b.x, y + b.y);
    }
    Point operator - (Point& b) {
        return Point(x - b.x, y - b.y);
    }
    Point operator * (double k) {
        return Point(x * k, y * k);
    }
    Point operator / (double k) {
        return Point(x / k, y / k);
    }
    bool operator < (Point b) {
        return equals(x, b.x) ? y < b.y : x < b.x;
    }
};
typedef vector<Point> polygon;
typedef Point Vector;
inline double cross(Vector a, Vector b) {
    return a.x * b.y - a.y * b.x;
}

inline double Ploygon_area(polygon s) {
    int n = s.size();
    double ans = 0.0;
    for (int i = 0; i < n; i++)
        ans += cross(s[i], s[(i + 1) % n]);
    return ans * 0.5;
}

double solve() {
    polygon s;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        double x, y;
        cin >> x >> y;
        s.push_back(Point(x, y));
    }
    double tmp = Ploygon_area(s);
    if (tmp < 0.0) return -tmp;
    return tmp;
}

int main() {
    int t;
    cin >> t;
    double ans = 0.0;
    while (t--)
        ans += solve();
    
    long long res = ans;
    printf("%lld\n", res);
    return 0;
}