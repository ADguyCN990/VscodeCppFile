#include<bits/stdc++.h>
using namespace std;
#define MAXN 200005
double a[MAXN];
double b[MAXN];
int n;

int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        a[i]=i+0.0;
        cin>>b[i];
        b[i]+=0.0;
    }
    sort(b+1,b+1+n);
    double minx=0x3f3f3f3f;
    for(int i=1;i<=n;i++)
    {
        double temp=b[i]/a[i];
        if(b[i]>a[i])
        {
            cout<<"-1"<<endl;
            return 0;
        }
        minx=min(minx,temp);
    }
    printf("%.6lf\n",minx);
    return 0;
}