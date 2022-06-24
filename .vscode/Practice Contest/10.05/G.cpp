#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 1005
#define ll long long
ll ans[1005][1005];
ll  r[1005][1005],c[1005][1005];//这是环
int m,n;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) 
	    {
            cin>>r[i][j];
            cin>>c[i][j];
        }
    } 
    //现在在每个格子中填一个整数x，在格子的左、下边加x，右、上边减x
    //一条水平的边值=上边气旋的气压值-下边气旋的气压值
    //一条竖直的边值=右边气旋的气压值-左边气旋的气压值
    ans[0][0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) 
	    {
            ans[(i+n-1)%n][j]=ans[i][j]+r[i][j];//上
            ans[i][(j+m-1)%m]=ans[i][j]-c[i][j];//左
            ans[(i+1)%n][j]=ans[i][j]-r[(i+1)%n][j];//下
            ans[i][(j+1)%m]=ans[i][j]+c[i][(j+1)%m];//右
        }
    }
    
    int flag=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++) 
	    {
            //判断推出来的有没有自相矛盾
            if(ans[(i+n-1)%n][j]!=ans[i][j]+r[i][j])flag=0;
            if(ans[i][(j+m-1)%m]!=ans[i][j]-c[i][j])flag=0;
            if(ans[(i+1)%n][j]!=ans[i][j]-r[(i+1)%n][j])flag=0;
            if(ans[i][(j+1)%m]!=ans[i][j]+c[i][(j+1)%m])flag=0;
        }
    }
    
    if(flag==1) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
	return 0;
 } 