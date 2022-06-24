#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000005
char mt[MAXN];
int nxt[MAXN], pre[MAXN];
int q, slen;

void init(){
    nxt[0] = -1;
    int mtlen = slen;
    for (int i=1;i<mtlen;i++){
        int temp = nxt[i-1];
        while(mt[temp+1] != mt[i] && temp > -1){
            temp = nxt[temp];
        }
        if (mt[temp+1]==mt[i]) nxt[i] = temp + 1;
        else nxt[i] = -1;
    }
}

void solve()
{
    cin>>mt;
    cin>>q;
    slen = strlen(mt);
    init();
    int x;
    int len = slen - nxt[slen - 1] - 1;
    int allnum = (slen+len-1)/ len;
    while (q--){
        cin >> x;
        int ans = 0;
        if (x==1 || x==slen){
            cout << 0 << endl;
            continue;
        }
        int num = (x+len-1)/len;
        if (num == (slen+len-1)/len){
            cout << 0 << endl;
            continue;
        }
        if (num > allnum/2){
            cout << allnum - num << endl;
            continue;
        }
        int rem = (slen%len==0)?(len):(slen%len);
        int xrem = (x%len==0)?(len):(x%len);
        if (xrem > rem){
            ans++;
        }
        cout << (num - 1) + ans << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}