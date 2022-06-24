#include <bits/stdc++.h>
using namespace std;

int n;
const int N = 2e5 + 10;
char a[N];
char b[5] = {'e','d','g','n','b'};

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int cnt = 0;
    cin >> a+1;
    n = strlen(a+1);
    for (int i=1;i<=n;++i){
        if (a[i]==b[0]){
            int j=i, cur = 0;
            for (j=i;j<=n&&j<i+5;++j){
                if (a[j]==b[j-i]){
                    cur++;
                }
            }
            if (cur >= 5){
                cnt++;
            }
        }
    }
    cout <<cnt << endl;

    return 0;
}