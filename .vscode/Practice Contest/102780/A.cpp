#include <bits/stdc++.h>
using namespace std;
#define ll long long

int t1, t2;

int main(void){
    scanf("%d%d", &t1, &t2);
    int mn = 1e9 + 7, res1 = 0, res2 = 0;
    for (int v1=0;v1<=1000;++v1){
        int up = t1 * v1 - 80 * v1;
        int down = 80 - t2;
        if (up % down == 0){
            int v2 = up / down;
            if (v1 == 0 && v2 == 0) continue;
            if (v1 + v2 <= mn){
                mn = v1 + v2, res1 = v1, res2 = v2;
                
            }
        }
    }
    printf("%d %d\n", res1, res2);
    return 0;

}