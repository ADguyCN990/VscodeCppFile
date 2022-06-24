#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005
ll n,m;
struct node
{
    string val;
    int id;
    int order;
}s[MAXN];
//字符串奇数升序，偶数降序排列
bool cmp(node a,node b){return a.val<b.val;}
bool cmpp(node a,node b){return a.id<b.id;}
map <char,char> mp;
int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin>>n>>m;
    {
        mp['A']='Z';mp['Z']='A';
        mp['B']='Y';mp['Y']='B';
        mp['C']='X';mp['X']='C';
        mp['D']='W';mp['W']='D';
        mp['E']='V';mp['V']='E';
        mp['F']='U';mp['U']='F';
        mp['G']='T';mp['T']='G';
        mp['H']='S';mp['S']='H';
        mp['I']='R';mp['R']='I';
        mp['J']='Q';mp['Q']='J';
        mp['K']='P';mp['P']='K';
        mp['L']='O';mp['O']='L';
        mp['M']='N';mp['N']='M';
    }

    for(int i=1;i<=n;i++)
    {
        string temp;
        cin>>temp;
        s[i].id=i;
        for(int j=1;j<temp.length();j+=2) temp[j]=mp[temp[j]];
        s[i].val=temp; 
    }
    sort(s+1,s+1+n,cmp);
    for(int i=1;i<=n;i++)
    {
        s[i].order=i;
        cout<<s[i].id<<" ";
    }   
    
    return 0;
}