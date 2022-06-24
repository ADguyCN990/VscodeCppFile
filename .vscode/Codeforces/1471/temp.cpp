#include<bits/stdc++.h>
using namespace std;

int a[100];
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    for(int i=1;i<100;i++) a[i]=i;
    cout<<upper_bound(a+1,a+1+99,5)-a<<endl;
    cout<<upper_bound(a+1,a+1+99,5)-a-1;

    return 0;
}