#include<bits/stdc++.h>
using namespace std;
#define MAXN 105
#define ll long long
ll n;
struct node
{
    int next_pos=0;
    int pre_pos=0;
    int val;
}a[MAXN];
void query1(int dx)
{
    cout<<"?";
    for(int i=1;i<n;i++) cout<<" "<<1+dx; //1+dx<=n
    cout<<" "<<1<<endl;   
    cout.flush();
}
void query2(int dx)
{
    cout<<"?";
    for(int i=1;i<n;i++) cout<<" "<<n-dx; //n-dx>0
    cout<<" "<<n<<endl;
    cout.flush();
}
void update()
{
    int dx=0;
    for(int i=n;i;i=a[i].pre_pos)
    {
        a[i].val=a[n].val-dx;
        dx++;
    }
    dx=0;
    for(int i=n;i;i=a[i].next_pos)
    {
        a[i].val=a[n].val+dx;
        dx++;
    }
}
void solve()
{
    cin>>n;
    int now=n;
    int dx=1;
    while(1)
    {     
        if(n-dx==0)//check特例，如果a[n]=n，会出现输出0 0 0 0 0 ... n的情况，会导致读入不了数据
        {
            a[n].val=n-dx+1;
            break;
        }   
        query2(dx);
        int index;
        cin>>index;//这是a[n]+dx的下标
        if(index==0)//找不到这个下标，就可以反推出a[n]的值
        {
            a[n].val=n-dx+1;
            break;
        } 
        else
        {
            a[now].next_pos=index;
            now=index;
            dx++;
        }
    }
    now=n;dx=1;
    while(1)
    {
        if(1+dx==n+1) break;  //特判 
        query1(dx);
        int index;
        cin>>index;//这是a[n]-dx的下标
        if(index==0) break;//如果找不到这个下标，那么说明整个链表已经维护完成
        a[now].pre_pos=index;
        now=index;
        dx++;
    }
    update();//已知a[n]的值和所有元素之间的相对关系，即可以构造出唯一的一种排列
    cout<<"!";
    for(int i=1;i<=n;i++)
    {
        cout<<" "<<a[i].val;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();   
    return 0;
}