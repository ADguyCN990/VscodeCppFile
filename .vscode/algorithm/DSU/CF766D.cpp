#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define MAXN 100005
ll n,m,q;
string s,v,u;
map <string,int> mp;//用int来映射字符串
int f[MAXN];
int val[MAXN];//对每个集团内的字符串通过0和1赋值来表示是不是近义词，反义词
//同义词的同义词是同义词 (0+0)%2
//反义词的反义词是同义词 (1+1)%2
int findx(int x)
{
    if(f[x]!=x)
    {
        int t=f[x];
        f[x]=findx(f[x]);
        val[x]=(val[x]+val[t])%2;
    }
    return f[x];
}

void solve()
{
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>s;
        mp[s]=i;//对字符串映射，这样就能通过正常的并查集访问了
        f[i]=i;
        val[i]=0;//开始默认所有词都是同义词（不是同一集团，没事）
    }
    int flag;
    while(m--)
    {
        cin>>flag>>u>>v;
        int x=mp[u];int y=mp[v];
        if(flag==1)//同义词
        {
            if(findx(x)==findx(y)&&val[x]!=val[y])//非法情况
            {
                cout<<"NO"<<endl;
                continue;
            }
            else//维护并查集
            {
                cout<<"YES"<<endl;
                int fx=findx(x);
                int fy=findx(y);
                f[fy]=fx;//这题难得顺序无所谓
                val[fy]=(val[x]+val[y])%2;               
            }
        }
        else//反义词
        {
            if(findx(x)==findx(y)&&val[x]==val[y])//非法情况
            {
                cout<<"NO"<<endl;
                continue;
            }
            else//维护并查集
            {
                cout<<"YES"<<endl;
                int fx=findx(x);
                int fy=findx(y);
                f[fy]=fx;
                val[fy]=(val[x]+val[y]+1)%2;          
            }
        }
    }
    while(q--)
    {
        cin>>u>>v;
        int x=mp[u];int y=mp[v];
        if(findx(x)==findx(y)&&val[x]!=val[y]) cout<<2<<endl;
        else if(findx(x)==findx(y)&&val[x]==val[y]) cout<<1<<endl;
        else if(findx(x)!=findx(y)) cout<<3<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();

    return 0;
}