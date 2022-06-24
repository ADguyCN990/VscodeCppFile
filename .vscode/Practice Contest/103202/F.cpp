#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
typedef pair<int,int> pii;
#define INF 0x3f3f3f3f
int a[MAXN], n;
pii ap[MAXN];
bool mcmp(pii& u,pii& v){
    return u.second<v.second;
}
int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    a[0] = 0, a[n + 1] = INF;
    for(int i=1;i<=n;i++){
        ap[i].first = a[i];
        ap[i].second = i;
    }
    sort(ap+1,ap+n+1);
    for(int i=1;i<=n;i++) ap[i].first = i;
    sort(ap+1,ap+n+1,mcmp);
    int ans = 0,p=0,maxIdx = -1;
    while(p+1<=n){
        p++;
        maxIdx = max(maxIdx,ap[p].first);
        if(p==maxIdx){
            ans++;
            maxIdx = -1;
        }
    }
    printf("%d\n",ans);
    return 0;
}