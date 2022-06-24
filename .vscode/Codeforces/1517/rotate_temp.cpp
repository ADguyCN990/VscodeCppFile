#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int a[10];
    for(int i=1;i<=5;i++) a[i]=i;
    rotate(a+1,a+4,a+1+5);
    for(int i=1;i<=5;i++) cout<<a[i]<<" ";
 
    return 0;
}