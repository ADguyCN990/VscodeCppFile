#include <set>
#include <map>
#include <list>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <bitset>
#include <vector>
#include<cstring>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
inline int read(){int s=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();return s*w;}
const int maxn = 1e5+5;
bool is_prime(ll n){
    if(n==2) return false;
    ll len=sqrt(n);
    for(ll i=2;i<=len;i++)
        if(n%i==0) return true;
    return false;
}
int main()
{
    int t=read();
    while (t--)
    {
        ll n;
        scanf("%lld",&n);
        ll f=n;

        if(!is_prime(n)) printf("1\n%lld\n",n);
        else
        {
            int pi[500]={0},k=0;
            for(int i=2;i<=sqrt(n);i++){
                while (n%i==0){
                    n/=i;
                    pi[++k]=i;
                }
            }
            if(n>1) pi[++k]=n;
            int ans=-INF;
            int ff=pi[1],pos=-1;
            for(int i=2;i<=k;i++){
                int x=1;
                while (pi[i]==ff&&i<=k) i++,x++;
                if(ans<x) ans=x,pos=i-1;
                ff=pi[i];
            }
            if(ans==1) {printf("1\n%lld\n",f);continue;}
            printf("%d\n",ans);
            for(int i=1;i<=ans-1;i++)
                printf("%d ",pi[pos]);
            printf("%lld\n",f/(ll)pow(pi[pos],ans-1));
        }
    }

    return 0;
}
