#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 305;
int mp[305][305];
int now;
int cnt1=0;int cnt2=0;
int n;
void get(int now)
{
    int fi,se;//首选和次选
    if(now==1)
    {
        fi=2;se=3;
    }
    else if(now==2)
    {
        fi=1;se=3;
    }
    else if(now==3)
    {
        fi=1;se=2;
    }
    //1和2还没填满的话
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(mp[i][j]==0&&(fi==1&&(i+j)%2==0||fi==2&&(i+j)%2==1))
            {
                mp[i][j]=fi;
                cout<<fi<<" "<<i<<' '<<j<<endl;
                cout.flush();
                return;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(mp[i][j]==0)
            {
                mp[i][j]=se;
                cout<<se<<" "<<i<<" "<<j<<endl;
                cout.flush();
                return;
            }
        }
    }
}

void solve()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>now;
            get(now);
        }
    }
}

int main()
{

    solve();
    return 0;
}