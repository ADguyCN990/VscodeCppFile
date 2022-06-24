#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
int n;
set<string> st;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> n;
    while(n--){
        string s;
        cin >> s;
        if(s[0]!='-'){
            st.insert(s);
        }
    }
    int p = 0;
    while(true){
        string tmp = to_string(p);
        if(st.find(tmp)==st.end()){
            cout << tmp << endl;
            return 0;
        }
        p++;
    }
    return 0;
}