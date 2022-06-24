#include <bits/stdc++.h>
using namespace std;
typedef pair<double, double> pdd;
#define ll long long
#define xx first
#define yy second
#define double long double

int n;
const int Max_n = 1000 + 10;
const double pi = acos(-1);
//const double lit = 1.0*2/1000/pi;
const double lit = 1.0 * 2 / pi;

vector<int> ve[Max_n];
pdd ans[Max_n];
int son[Max_n];
double ang[Max_n];

void dfs(int u, int pre)
{
    int ulen = ve[u].size();
    if (ulen == 1)
    {
        son[u] = 1;
        return;
    }
    for (int i = 0; i < ulen; ++i)
    {
        if (ve[u][i] == pre)
        {
            continue;
        }
        dfs(ve[u][i], u);
        son[u] += son[ve[u][i]];
    }
}

void cal(int u, int pre)
{
    if (ve[u].size() == 1)
    {
        return;
    }
    for (int i = 0; i < ve[u].size(); ++i)
    {
        if (ve[u][i] == pre)
        {
            continue;
        }
        int v = ve[u][i];
        ang[ve[u][i]] = ang[u] + lit * i / 1000;
        double x = ans[u].xx + cos(ang[v]), y = ans[u].yy + sin(ang[v]);
        ans[ve[u][i]] = pdd(x, y);
        cal(v, u);
    }
}

void solve()
{
    cin >> n;
    int a, b;
    for (int i = 1; i < n; ++i)
    {
        cin >> a >> b;
        ve[a].push_back(b), ve[b].push_back(a);
    }
    dfs(1, 0);
    //	for (int i=1;i<=n;++i){
    //		printf("%d\n", son[i]);
    //	}
    //	cout << "YES!!!" << endl;
    double cur = 0;
    for (int i = 0; i < ve[1].size(); ++i)
    {
        int v = ve[1][i];
        if (i == 0)
        {
            ang[v] = 0;
            ans[v].xx = 1.0, ans[v].yy = 0.0;
            cal(ve[1][0], 1);
            continue;
        }
        ang[v] = cur + lit * son[v] / 1000;
        cur = ang[v];
        ans[v].xx = cos(ang[v]), ans[v].yy = sin(ang[v]);
        for (int j = 0; j < ve[v].size(); ++j)
        {

            int w = ve[v][j];
            if (w == 1)
            {
                continue;
            }
            ang[w] = ang[v] + lit * i / 1000;
            double x = ans[v].xx + cos(ang[w]), y = ans[v].yy + sin(ang[w]);
            ans[w] = pdd(x, y);
            cal(w, v);
        }
    }

    for (int i = 1; i <= n; ++i)
    {
        cout << fixed << setprecision(10);
        cout << ans[i].xx << " " << ans[i].yy << endl;
        //		printf("%.8lf %.8lf\n",  ans[i].xx, ans[i].xx;
        //		printf("??    %lf\n", ang[i]);
    }
    //	cout << acos(-1) << endl;
}

int main(void)
{
    solve();
    return 0;
}
