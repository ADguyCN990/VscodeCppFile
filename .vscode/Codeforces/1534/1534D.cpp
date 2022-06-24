#include<bits/stdc++.h>
using namespace std;
int t;
double a,b,c,v;
#define ex 1e-9
//如果a<v a直接变成0，bc均分
//如果a>=v a-=v, bc均分v
double dfs(double a,double b,double c)//返回值为期望步数
{
    double ans=c;
   if(a!=0)//走A
   {
       if(a-v>=ex)//能减
       {
           if(b!=0)//b没有被减到0
           ans+=a*(1+dfs(a-v,b+v/2,c+v/2));
           else
           ans+=a*(1+dfs(a-v,0,c+v));//当前的概率乘上之后的期望步数
       }
       else//减不动直接为0
       {
           if(b!=0)
           ans+=a*(1+dfs(0,b+a/2,c+a/2));
           else
           ans+=a*(1+dfs(0,0,c+a));
       }
   }

   if(b!=0)//走B
   {
       if(b-v>=ex)//能减
       {
           if(a!=0)
           ans+=b*(1+dfs(a+v/2,b-v,c+v/2));
           else
           ans+=b*(1+dfs(0,b-v,c+v));
       }
       else
       {
           if(a!=0)
           ans+=b*(1+dfs(a+b/2,0,c+b/2));
           else
           ans+=b*(1+dfs(0,0,c+b));
       }
   }
   
   return ans; 
}

int main()
{
    cin>>t;
    while(t--)
    {
        scanf("%lf%lf%lf%lf",&a,&b,&c,&v);
       printf("%.12lf\n",dfs(a,b,c));
    }
    return 0;
}