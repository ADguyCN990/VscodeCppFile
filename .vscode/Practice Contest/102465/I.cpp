#include <bits/stdc++.h>
using namespace std;
#define ll long long

int n, m;
int x, y;
const int N = 1000 + 5;
char s[N][N];
int U[N], pre[N][N];
bool a[N][N];

bool check(int i, int j);
bool checkA(int i, int j);
bool checkB(int i, int j);
bool checkC(int i, int j);
bool checkE(int i, int j);
bool ok(int i, int j);
int cal(int X1, int Y1, int X2, int Y2);


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> m >> n;
    int cntA = 0, cntB = 0, cntC = 0;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            cin >> s[i][j];
            if (s[i][j] == '#'){
                a[i][j] = true;
            }
            else a[i][j] = false;
            pre[i][j] = pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1] + a[i][j];
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (a[i][j]){
                U[j]++;
            }
            else U[j] = 0;
        }
        for (int j=1;j<=m;++j){
            int k = j;
            if (U[k] == 0) continue;
            while (k<=m && U[k]==U[j]) ++k;
            
            x = k - j, y = (U[j] - 3 * x) / 2;
            if (y > 0 && 3 * x + 2 * y == U[j]){
                if (!check(i, j)) continue;
                if (!checkE(i, j)) continue;
                if (checkA(i, j)){
                    cntA++;
                }
                if (checkB(i, j)){
                    cntB++;
                }
                if (checkC(i, j)){
                    cntC++;
                }
            }
            j = k - 1;
        }
    }

    cout << cntA << " " << cntB << " " << cntC << endl;

    return 0;
}

bool ok(int i, int j){
    return i <= n && j <= m && i > 0 && j > 0;
}

bool check(int i, int j){
    return ok(i - 3 * x - 2 * y, j - 1) && ok(i + 1, j + 2 * x + y);
}

int cal(int X1, int Y1, int X2, int Y2){
    return pre[X2][Y2] - pre[X1 - 1][Y2] - pre[X2][Y1 - 1] + pre[X1 - 1][Y1 - 1];
}

bool checkE(int i, int j){
    bool f1 = (cal(i - 3 * x - 2 * y, j - 1, i - 3 * x - 2 * y, j + 2 * x + y) == 0);
    bool f2 = (cal(i - 3 * x - 2 * y, j - 1, i + 1, j - 1) == 0);
    bool f3 = (cal(i + 1, j - 1, i + 1, j + 2 * x + y) == 0);
    bool f4 = (cal(i - 3 * x - 2 * y, j + 2 * x + y, i + 1, j + 2 * x + y) == 0);
    return f1 && f2 && f3 && f4;
}

bool checkA(int i, int j){
    bool f1 = (cal(i - 3 * x - 2 * y + 1, j + x, i - 2 * x - 2 * y, j + x + y - 1) == x * y);
    bool f2 = (cal(i - 2 * x - y + 1, j + x , i - x - y, j + x + y - 1) == x * y);
    bool f3 = (cal(i - 3 * x - 2 * y + 1, j + x + y, i, j + 2 * x + y - 1) == x * (3 * x + 2 * y));
    bool f5 = (cal(i - 2 * x - 2 * y + 1, j + x, i - 2 * x - y, j + x + y - 1) == 0);
    bool f6 = (cal(i - x - y + 1, j + x, i , j + x + y - 1) == 0);
    return f1 && f2 && f3 && f5 && f6;
}

bool checkB(int i, int j){
    bool f1 = (cal(i - 3 * x - 2 * y + 1, j + x, i - 2 * x - 2 * y, j + x + y - 1) == x * y); 
    bool f2 = (cal(i - 2 * x - y + 1, j + x, i - x - y, j + x + y - 1) == x * y);
    bool f3 = (cal(i - x + 1, j + x, i, j + x + y - 1) == x * y);
    bool f4 = (cal(i - 3 * x - 2 * y + 1, j + x + y, i, j + 2 * x + y - 1) == x * (3 * x + 2 * y));
    bool f5 = (cal(i - 2 * x - 2 * y + 1, j + x, i - 2 * x - y, j + x + y - 1) == 0);
    bool f6 = (cal(i - x - y + 1, j + x, i - x, j + x + y - 1) == 0); 
    return f1 && f2 && f3 && f4 && f5 && f6;
}

bool checkC(int i, int j){
    bool f1 = (cal(i - 3 * x - 2 * y + 1, j + x, i - 2 * x - 2 * y, j + 2 * x + y - 1) == (x + y) * x);
    bool f2 = (cal(i - x + 1, j + x, i, j + 2 * x + y - 1) == (x + y) * x);
    bool f3 = (cal(i - 2 * x - 2 * y + 1, j + x, i - x, j + 2 * x + y - 1) == 0);
    return f1 && f2 && f3;
}