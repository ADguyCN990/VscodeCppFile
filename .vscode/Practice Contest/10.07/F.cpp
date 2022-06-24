#include <bits/stdc++.h>
using namespace std;

int n, m;
const int Max_n = 1e1 + 10;
const double ZERO = 1e-6;
double L[Max_n], R[Max_n];

bool check(double x){
	double ans = 0;
	for (int i=1;i<=n;++i){
        if (x >= R[i]){
            ans = ans + 1;
        }
		else if (x >= L[i]){
			ans = ans + (x-L[i])/(R[i]-L[i]);
		}
	}
	if (ans>=m){
		return true;
	}
	return false;
}

int main(void){
	scanf("%d%d", &n,&m);
	double le=0.0, ri = 1e9+10, mid;
    for (int i=1;i<=n;++i){
        scanf("%lf%lf", &L[i], &R[i]);
    }
	while (ri - le > ZERO){
		mid = (le+ri)/2.0;
		if (check(mid)){
			ri = mid;
		}
		else le = mid;
	}
	printf("%.10lf", le);
    return 0;
}