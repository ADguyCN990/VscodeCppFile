#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
const int N = 1e4 + 4;
int a[N];

int main(void){
    scanf("%d", &n);
    a[1] = 1, a[5] = 1, a[13] = 1;
    for (int i=1;i<=13;++i){
        if (i % 2){
            a[i] = 1;
        }
    }
    for (int i=14;i<N;++i){
        if (a[i - 1] || a[i - 5] || a[i - 13]){
            ;
        }
        else{
            a[i] = 1;
        }
    }
    if (a[n] == 1){
        puts("2");
    }
    else puts("1");
    return 0;
}