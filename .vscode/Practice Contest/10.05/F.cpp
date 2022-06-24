#include<bits/stdc++.h>
using namespace std;
#define MAXN 1005
#define ll long long
ll solvenum[MAXN];ll solvenum2[MAXN];//总过题数
ll solvetime[MAXN];ll solvetime2[MAXN];//总罚时
ll solvelast[MAXN];ll solvelast2[MAXN];//最后过题时间
char c[MAXN][30];char c2[MAXN][30];
ll num[MAXN][30];ll num2[MAXN][30];
ll tim[MAXN][30];ll tim2[MAXN][30];

string s[MAXN];
string s2[MAXN];
map <string,int> mp;
map <string,int> mp2;
ll n,m,k;
//需要注意部分终榜不一定是从1开始的
int pk(int x,int y)//将封榜前和封榜后的一个人进行对比
{
    if(solvenum[x] > solvenum2[y]) return 1;
    else if(solvenum[x] < solvenum2[y]) return -1;
    if(solvetime[x] > solvetime2[y]) return -1;
    else if(solvetime[x] < solvetime2[y]) return 1;
    if(solvelast[x] > solvelast2[y]) return -1;
    else if(solvelast[x] < solvelast2[y]) return 1;
    else if(s[x] < s2[y]) return 1;  
    else return -1;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>k>>n>>m;//题目数量，队伍的数量，封榜后
    for(int i=1;i<=n;i++)//封榜前的输入处理
    {
        cin>>s[i];
        mp[s[i]]=i;
        for(int j=1;j<=k;j++)
        {
            cin>>c[i][j]>>num[i][j]>>tim[i][j];
            if(c[i][j]=='+')//过了这题
            {
                solvenum[i]++;
                solvetime[i]+=(num[i][j]-1)*20+tim[i][j];
                solvelast[i]=max(solvelast[i],tim[i][j]);
            }

        }
    }

    for(int i=1;i<=m;i++)
    {
        cin>>s2[i];
        mp2[s2[i]]=i;
        for(int j=1;j<=k;j++)
        {
            cin>>c2[i][j]>>num2[i][j]>>tim2[i][j];
            if(c2[i][j]=='+')//封榜后过了这题
            {
                solvenum2[i]++;
                solvetime2[i]+=(num2[i][j]-1)*20+tim2[i][j];
                solvelast2[i]=max(solvelast2[i],tim2[i][j]);
            }
        }
    }

    if(m==1)
    {
        cout<<"Leaked"<<endl;
        return 0;
    }

    int f=1;
    for(int i=1;i<=n;i++)//
    {
        if(!mp2.count(s[i]))//如果在终榜找不到这个人，要么他太强了，要么他太弱了
        {
            int flag=0;
            if(pk(i,1)>0||pk(i,m)<0) flag=1;//在这之后未过题，被挤出了榜单
            //下面是封榜后开启厕所战神模式AK的情况
            for(int j=1;j<=k;j++)
            {
                if(c[i][j]=='-')//之前有罚时
                {
                    solvenum[i]++;
                    solvetime[i]+=(num[i][j])*20+240;//正好在封榜那一刻过题，巧吧
                    solvelast[i]=max(solvelast[i],(ll)240);
                }
                else if(c[i][j]=='.')//之前没有罚时
                {
                    solvenum[i]++;
                    solvetime[i]+=240;
                    solvelast[i]=max(solvelast[i],(ll)240);                   
                }
            }
            //模拟AK完了再进行比较
            if(pk(i,1)>0||pk(i,m)<0) flag=1;
            if(flag==0) f=0;

        }

    }
    if(f==1) cout<<"Leaked"<<endl;
    else cout<<"Fake"<<endl;
    return 0;
}