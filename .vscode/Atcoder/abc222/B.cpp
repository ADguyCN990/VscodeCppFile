#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int a[MAXN];
int p;
int n;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>p;
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<p) cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}