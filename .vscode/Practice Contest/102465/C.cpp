#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 1000005

struct trie {
    int tot, son[MAXN][30];
    int fa[MAXN]; //字典树某个节点的前驱，搜索恢复现场用
    trie() {tot = 0;} //字典树节点编号
    void insert(char s[], int len) {
        int now = 0; //字典树根
        for (int i = 0; i < len; i++) {
            int u = s[i] - 'a';
            if (!son[now][u]) {
                son[now][u] = ++tot;
                fa[tot] = now;
            }
            now = son[now][u];
        }
    }
}trie1, trie2;

int n, m, a, b, pos1[10], pos2[10];
int ans;
char s[MAXN];

void dfs(int now) {
    if (now == n * m) {
        ans++;
        return;
    }
    int row = now / m, col = now % m;
    for (int i = 0; i < 26; i++) {
        //暴力枚举每个字符
        if (trie1.son[pos1[col]][i] && trie2.son[pos2[row]][i]) {
            //如果两个pos指针都匹配上了，更新状态继续往深搜索
            pos1[col] = trie1.son[pos1[col]][i];
            pos2[row] = trie2.son[pos2[row]][i];
            dfs(now + 1);
            //利用之前预处理的结果恢复现场
            pos1[col] = trie1.fa[pos1[col]];
            pos2[row] = trie2.fa[pos2[row]];
        }
    }
}

int main() {
    scanf("%d%d", &n, &a);
    scanf("%d%d", &m, &b);
    for (int i = 1; i <= a; i++) {
        scanf("%s", s);
        trie1.insert(s, strlen(s));
    }
    for (int i = 1; i <= b; i++) {
        scanf("%s", s);
        trie2.insert(s, strlen(s));
    }
    dfs(0);
    printf("%d\n", ans);
    return 0; 
}