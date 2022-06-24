#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
const int M = 5e5;
 
int son[N],head[N],ans[N],rt[N];
 
void problem_solver(){
    int q;
    cin>>q;
    int cnt = 0;
    for(int i=1;i<=M;i++) rt[i] = head[i] = i+M;
    while(q--){
        int op,x,y;
        cin>>op>>x;
        if(op == 2) cin>>y;
        if(op == 1){
            ++cnt;
            son[head[x]] = cnt;
            head[x] = cnt;
        }else{
            if(x == y) continue;
            if(head[x] == rt[x]) continue;
 
            son[head[y]] = son[rt[x]];
            head[y] = head[x];
 
            son[rt[x]] = 0;
            head[x] = rt[x];
        }
    }
    for(int i=1;i<=M;i++) {
        int now = son[rt[i]];
        while(now){
            ans[now] = i;
            now = son[now];
        }
    }
    for(int i=1;i<=cnt;i++) cout<<ans[i]<<" ";
}