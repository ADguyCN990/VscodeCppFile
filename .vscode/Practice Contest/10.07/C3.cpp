#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int pre[MAXN];//前驱
int nxt[MAXN];//后继
int cnt[MAXN];//最终答案
stack <int> s;
int n,m;

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int l,r;
        cin>>l>>r;
        pre[r]=l;nxt[l]=r;
    }
    for(int i=n;i>0;i--) s.push(i);//1~n入栈
    for(int i=1;i<=n;i++)
    {
        if(pre[i]!=0)//i有前驱
        {
            cnt[i]=cnt[pre[i]];
            if(nxt[i]==0)//他是这个链的最后一个元素
            {
                s.push(cnt[i]);
            }
        }
        else//如果他还有后继
        {
            cnt[i]=s.top();
            if(nxt[i]!=0) s.pop();
        }  
        
    }
    for(int i=1;i<=n;i++) cout<<cnt[i]<<" ";
    return 0;
}