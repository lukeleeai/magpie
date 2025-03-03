#include <cstdio>

#include <algorithm>

#include <map>

using namespace std;



int N, MOD = 998244353;

int d1[200020], d2[200020], pow2[200020], s[4][200020];

pair<int,int> p[200020];



inline void add(int i) { for(;i <= N; i+=i&-i) d1[i] += 1; }

inline int  sum(int i) { int ret=0; for(; i > 0; i-=i&-i) ret += d1[i]; return ret; }



int main() {

    scanf("%d", &N);

    for(int i=0; i < N; ++i) scanf("%d%d", &p[i].first, &p[i].second);

    sort(p, p + N);



    map<int,int> m; int j = 0;

    for(int i = 0; i < N; ++i) m[p[i].second] = 0;

    for(auto&& i : m) i.second = ++j;

    for(int i = 0; i < N; ++i) p[i].second = m[p[i].second];



    for(int i = 0; i < N; ++i) {

        s[0][i] = sum(p[i].second);

        s[1][i] = i - s[0][i];

        add(p[i].second);

    }

    swap(d1, d2);

    for(int i = N-1; i >= 0; --i) {

        s[2][i] = sum(p[i].second);

        s[3][i] = (N-1-i) - s[2][i];

        add(p[i].second);

    }



    pow2[0] = 1;

    for(int i = 1; i <= N; ++i) pow2[i] = pow2[i-1] * 2 % MOD;



    long ans = 0, tmp1[4], tmp2[4];

    for(int i = 0; i < N; ++i) {

        for(int j = 0; j < 4; ++j) {

            tmp1[j] = pow2[s[j][i]];

            tmp2[j] = tmp1[j] - 1;

        }

        ans = (ans + tmp2[0] * tmp1[1] % MOD * tmp1[2] % MOD * tmp2[3] % MOD) % MOD;

        ans = (ans + tmp1[0] * tmp2[1] % MOD * tmp2[2] % MOD * tmp1[3] % MOD) % MOD;

        ans = (ans - tmp2[0] * tmp2[1] % MOD * tmp2[2] % MOD * tmp2[3] % MOD + MOD) % MOD;

        ans = (ans + tmp1[0] * tmp1[1] % MOD * tmp1[2] % MOD * tmp1[3] % MOD) % MOD;

    }



    printf("%ld", ans);

    return 0;

}