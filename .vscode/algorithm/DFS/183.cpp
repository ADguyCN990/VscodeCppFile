#include<bits/stdc++.h>
using namespace std;
#define MAXN 30
int n,t;
int a[MAXN];
int op[8][7]=
{
    {1,3,7,12,16,21,23},
    {2,4,9,13,18,22,24},
    {11,10,9,8,7,6,5},
    {20,19,18,17,16,15,14},
    {24,22,18,13,9,4,2},
    {23,21,16,12,7,3,1},
    {14,15,16,17,18,19,20},
    {5,6,7,8,9,10,11}
};
int cbd[8]={7,8,9,12,13,16,17,18};//中间八个方块的下标
int enemy[8]={5,4,7,6,1,0,3,2};//各自的对立面
int path[1005];
int f()//估值函数，理想情况下最少需要的步数
{
    int cnt[4]={0,0,0,0};
    for(int i=0;i<8;i++)
    {
        cnt[a[cbd[i]]]++;
    }
    int mxsum=0;
    mxsum=max({cnt[1],cnt[2],cnt[3]});
    return 8-mxsum;
}

void work(int x)
{
    int tmp=a[op[x][0]];
    for(int i=0;i<6;i++)
        a[op[x][i]]=a[op[x][i+1]];
    a[op[x][6]]=tmp;
}

bool dfs(int now,int mx,int pre)
{
    if(now+f()>mx) return false;
    if(f()==0) return true;//估值函数为0说明已经合法

    for(int i=0;i<8;i++)
    {
        if(enemy[i]==pre) continue;
        work(i);
        path[now+1]=i;
        if(dfs(now+1,mx,i)) return true;
        work(enemy[i]);//反向执行一次操作来恢复现场
    }
    return false;
}

void solve()
{
    int depth=0;
    while(!dfs(0,depth,-1)) depth++;//迭代加深
    if(!depth)
        cout<<"No moves needed"<<endl;
    else 
    {
        for(int i=1;i<=depth;i++) cout<<char('A'+path[i]);
        cout<<endl;
    }    
    cout<<a[7]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    
    while(cin>>t)
    {
        if(!t) break;
        a[++n]=t;
        if(n==24)
        {
            solve();
            n=0;
        }       
    }
    return 0;
}