#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
char s[MAXN];
int nxt[MAXN];
void solve()
{
     cin>>s+1;
    int len=strlen(s+1);
    int head=1,tot=0;
    for(int i=1;i<=len;i++)
    {
        while(s[head+nxt[tot]]<s[i])
        {
            head+=tot-nxt[tot];
            tot=nxt[tot];
        }
        if(s[i]==s[head+nxt[tot]] && tot)
        {
            tot++;
            nxt[tot]=nxt[tot-1]+1;
        }
        else
        {
            tot++;
            nxt[tot]=0;
        }
        cout<<head<<' '<<i<<"\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}


