#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 200005
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
map<string, int> year;
map<string, int> id;
map<int, int> mp;
int cnt;
int a[105];
void pre() {
    year["Ox"] = 1;
    year["Tiger"] = 2;
    year["Rabbit"] = 3;
    year["Dragon"] = 4;
    year["Snake"] = 5;
    year["Horse"] = 6;
    year["Goat"] = 7;
    year["Monkey"] = 8;
    year["Rooster"] = 9;
    year["Dog"] = 10;
    year["Pig"] = 11;
    year["Rat"] = 12;
}


void solve() {
    //以Bessie那一年的牛年为基准线
    int n = read();
    id["Bessie"] = 1;
    mp[1] = 1;
    for (int i = 2; i <= n + 1; i++) {
        int u, b;
        int flag = 1;//1表示在b的后，0表示在b的前
        int num; //表示生肖
        for (int j = 1; j <= 8; j++) {
            string tmp;
            cin >> tmp;
            if (j == 1) {
                id[tmp] = i;
                u = id[tmp];
            }
            if (j == 4) {
                if (tmp == "previous")
                    flag = 0;
                else if (tmp =="next")
                    flag = 1;
            }
            if (j == 5) {
                num = year[tmp];
            }
            if (j == 8) {
                b = id[tmp];
            }
            mp[u] = num;
        }
           
        if (flag == 1) {
            int bnum = mp[b];
            if (num > bnum) {
                a[u] = a[b] + num - bnum;
            }
            else {
                int dif = num + 12 - bnum;
                a[u] = a[b] + dif;
            }
        }
        else {
            int bnum = mp[b];
            if (num < bnum) {
                a[u] = a[b] - (bnum - num);
            }
            else {
                int dif = bnum + 12 - num;
                a[u] = a[b] - dif;
            }
        }
    }    
    
    int dif = abs(a[id["Bessie"]] - a[id["Elsie"]]);
    printf("%d\n", dif);
}

int main() {
    pre();
    solve();
    return 0;
}