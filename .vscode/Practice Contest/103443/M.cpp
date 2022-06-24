#include<bits/stdc++.h>
using namespace std;
#define MAXN 1005
#define pb push_back

char s1[MAXN],s2[MAXN];
int pat[MAXN];
int patu[MAXN][MAXN];
void solve(){
    int N;
    scanf("%d",&N);
    scanf("%s%s",s1+1,s2+1);
    for(int i=1;i<=N;i++){
        pat[i] = pat[i-1];
        if(s1[i]==s2[i]) pat[i]++;
    }
    pat[N+1] = pat[N];
    for(int i=1;i<=N;i++){
        int p = 0;
        int cnt = 0;
        while(i-p>=1&&i+p<=N){
            if(s1[i-p]==s2[i+p]){
                cnt++;
            }
            if(p!=0&&s1[i+p]==s2[i-p]) cnt++;
            patu[i-p][i+p] = cnt;
            p++;
        }
        if(i!=N){
            int p1 = i,p2 = i+1;
            cnt = 0;
            while(p1>=1&&p2<=N){
                if(s1[p1]==s2[p2]){
                    cnt++;
                }
                if(s1[p2]==s2[p1]) cnt++;
                patu[p1][p2] = cnt;
                p1--;
                p2++;
            }
        }
    }
    int l = 0,r = -1,maxVal = -1;
    for(int i=1;i<=N;i++){
        for(int j=i;j<=N;j++){
            int tmpVal = pat[i-1]+(pat[N]-pat[j])+patu[i][j];
            if(tmpVal>maxVal||(tmpVal==maxVal&&j-i+1<r-l+1)){
                maxVal = tmpVal;
                l = i;
                r = j;
            }
        }
    }
    printf("%d %d %d %d\n",pat[N],maxVal,l,r);
}

int main() {
    int T;
    scanf("%d",&T);
    while (T--){
        solve();
    }
        
}