#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 2005
#define MAXM 200005
typedef pair<int, int> pii;
#define INF 0x3f3f3f3f
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define per(i, x, y) for(int i = x; i >= y; i--)
#define pb emplace_back
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}
string s[10] = {"1110111", "0010010", "1011101", "1011011",
 "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int n;          
char a[MAXN][MAXN];    
bool flag = false, st[MAXN][MAXN];  
int ans[MAXN];     
void dfs(int pos, int k) {
	if (flag || k < 0) return;  
	if (pos == n) {   //如果枚举完n个数且剩余修改次数正好为0，则输出答案并记录
		if (k == 0) {
			flag = true;
			for (int i = 0; i < n; i++) 
                printf("%d", ans[i]);
			puts("");
			return;
		}
		else return;
	}
    if (st[pos][k]) return;  //已经算出了该状态不合法，返回
	for (int i = 9; i >= 0; i--) {
		int cnt = 0;       //记录a[pos]修改成数i需要的次数
		bool state = false;//记录a[pos]能否修改成数i
		for (int j = 0; j < 7; j++)  
		if (a[pos][j] == '0' && s[i][j] == '1') cnt++; //修改需要打开该灯管则可以修改
		else if (a[pos][j] == '1' && s[i][j] == '0') {   //修改需要关闭该灯管，则不可修改，所以，a[pos]不能改为数i
			state = true;
			break;
		}
		
		if (state) continue;
		ans[pos] = i;        
		dfs(pos + 1, k - cnt);  
	}
	if (!flag) st[pos][k] = true;  
}

void solve() {
    int k;
    n = read(), k = read();
    for (int i = 0; i < n; i++)
        scanf("%s", a[i]);   
    dfs(0, k);
    if (!flag) {
        puts("-1");
        return;
    }
}

int main() {
    solve();
    return 0;
}