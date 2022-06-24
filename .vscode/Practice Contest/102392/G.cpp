#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m, h;
const int N = 100 + 5;
int L[N][N], R[N][N];
char s[N];
struct node{
    int x, y, z;
};
vector<node> ve;
bool st[N][N][N];
bool check(int x, int y, int z);

int main(){
    scanf("%d%d%d", &n, &m, &h);
    for (int i=0;i<n;++i){
        scanf("%s", s);
        for (int j=0;j<m;++j){
            // scanf("%d", &L[i][j]);
            L[i][j] = s[j] - '0';
        }
    }
    for (int i=0;i<n;++i){
        scanf("%s", s);
        for (int j=0;j<h;++j){
            // scanf("%d", &R[i][j]);
            R[i][j] = s[j] - '0';
        }
    }
    for (int i=n-1;i>=0;--i){
        for (int j=0;j<m;++j){
            for (int k=0;k<h;++k){
                if (check(i, j, k)){
                    ve.push_back(node{i, j, k});
                    st[i][j][k] = true;
                }
            }
        }
    }
    int kmax = ve.size();
    printf("%d\n", kmax);
    for (int i=0;i<kmax;++i){
        printf("%d %d %d\n", n - 1 - ve[i].x, ve[i].y, ve[i].z);
    }
    for (int i=n-1;i>=0;--i){
        for (int j=m-1;j>=0;--j){
            for(int k=h-1;k>=0;--k){
                
            }
        }
    }

    return 0;
}

bool check(int x, int y, int z){
    if (L[(n - 1 - x)][y] == 1 && R[n - 1 - x][z] == 1){
        return true;
    }
    return false;
}