#include<bits/stdc++.h>
using namespace std;
bool vis[45];
string a[45];
int get() {
    
    int a = rand();
    a = a % 39 + 1;
    //printf("%d\n", a);
    return a;
}

int main() {
    memset(vis, false, sizeof vis);
    srand((unsigned)time(NULL));
    for (int i = 1; i <= 11; i++) { //优秀
        int num;
        while (1) {
            int x = get();
            if (!vis[x]) {
                vis[x] = true;
                num = x;
                break;
            }
        }
        a[num] = "very good";
    }
    for (int i = 1; i <= 21; i++) { //良好
        int num;
        while (1) {
            int x = get();
            if (!vis[x]) {
                vis[x] = true;
                num = x;
                break;
            }
        }
        a[num] = "good";
    }
    for (int i = 1; i <= 7; i++) { //及格
        int num;
        while (1) {
            int x = get();
            if (!vis[x]) {
                vis[x] = true;
                num = x;
                break;
            }
        }
        a[num] = "nod bad";
    }
    for (int i = 1; i <= 39; i++) {
        if (i == 24)
            printf("this is me, ignore it\n");
        else {
            if (i < 17)
                printf("id: %d goal: ", i), cout << a[i] << endl;
            else
                printf("id: %d goal: ", i + 1), cout << a[i] << endl;
        }
            
    }
    return 0;
}