#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define ll long long
ll read() {
    ll x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
    do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
    return x*f;
}

int main() {
    ll u = read(), v = read();
    //xor-sum = u, sum = v
    vector<ll> num;
    ll tmp = v - u;
    if (tmp < 0 || tmp & 1) {
        puts("-1");
        return 0;
    }
    if (u == 0 && v == 0) {
        puts("0");
        return 0;
    }
    for (int i = 63; i >= 0; i--) 
        if (u >> i & 1)
            num.push_back(1ll << i);
    tmp /= 2;
    ll bac = num.back() + tmp;
    int cnt = 0;
    vector<ll> ans;
    for (int i = 0; i < num.size(); i++) {
        if (cnt == 2) {
            ans.push_back(num[i]);
        }
        else {
            if (num[i] != tmp) {
                ans.push_back(num[i] + tmp);
                cnt++;
            }
            else
                ans.push_back(num[i]);
        }
    }
    if (cnt < 2 && tmp != 0) {
        for (int i = 1; i <= 2 - cnt; i++) ans.push_back(tmp);
    }
    printf("%d\n", ans.size());
    for (int i = 0; i < ans.size(); i++) printf("%lld ", ans[i]);
    return 0;
}
