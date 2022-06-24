#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ZERO 1e-6

string tt[5];
int t[5];
string aver;
int av;

int getNum(string x){
    int res = 0;
    for (int i=0;i<x.size();++i){
        if (x[i]>='0' && x[i]<='9'){
            res = res*10 + (x[i]-'0');
        }
    }
    return res;
}

int main(void){
    double sumt = 0;
    for (int i=1;i<=4;++i){
        cin >> tt[i];
        t[i] = getNum(tt[i]);
        sumt += t[i];
    }
    cin >> aver;
    av = getNum(aver);
    sort(t+1, t+1+4);
    if (sumt - t[1] <= av*3 ){
        cout << "infinite" << endl;
        return 0;
    }
    if (sumt - t[4] > av*3){
        cout << "impossible" << endl;
        return 0;
    }
    int ans = (av*3) - t[2] - t[3];
    int pre = ans/100;
    string aa = to_string(ans);
    cout << pre << "." << aa[aa.size()-2] << aa[aa.size()-1] << endl;
    return 0;

}