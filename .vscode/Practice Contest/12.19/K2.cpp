#include <bits/stdc++.h>
using namespace std;
#define double long double
#define ll long long
#define int long long
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
double res;
pdd QQ;
#define xx first
#define yy second
#define ZERO 1e-5

bool inEdge(pii A, pii B, pii P)
{
    bool f1 = (P.yy - B.yy) * (A.xx - B.xx) == (P.xx - B.xx) * (A.yy - B.yy);
    bool f2 = ((P.xx <= A.xx) && (P.xx >= B.xx)) || ((P.xx <= B.xx) && (P.xx >= A.xx));
    return f1 && f2;
}
bool inEdge(pdd A, pdd B, pdd P)
{
    bool f1 = (P.yy - B.yy) * (A.xx - B.xx) == (P.xx - B.xx) * (A.yy - B.yy);
    bool f2 = ((P.xx <= A.xx) && (P.xx >= B.xx)) || ((P.xx <= B.xx) && (P.xx >= A.xx));
    return f1 && f2;
}
double line(pdd A, pdd B)
{
    double len = sqrt((A.xx - B.xx) * (A.xx - B.xx) + (A.yy - B.yy) * (A.yy - B.yy));
    return len;
}
double area(pdd A, pdd B, pdd C)
{
    double AB = line(A, B), BC = line(B, C), AC = line(A, C);
    double p = (AB + BC + AC) / 2;
    double s = sqrt(p * (p - AB) * (p - BC) * (p - AC));
    return s;
}

double dis(pdd P, pdd B, pdd C){
    double down = line(B, C);
    double up = fabs((B.xx-C.xx)*(P.yy-C.yy)-(P.xx-C.xx)*(B.yy-C.yy));
    return up/down;
}

void solve()
{
    pdd A, B, C, P;
    pii AA, BB, CC, PP;
    pdd Q;
    scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &AA.xx, &AA.yy, &BB.xx, &BB.yy, &CC.xx, &CC.yy, &PP.xx, &PP.yy);
    // cin >> A.xx >> A.yy >> B.xx >> B.yy >> C.xx >> C.yy >> P.xx >> P.yy;
    if (inEdge(AA, BB, PP))
    {
        pdd tmp = CC;
        CC = BB;
        BB = tmp;
    }
    else if (inEdge(BB, CC, PP))
    {
        pdd tmp = BB;
        BB = AA;
        AA = tmp;
    }
    else if (!inEdge(AA, CC, PP))
    {
        // cout << -1 << endl;
        puts("-1");
        return;
    }
    A = AA, B = BB, C = CC, P = PP;
    double all = area(A, B, C);
    
    // Q in the BC
    double h1 = dis(P, B, C);
    double bottom = all / h1;
    double rate = bottom / line(B, C);
    

    // Q in the AB
    double h2 = dis(P, A, B);
    double bt2 = all / h2;
    double r2 = bt2 / line(A, B);
    
    if (r2<0 || r2>1){
        Q.xx = C.xx + (B.xx-C.xx)*rate, Q.yy = C.yy + (B.yy-C.yy)*rate;
        printf("%.10Lf %.10Lf\n", Q.xx, Q.yy);
        // cout << fixed << setprecision(10) << Q.xx << " " << Q.yy << endl;
    }
    else{
        QQ.xx = 0.0 + A.xx + (B.xx-A.xx)*r2, QQ.yy = 0.0 + A.yy + (B.yy-A.yy)*r2;
        printf("%.10Lf %.10Lf\n", QQ.xx, QQ.yy);
        // cout << fixed << setprecision(10) << QQ.xx << " " << QQ.yy << endl;
    }
    
}

signed main(void)
{
    int t;
    scanf("%lld", &t);
    while (t--)
    {
        solve();
    }
    return 0;
}