#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 510;
int a[N][N];
int e[N][N];
int gauss(){
    int c = 0,r = 0;
    for(c=0;c<n;c++){
        int t = r;
        for(int i=r;i<n;i++){
            if(a[i][c]==1){
                t = i;
                break;
            }
        }
        if(a[t][c]==0) return 1;
        for(int j=0;j<n+1;j++)
            swap(a[t][j],a[r][j]);
        for(int j=0;j<n;j++)
            swap(e[t][j],e[r][j]);
        for(int i=r+1;i<n;i++){
            if(a[i][c]>0){
                for(int j=n;j>=c;j--){
                    a[i][j]^=a[r][j];
                }
                for(int j=n-1;j>=0;j--){
                    e[i][j]^=e[r][j];
                }
            }
        }
        ++r;
    }
    if(r<n) return 1;
    // for(int i=n-1;i>=0;i--){
    //     for(int j=i-1;j>=0;j--){
    //         //a[i][n]^=(a[i][j]*a[j][n]);
    //         if(a[j][i]){
    //             for(int k=0;k<n;k++){
    //                 a[j][k]^=a[i][k];
    //                 e[j][k]^=e[i][k];
    //             }
    //         }
    //     }
    // }
    for (int i=n-1;i>=0;--i){
        for (int j=i+1;j<n;++j){
            if (a[i][j]){
                a[i][n] ^= a[j][n];
                for (int k=0;k<n;++k){
                    a[i][k] ^= a[j][k];
                    e[i][k] ^= e[j][k];
                }
            }
        }
    }
    return 0;
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&a[i][j]);
        }
        e[i][i] = 1;
    }
    int t = gauss();
    if(t==1){
        printf("-1");
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(e[i][j]){
                printf("%d ",j+1);
            }
        }
        printf("\n");
    }
    return 0;
}