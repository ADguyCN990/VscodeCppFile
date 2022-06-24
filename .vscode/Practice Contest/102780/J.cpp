#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct node{
    int x1, x2, x3, x4, x5;
};

node cal(int x){
    for (int i1=0;i1<=x;++i1){
        for (int i2=0;i2<=x*10;++i2){
            for (int i3=0;i3<=x*10;++i3){
                for (int i4=0;i4<=x*10;++i4){
                    for (int i5=0;i5<=x*10;++i5){
                        if (i1 * i1 * i1 + i2 * i2 * i2 + i3 * i3 * i3 + i4 * i4 * i4 + i5 * i5 * i5 == x){
                            return node{i1, i2, i3, i4, i5};
                        }
                    }
                }
            }
        }
    }
    return node{0, 0, 0, 0, 0};
}

bool equals(node x, node y){
    return (x.x1==y.x1 && x.x2 == y.x2 && x.x3 == y.x3 && x.x4==y.x4 && x.x5 == y.x5);
}

int main(void){
    for (int i=1;i<=20;++i){
        node f = cal(i);
        if(!equals(f, node{0,0,0,0,0})){
            cout << i << ": " << f.x1 << " " << f.x2 << " " << f.x3 << " " << f.x4 << " " << f.x5 << endl;
        }
    }

    return 0;
}