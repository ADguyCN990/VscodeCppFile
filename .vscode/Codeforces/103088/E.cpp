#include<bits/stdc++.h>
using namespace std;
#define MAXN 10005

int n;
int ans;
void solve()
{
    cin>>n;
    queue <int> q0;queue <int> q1;
    for(int i=1;i<=n;i++)
    {
        int tim,op;
        cin>>tim>>op;
        if(op==0) q0.push(tim);
        else q1.push(tim);
    }

    while(q0.size()&&q1.size())
    {
        int now0=q0.front();
        int now1=q1.front();

        if(now0<now1) //电梯为0号方向
        {
            ans+=10;//当前电梯停止的时间
            
            while(q0.size()&&q0.front()<ans)
            {
                if(q0.front()+10>ans) ans=q0.front()+10; //下一个人相同状态的人到达的时间超过停止的时间
                q0.pop();
            }
        }
        else
        {
            ans+=10;
            while(q1.size()&&q1.front()<ans)
            {
                if(q1.front()+10>ans) ans=q1.front()+10;
                q1.pop();
            }
        }
    }
    ans+=10;
    int r=0;
    while(q0.size()) r=q0.front()+10,q0.pop();
    while(q1.size()) r=q1.front()+10,q1.pop();
    cout<<max(ans,r)<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}