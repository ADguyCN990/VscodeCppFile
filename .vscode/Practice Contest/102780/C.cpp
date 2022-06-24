#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

int n;
const int N = 1e4 + 5;
map<char,int> mp;
char s[N];
string t0 = "[~\\PDCE%X8";
string t1 = "0|";

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> s;
    n = strlen(s);
    for (int i=0;i<n;++i){
        mp[s[i]]++;
    }
    int t0len = t0.size();
    for (int i=0;i<t0len;++i){
        char x = t0[i];
        string t = "";
        while (mp[x] > 0){
            if (x == '['){
                t = "[:|||:]";
            }
            else if (x == '~'){
                t = ":~("; 
            }
            else if (x == '\\'){
                t = ":-\\";
            }
            else if (x == 'P'){
                t = ":-P";
            }
            else if (x == 'D'){
                t = ":D";
            }
            else if (x == 'C'){
                t = ":C";
            }
            else if (x == 'E'){
                t = ":-E";
            }
            else if (x == '%'){
                t = "%0";
            }
            else if (x == 'X'){
                t = ":-X";
            }
            else if (x == '8'){
                t = "8-0";
            }
            for (int j=0;j<t.size();++j){
                mp[t[j]]--;
            }
            cout << t << endl;
        }
    }
    for (int i=0;i<2;++i){
        char x = t1[i];
        string t = "";
        while (mp[x] > 0){
            if (x == '0'){
                t = ":-0";
            }
            else if (x == '|'){
                t = ":-|";
            }
            for (int j=0;j<t.size();++j){
                mp[t[j]]--;
            }
            cout << t << endl;
        }
    }
    while (mp[';'] > 0){
        string t = ";-";
        mp[';']--, mp['-']--;
        if (mp['('] > 0){
            mp['(']--, t += '(';
        }
        else if (mp[')'] > 0){
            mp[')']--, t+= ')';
        }
        cout << t << endl;
    }
    while (mp[':'] > 0){
        string t = ":";
        mp[':']--;
        if (mp['('] > 0){
            mp['(']--, t += '(';
        }
        else if (mp[')'] > 0){
            mp[')']--, t+= ')';
        }
        cout << t << endl;
    }
    cout << "LOL" << endl;
    return 0;
}