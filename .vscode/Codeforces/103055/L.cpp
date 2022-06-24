#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 100005
int n;
char s[MAXN];
int ne[MAXN];

void getnext() {
    for (int i = 2, j = 0; i <= n; i++) {
        while (j && s[i] != s[j + 1]) j = ne[j];
        if (s[i] == s[j + 1]) j++;
        ne[i] = j;
    }
}

int main() {
    cin >> n;
    scanf("%s", s + 1);
    getnext();
    for (int i = 2; i <= n; i++) {
        if (ne[i] > 0) {
            puts("Wrong Answer");
            return 0;
        }
    }
    puts("Correct");
    return 0;
}