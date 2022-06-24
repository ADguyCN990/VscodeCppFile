#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
#define MAXM 200005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f

int n, k;
const int N = 500 + 10;
double s[N], ans[N];

void solve()
{
    cin >> n >> k;
    for (int i=0;i<n;++i){
        cin >> s[i];
    }
    int num = n - k;
    double d = (double)1.0*k/n;
    for (int i=0;i<n;++i){
        double tmp = d;
        for (int j=0;j<=num;++j){
            ans[i] = ans[i] + tmp*s[(i-j+n)%n];
            tmp = tmp*(n-k)/(n-1);
        }
        cout << ans[i] << endl;
    }
    
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();

    return 0;
}