#include<bits/stdc++.h>
using namespace  std;
int a,b,c;
int t;
int maxs;
int get(int x)//求x的质因子幂数之和
{
    int ans=0;
    int temp=x;
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
        {
            while(x%i==0)
            {
                ans++;
                x/=i;
            }
        }
        
    }
    if(x>1) ans++;
    return ans;
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&a,&b,&c);
        if(c==1)
        {
            if(a==b) printf("NO\n");
            else if(a%b==0||b%a==0) printf("YES\n");
            else printf("NO\n");
           // continue;
        }
        else
        {
            maxs=0;
            maxs=get(a)+get(b);
            // cout<<"geta "<<get(a)<<" getb "<<get(b)<<endl;
            if(c<=maxs) printf("YES\n");
            else printf("NO\n");
        } 
    }
    return 0;
}

