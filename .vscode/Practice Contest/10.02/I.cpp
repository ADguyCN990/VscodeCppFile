#include<bits/stdc++.h>
using namespace std;

string s1, s2;
int s1len, s2len;

void solve(){
    cin >> s1 >> s2;
    s1len = s1.size(), s2len = s2.size();
    int j = 0;
    for (int i=0;i<s1len;++i){
        if (s1[i]==s2[j]){
            j++;
            if (j >= s2len){
                break;
            }
        }
    }
    if (j==s2len){
        puts("Yes");
    }
    else{
        puts("No");
    }

}

int main()
{
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    solve();
    return 0;
}