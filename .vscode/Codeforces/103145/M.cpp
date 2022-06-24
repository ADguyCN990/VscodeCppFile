#include<bits/stdc++.h>
using namespace std;

map<string, string> sm;
map<string, string> ym;

void init() {
    sm["zh"] = "v";
    sm["sh"] = "u";
    sm["ch"] = "i";
    ym["iu"] = "q";
    ym["ei"] = "w";
    ym["uan"] = "r";
    ym["ue"] = "t";
    ym["un"] = "y";
    ym["uo"] = "o";
    ym["ie"] = "p";
    ym["ong"] = "s", ym["iong"] = "s";
    ym["ai"] = "d";
    ym["en"] = "f";
    ym["eng"] = "g";
    ym["ang"] = "h";
    ym["an"] = "j";
    ym["uai"] = "k", ym["ing"] = "k";
    ym["uang"] = "l", ym["iang"] = "l";
    ym["ou"] = "z";
    ym["ia"] = "x", ym["ua"] = "x";
    ym["ao"] = "c";
    ym["ui"] = "v";
    ym["in"] = "b";
    ym["iao"] = "n";
    ym["ian"] = "m";
}

void work(string s) {
    int len = s.size();
    if (len == 1) {
        cout << s << s;
        return;
    }
    if (len == 2) {
        cout << s;
        return;
    }
    if (s == "ang") {
        cout << "ah";
        return;
    }
    string tmp = s.substr(0, 2);
    string a, b;
    if (tmp == "zh" || tmp == "ch" || tmp == "sh") {
        a = tmp;
        b = s.substr(2, len - 2);
    }
    else {
        a = s[0];
        b = s.substr(1, len - 1);
    }
    if (a.size() == 1)
        cout << a;
    else
        cout << sm[a];
    if (b.size() == 1)
        cout << b;
    else
        cout << ym[b];
        
}

int main() {
    init();
    string t;
    while (getline(cin, t)) {
        string s = "";
        for (int i = 0; i < t.length(); i++) {
            if (t[i] == ' ') {
                work(s);
                printf(" ");
                s = "";
            }
            else
                s += t[i];
        }
        work(s);
        puts("");
    }
}