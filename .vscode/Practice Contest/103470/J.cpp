#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int N = 2000;
int p[N],pcnt[N];
pii f[N];

int tot = 0,dn = 0;
void dfs(int u,int x,int cnt){
    if(u>tot){
        ++dn;
        p[dn] = x;
        pcnt[dn] = cnt;
        return;
    }
    for(int i=0;i<=f[u].second;i++){
        dfs(u+1,x,cnt);
        x*=f[u].first;
        cnt++;
    }
}
void solve(){

    int aa,bb;
    scanf("%d %d",&aa,&bb);
    int a = min(aa,bb),b=max(aa,bb);
    if(a==1){
        printf("0\n");
        return;
    }
    if(b-a==1){
        printf("%d\n",a-1);
        return;
    }
    int diff = b-a,d = b-a;
    tot = 0;
    int totCnt = 0;
    for(int i=2;i<=d/i;i++){
        if(d%i==0){
            int sm = 0;
            while(d%i==0){
                d/=i;
                sm++;
                totCnt++;
            }
            f[++tot] = {i,sm};
        }
    }
    if(d>1) f[++tot] = {d,1};
    dn = 0;
    dfs(1,1,0);
    int ans = b+1;
    for(int i=1;i<=dn;i++){
        if(p[i]==1||p[i]==diff) continue;
        int k = diff/p[i];
        int kcnt = totCnt-pcnt[i];
        if(a>k){
            k = (a/k+1)*k;
        }
        b +=k-a;
        a = k;
        a/=diff/p[i];
        b/=diff/p[i];
        int tmpAns = kcnt+a-1;
        ans = min(ans,b);
    }
    printf("%d\n",ans);
}
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        solve();
    }
    return 0;
}