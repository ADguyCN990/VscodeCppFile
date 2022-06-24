    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long

    int n;
    const int N = 1e6 + 5;
    const ll M = 1e9 + 7;
    ll C[N], a[N];
    // int cnt[N];
    ll ans = 1;
    stack<pair<int,int>> st;

    ll read();
    ll qmi(ll a, ll b, ll p);
    void init();

        int main(void){
        init();
        n = read();
        int x = 1;
        for (int i=1;i<=n;++i){
            a[i] = read();
        }
        for(int i=1;i<=n;i++){
            if(st.empty()||a[i]>st.top().first)
                st.push(make_pair(a[i],1));
            else if(a[i]==st.top().first){
                st.top().second++;
            }else{
                while(!st.empty()&&st.top().first>a[i]){
                    if(st.top().second>1)
                        ans = ans*C[st.top().second]%M;
                    st.pop();
                }
                if(st.empty() || st.top().first < a[i])
                    st.push(make_pair(a[i],1));
                else
                    st.top().second++;
            }
        }
        while(!st.empty()){
            if(st.top().second>1)
            ans = ans*C[st.top().second]%M;
            st.pop();
        }
        printf("%lld\n", ans);

        return 0;
    }

    ll read() {
        ll x=0,f=1;char ch;
        do{ch=getchar();if(ch=='-') f=-1;} while(ch<'0'||ch>'9');
        do{x=x*10+ch-48;ch=getchar();} while(ch>='0'&&ch<='9');
        return x*f;
    }

    ll qmi(ll a, ll b, ll p){
        ll res = 1LL % p;
        while (b){
            if (b & 1) res = (ll) res * a % p;
            a = (ll) a * a % p;
            b >>= 1;
        }
        return res;
    }

    void init(){
        C[0] = C[1] = 1LL;
        for (int i=2;i<N;++i){
            C[i] = 1LL * C[i - 1] * (4 * i - 2) % M * qmi(i + 1, M - 2, M) % M;
        }
    }
    
