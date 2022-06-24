#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 105
char mp[MAXN][MAXN];
struct node
{
    int id;
    int val;
}a[MAXN];
int n,m;
bool cmp(node a,node b)
{
    if(a.val==b.val) return a.id<b.id;
    return a.val>b.val;
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    n*=2;
    for(int i=1;i<=n;i++)
    {
        string s;
        cin>>s;
        for(int j=0;j<m;j++)
        {
           mp[i][j+1]=s[j];
        }
        a[i].id=i;
    }
    int cnt=0;
    while(m--)
    {
        cnt++;        
        for(int i=1;i<=n;i+=2)//排名
        {
            char x=mp[a[i].id][cnt];char y=mp[a[i+1].id][cnt];
            if(x=='G'&&y=='C'||x=='C'&&y=='P'||x=='P'&&y=='G')
            {
                a[i].val++;
            }
            else if(y=='G'&&x=='C'||y=='C'&&x=='P'||y=='P'&&x=='G')
            {
                a[i+1].val++;
            }
        }

        sort(a+1,a+1+n,cmp);
    }
    for(int i=1;i<=n;i++) cout<<a[i].id<<endl;
    return 0;
}