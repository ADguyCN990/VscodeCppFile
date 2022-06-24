#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 25
string s;
map <char,char> mp;

set <pair<int,int>> point;//用set为了去重
void solve()
{
    int len=s.length();
    if(len>=3)
    {
        if(s[len-1]==mp[s[len-2]]&&s[len-2]==mp[s[len-3]])
        {
            cout<<"impossible"<<endl;
            return;
        }
    }
    int x=0;int y=0;int dx=100;//dx每次都得变大，避免走进死胡同
    //正着遍历，以小球一开始的位置作为（0，0）点开始模拟
    for(int i=0;i<len;i++)
    {
        if(s[i]=='L')
        {
            x=-dx;point.insert(make_pair(x-1,y));
        }
        else if(s[i]=='R')
        {
            x=dx;point.insert(make_pair(x+1,y));
        }
        else if(s[i]=='U')
        {
            y=dx;point.insert(make_pair(x,y+1));
        }
        else if(s[i]=='D')
        {
            y=-dx;point.insert(make_pair(x,y-1));
        }
        if(s[i+1]!=mp[s[i]])//特判可能出现的放屁情况，这样距离不变，不加这句的话就会多出来一些奇奇怪怪的点导致WA（原因未知）
            dx+=100;
    }
    cout<<-x<<" "<<-y<<endl;//变换参考系，以小球的终点为参考为原点
    cout<<point.size()<<endl;
    for(auto it:point)
    {
        cout<<it.first-x<<" "<<it.second-y<<endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>s;
    mp['L']='R';mp['R']='L';mp['U']='D';mp['D']='U';
    solve();

    return 0;
}
