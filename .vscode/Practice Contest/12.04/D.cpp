#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define double long double 
double n,p1,p2,v1,v2;
double ans[5];
#define ZERO 1e-12

double check(double x){
    double t11 = (x-p1)/v1;
    double t12 = x/v1;
    double t21 = (p2-x)/v2;
    double t22 = (n-x)/v2;
    double all = max(t11 + t12 , t21 + t22);

    return all;
}

double todo(){
    double le = p1, ri = p2;
    while (ri - le > ZERO){
        double m1 = le + (ri - le)/3.0;
        double m2 = le + (ri - le)/3.0*2.0;
        if (check(m1) > check(m2)){
            le = m1;
        }
        else{
            ri = m2;
        }
    }
    return check(le);
}

double check2(double x){
    double t11 = p1/v1;
    double t12 = x/v1;
    double t21 = (p2-x)/v2;
    double t22 = (n-x)/v2;
    double all = max(t11 + t12 , t21 + t22);

    return all;
}

double todo2(){
    double le = p1, ri = p2;
    while (ri - le > ZERO){
        double m1 = le + (ri - le)/3.0;
        double m2 = le + (ri - le)/3.0*2.0;
        if (check2(m1) > check2(m2)){
            le = m1;
        }
        else{
            ri = m2;
        }
    }
    return check2(le);
}

double check3(double x){
    double t11 = (x-p1)/v1;
    double t12 = x/v1;
    double t21 = (n-p2)/v2;
    double t22 = (n-x)/v2;
    double all = max(t11 + t12 , t21 + t22);

    return all;
}

double todo3(){
    double le = p1, ri = p2;
    while (ri - le > ZERO){
        double m1 = le + (ri - le)/3.0;
        double m2 = le + (ri - le)/3.0*2.0;
        if (check3(m1) > check3(m2)){
            le = m1;
        }
        else{
            ri = m2;
        }
    }
    return check3(le);
}

void solve()
{
    cin>>n>>p1>>v1>>p2>>v2;
    if(p1>p2)
    {
        swap(p1,p2);
        swap(v1,v2);
    }
    // 同向左
    double t11 = p1/v1;
    double t2 = min((n-p2)/v2, p2/v2) + n/v2;
    if (t11 >= t2){
        ans[1] = t2;
    }
    else{
        double t22 = min((p2-p1)/v2, (n-p2)/v2) + (n-p1)/v2;
        ans[1] = max(t11, t22);
    }
    double a2 = todo2();
    ans[1] = min(ans[1], a2);

    // 同向右
    double t21 = (n-p2)/v2;
    double t1 = min((n-p1)/v1, p1/v1) + n/v1;
    if (t21 >= t1){
        ans[2] = t1;
    }
    else{
        double t12 = min((p2-p1)/v1, p1/v1) + p2/v1;
        ans[2] = max(t21, t12);
    }
    double a3 = todo3();
    ans[2] = min(ans[2], a3);

    // 面对
    // 各自不改变朝向
    double tmp1 = max((n-p1)/v1, p2/v2);
    // 2次改变朝向
    double tmp2 = todo();
    ans[3] = min(tmp1, tmp2);

    // 背对
    ans[4] = (n+p1+n-p2)/(v1+v2);

    double res = ans[1];
    for (int i=2;i<5;++i){
        res = min(res, ans[i]);
    }
    cout << fixed << setprecision(11) << res << endl;

    // cout << "!!    " << a2 << " " << a3 << endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}