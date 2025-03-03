#include"stdc++.h"

using namespace std;



typedef long long ll;



const int mod = 1e9 + 7;

const int MN = 100010;



int N;

ll A, B;

ll S[MN];

int psum[MN], dp[MN];



int calc(int l, int r) {

    if(l > r) return 0;

    return psum[r] - (l? psum[l - 1] : 0);

}



struct Fenwick {

    vector<int> tree;

    void init() {

        tree = vector<int>(MN + 1, 0);

    }

    void upd(int idx, int val) {

        for(int i = idx + 1; i <= MN; i += (i & -i)) tree[i] += val, tree[i] %= mod;

    }

    int quer(int a) {

        int ret = 0;

        for(int i = a + 1; i >= 1; i -= (i & -i)) ret += tree[i], ret %= mod;

        return ret;

    }

    int quer(int a, int b) {

        if(a > b) return 0;

        return (quer(b) + mod - quer(a - 1)) % mod;

    }

} fw;



int main() {

    scanf("%d %lld %lld", &N, &A, &B);

    if(A > B) swap(A, B);



    for(int i = 0; i < N; i++) {

        scanf("%lld", &S[i]);

    }



    for(int i = 0; i < N - 2; i++) {

        if(S[i + 2] - S[i] < A) {

            printf("0");

            return 0;

        }

    }



    for(int i = 1; i < N; i++) {

        psum[i] = S[i] - S[i - 1] < A;

        psum[i] += psum[i - 1];

    }



    fw.init();

    dp[N] = 1;

    fw.upd(N, dp[N]);



    int pos1 = N;

    int pos2 = N;

    for(int i = N - 1; i >= 0; i--) {

        while(pos1 >= 1 && S[pos1 - 1] - S[i] >= B) pos1--;

        while(pos2 >= 0 && calc(i + 2, pos2 - 1)) pos2--;

        dp[i] = fw.quer(pos1, pos2);

        fw.upd(i, dp[i]);

    }

    int ans = 0;

    for(int i = 0; i <= N; i++) {

        if(!calc(0, i - 1)) ans += dp[i], ans %= mod;

    }

    printf("%d", ans);

}
