#include<bits/stdc++.h>
using namespace std;
double c[10]={0,-7,1,31,57,9977};//贡献
#define MAXN 105
char a[MAXN];
double b[MAXN];//概率
double p[MAXN];
double n,k;
double sum;
int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i]>>p[i];
        if(a[i]=='D') b[1]+=p[i];
        else if(a[i]=='C') b[2]+=p[i];
        else if(a[i]=='B') b[3]+=p[i];
        else if(a[i]=='A') b[4]+=p[i];
        else if(a[i]=='S') b[5]+=p[i];
       
    }
     for(int i=1;i<=5;i++)
        {
            sum=sum+b[i]*1.0*c[i]*1.0;
        }
        printf("%.4lf\n",sum*k);
    return 0;
}