#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 400005
ll n,p;
struct node
{
    ll id;
    ll val;
}a[MAXN];

bool cmp(node a,node b) {return a.val>b.val;}
int ok[MAXN];//及格次数
int num[MAXN];//出现次数

void init()
{
    for(int i=1;i<=n;i++)
        ok[i]=0,num[i]=0;
}

void solve()
{
    cin>>n>>p;
    init();
    for(int i=1;i<=n;i++)
    {
        cin>>a[2*i-1].val>>a[2*i].val;
        a[2*i-1].id=i,a[2*i].id=i;
    }
    sort(a+1,a+2*n+1,cmp);
    int l=1,r=1,ans=0,tmp=0,cnt=0;//cnt表示已经选到的人数,tmp表示当前状态下及格的人数
    for(int i=1;i<=n+1;i++)
    {
        //先选出n个不同的人
        while(r<=2*n&&cnt<n)
        {
            num[a[r].id]++;
            if(num[a[r].id]==1) //在当前序列中只出现过一次
            {
                cnt++;//多选出了一个人
            }
            r++;
        }
        if(cnt<n) break;//已经选不出合法序列了，直接退出


        //当选出的人数达到n时，这就是一个合法的情况，这时开始统计及格的人数。
        //尺取法成立的原因是，对于某一个人，成绩越高及格的可能性就越大
        //因此将序列按照成绩降序后，从左到右扫过去直到序列中有n个人时的解法一定是以a[i]为最高成绩时最优的解法


        //统计及格的人数
        ll base;//及格线，向上取整
        if((a[i].val*p)%100==0) 
            base=a[i].val*p/100;
        else 
            base=(long long)(a[i].val*p/100)+1;
        while(l<=2*n&&a[l].val>=base)
        {
            ok[a[l].id]++;
            if(ok[a[l].id]==1)//在及格序列中值只出现过一次
            {
                tmp++;
            }
            l++;
        }
        
        //记录答案
        ans=max(tmp,ans);

        //更新状态，为下一个人最高成绩做好预处理
        num[a[i].id]--;
        if(!num[a[i].id]) cnt--;//如果这个人只出现过一次，那么现在最高成绩不是他了，也就是总人数减一
        ok[a[i].id]--;
        if(!ok[a[i].id]) tmp--;//如果这个人只是最高分及格了（或者只出现了一次），那么最高成绩不是他后他就不及格了
        
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }

    return 0;
}