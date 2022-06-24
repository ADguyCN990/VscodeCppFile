#include<bits/stdc++.h>
using namespace std;
long long n;
void solve()
{
    cin>>n;
    long long num=n/3;//偶数的个数
    long long mod=n%3;
    long long ans=num*mod+(2*num)*(num+1)/2;
    ans+=3*num*(num-1)/2;

    cout<<ans<<endl;
}

int main()
{
    solve();

    return 0;
}