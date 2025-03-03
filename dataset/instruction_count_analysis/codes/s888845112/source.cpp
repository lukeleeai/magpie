#include <stdio.h>



using lli = long long int;



// constexpr version : N が clang++ : 3e5くらいまでok,  g++ : 2e6くらいまでok

template <int N, long long int mod>

struct CombinationMod{

private:

    using lli = long long int;

public:

    lli Power[N+1], Inverse[N+1], powInverse[N+1];

    constexpr CombinationMod():Power(), Inverse(), powInverse(){

        Power[0] = 1; Inverse[0] = 1; powInverse[0] = 1;

        for(int x = 1; x <= N; ++x) Power[x] = (Power[x-1] * x) % mod;

        powInverse[N] = inverse(Power[N]);

        for(int x = N; x > 0; --x) powInverse[x-1] = (powInverse[x] * x) % mod;

        for(int x = 1; x <= N; ++x) Inverse[x] = (Power[x-1] * powInverse[x]) % mod;

    }

    constexpr void swap(lli &a, lli &b) const {

        a ^= b; b ^= a; a ^= b;

    }

    constexpr lli inverse(lli a) const noexcept{

        lli b = mod, u = 1, v = 0;

        while (b != 0) { 

            lli t = a / b; a -= t * b; swap(a, b);

            u -= t * v; swap(u, v);

        }

        u %= mod; if (u < 0) u += mod;

        return u;

    }

    // nCkを求める関数 : n < k の入力に注意せよ

    inline lli combination(int n, int k) const noexcept{

        if(n < k) return 0;

        return ((Power[n] * powInverse[k] % mod) * powInverse[n-k]) % mod;

    }

};



constexpr int SizeN = 2e5 + 1;

constexpr int mod = 1e9 + 7;

constexpr CombinationMod<SizeN, mod> Cmb;





int main(void){

    int n, m, k; scanf("%d%d%d", &n, &m, &k);

    lli T1 = m; (T1 *= m) %= mod; (T1 *= Cmb.combination(n+1, 3)) %= mod;

    lli T2 = n; (T2 *= n) %= mod; (T2 *= Cmb.combination(m+1, 3)) %= mod;

    lli res = T1 + T2;

    (res *= Cmb.combination(n*m-2, k-2)) %= mod;

    printf("%lld\n", res);

    return 0;

}
