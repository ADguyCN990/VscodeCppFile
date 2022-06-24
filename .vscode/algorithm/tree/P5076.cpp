#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
int cnt=1;
int root=1;
struct node
{
    int l;//左子树大小
    int r;//右子树大小
    int val;//节点的值
    int num;//拥有相同值的元素的个数
    int size;
}a[MAXN];

int rk(int x,int root)//查询x的排名
{
    if(x<a[root].val) return rk(x,a[root].l);
    else if(x==a[root].val) return a[a[root].l].size+a[root].num;
    else if(x>a[root].val) return a[a[root].l].size+rk(x,a[root].r);
    return 1;
}

int findx(int x,int root)//查询排名为x的节点的数值
{
    if(x<=a[a[root].l].size) return findx(x,a[root].l);
    else if(x<=a[a[root].l].size+a[root].num) return a[root].val;  
     return findx(x-a[a[root].l].size-a[root].num,a[root].r);
}

void pushup(int root)//维护当前根节点数据
{
    a[root].size=a[a[root].l].size+a[a[root].r].size+a[root].num;
}

void insert(int x,int &root)//插入一个值为x的数
{
    if(x<a[root].val)//插入到左子树中
    {
        if(a[root].l==0)
        {
            a[a[root].l=++cnt]=node{0,0,x,1,1};
        }
        else insert(x,a[root].l);
    }
    else if(x>a[root].val)//插入到右子树中
    {
        if(a[root].r==0)
        {
            a[a[root].r=++cnt]=node{0,0,x,1,1};
        }
        else insert(x,a[root].r);
    }
    else if(x==a[root].val)
    {
        a[root].num++;
    }
    pushup(root);
}

void solve()
{
    int q;
    cin>>q;
    
    while(q--)
    {
        int f,x;
        cin>>f>>x;
        a[1].l=0;a[1].r=0;a[1].val=2147483647;a[1].num=1;a[1].size=1;
        if(f==1) cout<<rk(x,root)<<endl;
        else if(f==2) cout<<findx(x,root)<<endl;
        else if(f==3) cout<<findx(rk(x,root)-1,root)<<endl;
        else if(f==4) cout<<findx(rk(x+1,root),root)<<endl;
        else if(f==5) insert(x,root);
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}