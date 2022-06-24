#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n;
ll sum[1505];
map <int,int> mp;
void pre()
{
    int key=1;
    mp[key]=1;
    for(int i=2;;i++)
    {
        key+=i;
        mp[key]=i;
        if(key>1000000) break;
    }
    mp[2]=3;
    mp[4]=3;
    mp[5]=4;
    int pre=1;
    for(int i=1;i<=1000000;i++)
    {
        if(mp[i]!=0) 
        {
            pre=mp[i];continue;
        }
        if(mp[i+1]!=0)
        {
            mp[i]=mp[i+1]+1;
        }
        else
        {
            mp[i]=pre+1;
        }
    }
}

void solve()
{
    cin>>n;//n为目的地，一开始在坐标点为0的位置上
    //现在跳了k次，要么往右跳k的距离，要么往左跳1的距离
    cout<<mp[n]<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    pre();
    while(T--)
    {
        solve();
    }

    return 0;
}