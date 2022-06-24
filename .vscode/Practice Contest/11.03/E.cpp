#include <bits/stdc++.h>
using namespace std;

int n;
const int Max_n = 1e6 + 10;
int a[Max_n];

int read(){
    int x=0,f=1;char ch;
    do{ch=getchar();if(ch=='-')f=-1;}while(ch<'0' || ch>'9');
    do{x=x*10+ch-48;ch=getchar();}while (ch>='0' && ch<='9');
    return x*f;
}

int gcd(int a,int b)
{
    int temp;
    while(b)
    {
        temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
int mn;
int cnt;
void solve()
{
    n=read();
    for(int i=1;i<=n;i++) a[i]=read();
    cnt=0;mn=0x3f3f3f3f;
    for(int i=1;i<=n;i++)
    {
        if(a[i]<mn)
        {
            mn=a[i];
            cnt=1;
        }
        else if(a[i]==mn)
        {
            cnt++;
        }
    }
    int G=a[1];
    for(int i=2;i<=n;i++) G=gcd(G,a[i]);
    //cout<<"mn: "<<mn<<" G: "<<G<<endl;
    if(G==mn)
    {
        cout<<(cnt+1)/2<<endl;
    }
    else
    {
        cout<<1<<endl;
    }
}

int main(void){
    int t;
    cin>>t;
    while(t--)
    {
        solve();
    }
    
}