#include <bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<double, double> pii;
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

void solve()
{
    pii A, B, C, P;
    pdd Q;
    cin >> A.xx >> A.yy >> B.xx >> B.yy >> C.xx >> C.yy >> P.xx >> P.yy;
    if (inEdge(A, B, P))
    {
        pii tmp = C;
        C = B;
        B = tmp;
    }
    else if (inEdge(B, C, P))
    {
        pii tmp = B;
        B = A;
        A = tmp;
    }
    else if (!inEdge(A, C, P))
    {
        cout << -1 << endl;
        return;
    }
    double le = 0, ri = 1.0, mid = 0, ans = 0;
    double all = area(A, B, C);
    if (line(P, A) > line(P, C))
    {
        pdd mA = min(A, B), mB = max(A, B);
        while (ri - le > ZERO)
        {
            mid = (le + ri) / 2.0;
            // cout << "mid: " << mid << endl;
            Q.xx = mA.xx + (mB.xx - mA.xx) * mid, Q.yy = mA.yy + (mB.yy - mA.yy) * mid;
            double APQ = area(mA, P, Q);
            if (all - APQ - APQ > ZERO)
            {
                le = mid;
            }
            else
            {
                ri = mid;
            }
        }
        QQ.xx = mA.xx + (mB.xx - mA.xx) * le, QQ.yy = mA.yy + (mB.yy - mA.yy) * le;

        cout << fixed << setprecision(10) << QQ.xx << " " << QQ.yy << endl;
        return ;
    }

    // pdd mA = min(A, B), mB = max(A, B);
    // while (ri - le > ZERO){
    //     mid = (le+ri)/2.0;
    //     // cout << "mid: " << mid << endl;
    //     Q.xx = mA.xx+(mB.xx-mA.xx)*mid, Q.yy = mA.yy+(mB.yy-mA.yy)*mid;
    //     double APQ = area(mA, P, Q);
    //     if (all - APQ - APQ > ZERO){
    //         le = mid;
    //     }
    //     else{
    //         ri = mid;
    //     }
    // }
    // QQ.xx = mA.xx+(mB.xx-mA.xx)*le, QQ.yy = mA.yy+(mB.yy-mA.yy)*le;
    // ans = area(mA, P, QQ);
    // res = ans;
    // cout << "all: " << all << " ans: " << ans << endl;
    // if (fabs(all - ans - ans) < ZERO){
    //     cout << Q.xx << " " << Q.yy << endl;
    //     return;
    // }

    // B C
    le = 0, ri = 1.0;
    pdd mC = min(C, B);
    pdd mB = max(C, B);
    while (ri - le > ZERO)
    {
        mid = (le + ri) / 2;
        Q.xx = mC.xx + (mB.xx - mC.xx) * mid, Q.yy = mC.yy + (mB.yy - mC.yy) * mid;
        double CPQ = area(mC, P, Q);
        if (all - CPQ - CPQ > ZERO)
        {
            le = mid;
        }
        else
        {
            ri = mid;
        }
    }
    Q.xx = mC.xx + (mB.xx - mC.xx) * le, Q.yy = mC.yy + (mB.yy - mC.yy) * le;
    ans = area(mC, P, Q);
    // if (fabs(all - ans - ans) < ZERO){
    //     cout << Q.xx << " " << Q.yy << endl;
    //     return;
    // }
    // cout << all << " " << ans << endl;
    cout << fixed << setprecision(10) << Q.xx << " " << Q.yy << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    // cout << area(pdd(1,0), pdd(0,0), pdd(0.5,0.5)) << endl;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}