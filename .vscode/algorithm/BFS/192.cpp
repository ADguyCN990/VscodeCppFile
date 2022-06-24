#include<bits/stdc++.h>
using namespace std;
#define ll long long
string A,B;
int n;
string a[10],b[10];//子串变换规则
unordered_map <string,int> disa;//起点到某个状态的距离
unordered_map <string,int> disb;//终点到某个状态的距离

int extend(queue<string> &q,unordered_map<string,int> &disa,unordered_map <string,int> &disb, string a[],string b[])//从当前队列仅扩展一层状态
{
    int len=q.size();
    for(int k=0;k<len;k++)//保证只扩展一层
    {
        string now=q.front();q.pop();
        if(disb.count(now))//在对面找到了相同状态的点
        {
            return disa[now]+disb[now];
        }
        for(int i=0;i<now.size();i++)//枚举替换开始位置
        {
            for(int j=0;j<n;j++)//枚举规则
            {
                if (now.substr(i, a[j].size()) == a[j])//能替换
                {
                    string to = now.substr(0, i) + b[j] + now.substr(i + a[j].size());//扩展状态
                    if (disa.count(to)) continue;//之前这个状态已经出现过了

                    disa[to] = disa[now] + 1;
                    q.push(to);
                }
            }
        }
    }
    return 11;//返回一个非法的数，表示没找到
}

int bfs()
{
    disa[A]=0;disb[B]=0;
    queue <string> qa,qb;//qa表示从起点开始搜，qb表示从终点开始搜
    qa.push(A),qb.push(B);
    while(qa.size()&&qb.size())//只有当qa和qb两个队列里都有东西时才能继续搜索
    {
        int t;//从小的队列开始扩展，能否出现另一个队列的元素，如果可以返回合法步数
        if(qa.size()<=qb.size())
            t=extend(qa,disa,disb,a,b);
        else
            t=extend(qb,disb,disa,b,a);//扩展的队列不同，参数位置也不同
        if(t<=10) return t;
    }
    return 100;
}

void solve()
{
    cin>>A>>B;
    while(cin>>a[n]>>b[n]) n++;
    int ans=bfs();//开始双端搜索
    if(ans>10)
        cout<<"NO ANSWER!"<<endl;
    else
        cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}