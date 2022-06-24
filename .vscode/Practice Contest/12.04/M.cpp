#include<bits/stdc++.h>
using namespace std;
int n,m;
const int N = 100 + 10, M = 1000 + 10;
map<string, int> mp;//0表示能删除的，1表示不能删除的，2表示可以不删除的
string s[105];

void solve()
{
    cin >> n >> m;
    // for (int i=1;i<=n;++i){
    //     cin >> s+1;
    //     int slen = strlen(s+1);
    //     for (int i=1;i<=slen;++i){
    //         int j = i;
    //         while (j<=slen&&s[j]!='/') j++;
    //         string sub = "";
    //         for (int k=i;k<j;++k){
    //             sub += s[k];
    //         }
    //         i = j;
    //     }
    // }
    int ans=n;
    for(int i=1;i<=n+m;i++)
    {
        cin>>s[i];
        string tmp="";
        for(int j=0;j<s[i].length();j++)
        {
            if(s[i][j]=='/')
            {
                if(i>n)//限制条件
                    mp[tmp]=1;
                else//删除条件
                    mp[tmp]=0;
            }
            else 
                tmp+=s[i][j];
        }
    }

    for(int i=1;i<=n;i++)
    {
        string tmp="";
        for(int j=0;j<s[i].length();j++)
        {
            if(s[i][j]=='/')
            {
                if(mp[tmp]==0)
                    mp[tmp]=2;//把他删除，下次碰到同一路径的就不用管了
                else if(mp[tmp]==1)
                    continue;//不能删除，没有贡献
                else if(mp[tmp]==2)
                {
                    ans--;//贡献加一
                    break;//删掉后不会重复贡献
                }
            }
            else
                tmp+=s[i][j];
        }
    }
    cout<<ans<<endl;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}