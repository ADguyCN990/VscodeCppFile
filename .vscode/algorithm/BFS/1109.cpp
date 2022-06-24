#include<bits/stdc++.h>
using namespace std;
#define ll long long
unordered_map <string,int> dis;
unordered_map <string,pair<char,string>> pre;//前驱节点
string s,e;

string get1(string s)
{
    reverse(s.begin(),s.end());
    return s;
}

string get2(string s)
{
    string ans="";
    ans+=s[3],ans+=s[0],ans+=s[1],ans+=s[2],ans+=s[5],ans+=s[6],ans+=s[7],ans+=s[4];
    return ans;
}

string get3(string s)
{
    string ans="";
    ans+=s[0],ans+=s[6],ans+=s[1],ans+=s[3],ans+=s[4],ans+=s[2],ans+=s[5],ans+=s[7];
    return ans;
}

void bfs(string s)
{
    dis[s]=0;
    if(s==e) return;
    queue <string> q;
    q.push(s);
    while(q.size())
    {
        string now=q.front();q.pop();
        if(now==e) return;
        string s1=get1(now);
        string s2=get2(now);
        string s3=get3(now);
        if(dis.count(s1)==0)
        {
            pre[s1]={'A',now};
            dis[s1]=dis[now]+1;
            q.push(s1);
        }
        if(dis.count(s2)==0)
        {
            pre[s2]={'B',now};
            dis[s2]=dis[now]+1;
            q.push(s2);
        }
        if(dis.count(s3)==0)
        {
            pre[s3]={'C',now};
            dis[s3]=dis[now]+1;
            q.push(s3);
        }
    }
}

void solve()
{
    s="12345678";
    for(int i=1;i<=8;i++)
    {
        int tmp;
        cin>>tmp;
        e+='0'+tmp;
    }
    bfs(s);
    cout<<dis[e]<<endl;
    string ans="";
    while(e!=s)
    {
        //cout<<pre[e].first<<endl;
        ans+=pre[e].first;
        e=pre[e].second;
    }
    //cout<<ans<<endl;
    reverse(ans.begin(),ans.end()); 
    cout<<ans;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}