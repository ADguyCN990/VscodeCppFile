#include<bits/stdc++.h>
using namespace std;
#define ll long long
unordered_map <string,int> dis;//当前状态与起点的步数
unordered_map <string,pair<string,char>> pre;//前驱，用于输出答案用
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
char op[4]={'r','l','u','d'};
typedef pair<int,string> pis;

int get(string s)//估值函数，当前状态中每个数与他目标位置的曼哈顿距离之和
{
    int ans=0;
    for(int i=0;i<9;i++)
    {
        if(s[i]=='x') continue;
        int x=s[i]-'1';
        ans+=abs(x/3-i/3)+abs(x%3-i%3);
    }
    return ans;
}

string bfs(string start)
{
    priority_queue <pis,vector<pis>,greater<pis>> q;
    dis[start]=0;
    q.push({get(start),start});
    while(q.size())
    {
        string now=q.top().second;//当前的状态
        int step=dis[now];//当前状态距离起点的步数
        q.pop();
        if(now=="12345678x") break;
        int pos=now.find('x');
        int x=pos/3,y=pos%3;//记录'x'的坐标位置
        string data=now;//保存原始数据，等会会变，并且记录答案时要用到前驱
        for(int i=0;i<4;i++)
        {
            int xx=x+dx[i],yy=y+dy[i];
            if(xx>=3||xx<0||yy>=3||yy<0) continue;
            swap(now[x*3+y],now[xx*3+yy]);//枚举并交换'x'的位置，尝试搜索
            if(!dis.count(now)||dis[now]>step+1)
            {
                dis[now]=step+1;
                pre[now]={data,op[i]};
                q.push({dis[now]+get(now),now});
            }
            now=data;//恢复现场
        }
    }
    string end="12345678x";
    string ans="";
    while(start!=end)
    {
        ans+=pre[end].second;
        end=pre[end].first;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

void solve()
{
    string start,tmp;
    for(int i=0;i<9;i++)
    {
        char c;
        cin>>c;
        start+=c;
        if(c!='x')
            tmp+=c;
    }
    int cnt=0;//逆序对数量
    for(int i=0;i<8;i++)
        for(int j=i+1;j<8;j++)
            if(tmp[i]>tmp[j])
                cnt++;
    if(cnt&1) cout<<"unsolvable"<<endl;
    else cout<<bfs(start)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}