#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n;
const int N = 100 + 5;
int r1[N], r2[N], d[N];

void test(int r1[]){
    for (int i=1;i<n;++i){
        for (int j=i+1;j<=n;++j){
            if (j - i > 1){
                r1[j]++;
            }
            else{
                if (rand() % 2 == 0){
                    r1[j]++;
                }
                else r1[i]++;
            }
        }
    }
}

int main(void){
    n = 5;
    srand(time(0));
    while (true){
        test(r1);
        test(r2);
        for (int i=1;i<=n;++i){
            d[i] = abs(r1[i] - r2[i]);
            printf(i==n?"%d\n":"%d ", d[i]);
        }
    }
    
    
    printf("!!!  ");
    

    return 0;
}