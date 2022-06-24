#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e6+10000;
char ch[N];
int x[40];
string str;
signed main()
{
    int T,n;
    scanf("%lld",&T);
    while(T--)
    {
        memset(x,0,sizeof(x));
        scanf("%s",ch+1);
        int len = strlen(ch+1);
        for(int i = 1;i<=len;i++)
        {
            x[ch[i]-'a' + 1] ++;
        }
        cin >> str;
        if(str != "abc" || x[1] == 0)
        {
            //printf("OK");
            for(int i = 1;i<=26;i++)
            {
                while(x[i]--)
                {
                    printf("%c",i+'a'-1);
                }
            }
        }
        else
        {
            while(x[1]--)
                {
                    printf("%c",1+'a'-1);
                }
            while(x[3]--)
                {
                    printf("%c",3+'a'-1);
                }
            while(x[2]--)
                {
                    printf("%c",2+'a'-1);
                }
            for(int i = 4;i<=26;i++)
            {
                while(x[i]--)
                {
                    printf("%c",i+'a'-1);
                }
            }
        }
        printf("\n");
    }
    return 0;
}