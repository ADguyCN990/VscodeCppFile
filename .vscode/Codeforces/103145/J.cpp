#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi acos(-1)
int read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

struct node {
    double x, y, z;
};

node get(double x, double y, double z, double xx, double yy, double zz, double th) {
    double r = th * pi / 180;
    double c = cos(r);
    double s = sin(r);
    double nx = (xx * xx * (1 - c) + c) * x + (xx * yy * (1 - c) - zz * s) * y + (xx  *zz * (1 - c) + yy * s) * z;
    double ny = (yy * xx * (1 - c) + zz * s) * x + (yy * yy * (1 - c) + c) * y + (yy * zz * (1 - c) - xx * s) * z;
    double nz = (xx * zz * (1 - c) - yy * s) * x + (yy * zz * (1 - c) + xx * s) * y + (zz * zz * (1 - c) + c) * z;
    return node{nx, ny, nz};
}

void solve() {
    int a, b, c, x, y, z, r;
    a = read(), b = read(), c = read(), x = read(), y = read(), z = read(), r = read();
    double len = sqrt(a * a + b * b + c * c);
    node p1 = get(x, y, z, a / len, b / len, c / len, r);
    node p2 = get(x, y, z, a / len, b / len, c / len, -r);
    if (p1.z > p2.z) {
		printf("%.9f %.9f %.9f\n", p1.x, p1.y, p1.z);
	}
	else {
		printf("%.9f %.9f %.9f\n", p2.x, p2.y, p2.z);
	}
    
}

int main() {
    int t = read();
    while (t--)
        solve();
    return 0;
}