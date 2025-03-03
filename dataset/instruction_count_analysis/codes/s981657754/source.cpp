#include"stdc++.h"

using namespace std;



typedef long long ll;

const int mod = 1000*1000*1000+7;

const int MN = 100010;



int N;

ll A, B;

vector<ll> S;



struct BIT {

    ll tree[4*MN];

    void init() {

        memset(tree, 0, sizeof(tree));

    }

    void build(int l, int r, int n) {

        if(l == r) {

            tree[n] = (l == 0? S[l] : S[l] - S[l - 1]);

            return;

        }

        int m = (l + r)>>1;

        build(l, m, 2*n);

        build(m + 1, r, 2*n + 1);

        tree[n] = min(tree[2*n], tree[2*n + 1]);

    }

    ll quer(int a, int b, int l, int r, int n) {

        if(b < l || r < a) return 1e18;

        if(a <= l && r <= b) return tree[n];

        int m = (l + r)>>1;

        ll L = quer(a, b, l, m, 2*n);

        ll R = quer(a, b, m + 1, r, 2*n + 1);

        return min(L, R);

    }

} bit;



int cc[100010];

int dp(int idx) {

    int &ret = cc[idx];

    if(ret != -1) return ret;



    if(idx == N) return ret = 1;



    ret = 0;

    if(idx == 0 || S[idx] - S[idx - 1] >= B) {

        ret += dp(idx + 1);

        ret %= mod;

    }



    int s = idx + 1, e = N - 1;

    int x = N;

    while(s <= e) {

        int m = (s + e)>>1;



        if(S[m] - S[idx] >= A) {

            x = m;

            e = m - 1;

        }

        else s = m + 1;

    }



    if(((idx != N - 1 && idx >= 1)? S[idx + 1] - S[idx - 1] >= B : 1) && bit.quer(idx + 2, x - 1, 0, N - 1, 1) >= B) {

        ret += dp(x);

        ret %= mod;

    }



    return ret;

}



int main() {

    scanf("%d %lld %lld", &N, &A, &B);

    S.resize(N);

    for(int i = 0; i < N; i++) {

        scanf("%lld", &S[i]);

    }



    if(A < B) swap(A, B);



    bit.init();

    bit.build(0, N - 1, 1);

    memset(cc, -1, sizeof(cc));



    printf("%d", dp(0));

}
