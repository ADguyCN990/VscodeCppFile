#include<bits/stdc++.h>
using namespace std;
int n, m,cnt,s;
#define MAXN 1000005
#define MAXM 1000005
int f[MAXN];
double x[MAXN];
double y[MAXN];
struct node {
	int x, y;
	double val;
}edge[MAXM];
bool cmp(node a, node b) { return a.val < b.val; }
int findx(int x)
{
	if (f[x] == x) return x;
	return f[x] = findx(f[x]);
}
void merge(int x, int y)
{
	int fx = findx(x); int fy = findx(y);
	if (fx != fy) f[fy] = fx;
}
double get(int a, int b)
{
	return sqrt((x[a] - x[b]) * (x[a] - x[b] / 1.0) + (y[a] - y[b]) * (y[a] - y[b]) / 1.0);
}

int main()
{
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
	{
		f[i] = i;
		double a, b;
		cin >> a >> b;
		x[i] = a / 1.0; y[i] = b / 1.0;
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			edge[++cnt].x = i; edge[cnt].y = j; edge[cnt].val = get(i, j);
		}
	}
	sort(edge + 1, edge + 1 + cnt, cmp);
	double ans = 0; int p = 0;
	for (int i = 1; i <= cnt; i++)
	{
		int a = edge[i].x; int b = edge[i].y; double val = edge[i].val;
		if (findx(a) == findx(b)) continue;
		merge(a, b);
		p++;
		if (p >= n - s)
		{
			ans = val;
			break;
		}
	}
	printf("%.2lf", ans);
	return 0;
}