#include<bits/stdc++.h>
using namespace std;
#define MAXN 2005
int a[MAXN];
bool cmp(int a,int b){return a>b;}
int t,n,m;

int main()
{
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++) cin>>a[i];
        int x=-1,y=-1;
        for(int i=1;i<=n;i++)
        {
            if(a[i]>x)
            {
                y=x;
                x=a[i];
            }
            else if(a[i]<=x&&a[i]>y)
            {
                y=a[i];
            }
        }
        //cout<<x<<" "<<y<<endl;
        int temp1=m/(x+y)*2;
        if(m%(x+y)==0) temp1=temp1;
        else if(m%(x+y)<=x) temp1++;
        else temp1+=2;
        cout<<temp1<<endl;
        
    }

    return 0;
}