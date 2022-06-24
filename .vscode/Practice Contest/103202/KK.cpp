#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005

int read(){
    int x = 0, f = 1;char ch;
    do{ch=getchar();if(ch=='-') f=-1;}while(ch<'0' || ch>'9');
    do{x=x*10+ch-48;ch=getchar();}while(ch>='0' && ch<='9');
    return x * f;
}

int n, pc, nc, cnt;
const int N = 1e6 + 5;
int pos[N], neg[N];
double fpr[N], tpr[N];
char s[5];

int main() {
    n = read();
    int x;
    for (int i=1;i<=n;++i){
        scanf("%s", s); x = read();
        if (s[0] == '+'){
            pos[++pc] = x;
        }
        else neg[++nc] = x;
    }
    sort(pos + 1, pos + 1 + pc);
    sort(neg + 1, neg + 1 + nc);
    for (int i=nc;i>=1;--i){
        x = neg[i];
        int p = upper_bound(pos + 1, pos + 1 + pc, x) - pos;
        int tp = pc - p + 1;
        p = upper_bound(neg + 1, neg + 1 + nc, x) - neg;
        int fp = nc - p + 1, tn = p - 1, fn = n - tp - tn - fp;
        ++cnt;
        double TPR = 1.0 * tp / (tp + fn), FPR = 1.0 * fp / (fp + tn);
        tpr[cnt] = TPR, fpr[cnt] = FPR;
    }
    double res = 0;
    fpr[++cnt] = 1.0;
    for (int i=2;i<=cnt;++i){
        res = res + (fpr[i] - fpr[i - 1]) * tpr[i - 1];
    }
    printf("%.15f\n", res);
    // for (int i=1;i<=cnt;++i){
    //     printf("FPR:%f , TPR:%f\n", fpr[i], tpr[i]);
    // }

    return 0;
}