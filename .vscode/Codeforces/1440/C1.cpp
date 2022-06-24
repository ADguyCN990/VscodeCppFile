#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
ll n,m;
char s[MAXN][MAXN];

struct node
{
    int x,y,xx,yy,xxx,yyy;
};
vector <node> ans;
void work(int i,int j)
{
        int a=s[i][j]-'0';int b=s[i][j+1]-'0';int c=s[i+1][j]-'0';int d=s[i+1][j+1]-'0';
            int cnt=a+b+c+d;
            if(cnt==0) return;
            if(cnt==1)
            {
                if(a==1)
                {
                    ans.emplace_back(node{i,j,i,j+1,i+1,j});
                    ans.emplace_back(node{i,j,i+1,j,i+1,j+1});
                    ans.emplace_back(node{i,j,i,j+1,i+1,j+1});
                }
                else if(b==1)
                {
                    ans.emplace_back(node{i,j,i,j+1,i+1,j+1});
                    ans.emplace_back(node{i,j+1,i+1,j,i+1,j+1});
                    ans.emplace_back(node{i,j,i,j+1,i+1,j});
                }
                else if(c==1)
                {
                    ans.emplace_back(node{i,j,i+1,j,i+1,j+1});
                    ans.emplace_back(node{i,j+1,i+1,j,i+1,j+1});
                    ans.emplace_back(node{i,j,i,j+1,i+1,j});
                }
                else if(d==1)
                {
                    ans.emplace_back(node{i,j+1,i+1,j,i+1,j+1});
                    ans.emplace_back(node{i,j,i+1,j,i+1,j+1});
                    ans.emplace_back(node{i,j,i,j+1,i+1,j+1});
                }
            }
            else if(cnt==2)
            {
                if(a==1&&b==1)
                {
                    ans.emplace_back(node{i,j,i+1,j,i+1,j+1});
                    ans.emplace_back(node{i,j+1,i+1,j,i+1,j+1});
                }
                else if(a==1&&c==1)
                {
                    ans.emplace_back(node{i,j+1,i+1,j,i+1,j+1});
                    ans.emplace_back(node{i,j,i,j+1,i+1,j+1});
                }
                else if(a==1&&d==1)
                {
                    ans.emplace_back(node{i,j+1,i+1,j,i+1,j+1});
                    ans.emplace_back(node{i,j,i,j+1,i+1,j});
                }
                else if(b==1&&c==1)
                {
                    ans.emplace_back(node{i,j,i+1,j,i+1,j+1});
                    ans.emplace_back(node{i,j,i,j+1,i+1,j+1});
                }
                else if(b==1&&d==1)
                {
                    ans.emplace_back(node{i,j,i,j+1,i+1,j});
                    ans.emplace_back(node{i,j,i+1,j,i+1,j+1});
                }
                else if(c==1&&d==1)
                {
                    ans.emplace_back(node{i,j,i,j+1,i+1,j});
                    ans.emplace_back(node{i,j,i,j+1,i+1,j+1});
                }
            }
            else if(cnt==3)
            {
                if((a==1&&b==1)&&(a==1&&c==1))
                    ans.emplace_back(node{i,j,i,j+1,i+1,j});
                else if((a==1&&b==1)&&(a==1&&d==1))
                    ans.emplace_back(node{i,j,i,j+1,i+1,j+1});
                else if((a==1&&c==1)&&(a==1&&d==1))
                    ans.emplace_back(node{i,j,i+1,j,i+1,j+1});
                else if((c==1&&b==1)&&(d==1&&c==1))
                    ans.emplace_back(node{i,j+1,i+1,j,i+1,j+1});
            }
            else if(cnt==4)
            {
                ans.emplace_back(node{i,j+1,i+1,j,i+1,j+1});
                ans.emplace_back(node{i,j,i,j+1,i+1,j});
                ans.emplace_back(node{i,j,i+1,j,i+1,j+1});
                ans.emplace_back(node{i,j,i,j+1,i+1,j+1});
            }
            s[i][j]='0';s[i][j+1]='0';s[i+1][j]='0';s[i+1][j+1]='0';
}

void solve()
{
    cin>>n>>m;
    ans.clear();
    for(int i=1;i<=n;i++)
    {
        scanf("%s",s[i]+1);
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            work(i,j);
        }
    }
    cout<<ans.size()<<endl;
    for(auto t:ans)
        cout<<t.x<<" "<<t.y<<" "<<t.xx<<" "<<t.yy<<" "<<t.xxx<<" "<<t.yyy<<endl;
}   

int main()
{
    //ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int T;
    cin>>T;
    while(T--)
    {
        solve();
    }
    return 0;
}