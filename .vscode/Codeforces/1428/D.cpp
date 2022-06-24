#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
typedef pair<int,int> pii;
vector <pii> ans;
int n;
int a[MAXN];
int h[MAXN];
int a1[MAXN],cnt1;//当做第二次反弹的跳板
int a2[MAXN],cnt2;//第三次反弹的跳板
void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    //一定要倒着选点，否则会出现问题
    int height=n;
    for(int i=n;i;i--)
    {
        if(a[i]==1)
        {
            h[i]=height--;
            a1[++cnt1]=i;
            ans.push_back({i,h[i]});
        }
        else if(a[i]==2)//前面必须得有个弹过一次的，要不然就是非法状态（不能再后面的列中放方块反弹第二次）
        {
            if(!cnt1)
            {
                cout<<-1<<endl;
                return;
            }
            h[i]=h[a1[cnt1--]];//与跳板同一高度，顺便更新可用点
            a2[++cnt2]=i;
            ans.push_back({i,h[i]});
        }
        else if(a[i]==3)
        {
            if(!cnt2&&!cnt1)
            {
                cout<<-1<<endl;
                return;
            }
            h[i]=height--;
            ans.push_back({i,h[i]});
            int tmp;
            if(cnt2)
                tmp=a2[cnt2--];
            else 
                tmp=a1[cnt1--];
            ans.push_back({tmp,h[i]});
            a2[++cnt2]=i;
        }
    }
    cout<<ans.size()<<endl;
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i].first<<" "<<ans[i].second<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}