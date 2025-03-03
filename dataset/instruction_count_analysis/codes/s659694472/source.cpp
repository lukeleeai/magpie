#include <algorithm>

#include <iostream>

#include <vector>

#include <cctype>

#include <cstdio>

using namespace std;



#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

#define ALL(c) (c).begin(), (c).end()



int64_t read_int() noexcept {

    int64_t ret = 0, sgn = 1;

    int ch = getchar_unlocked();

    if (isspace(ch)) { ch = getchar_unlocked(); }

    if (ch == '-') { sgn = -1; ch = getchar_unlocked(); }

    while (isdigit(ch)) {

        ret = (ret * 10) + (ch - '0');

        ch = getchar_unlocked();

    }

    ungetc(ch, stdin);

    return sgn * ret;

}



inline pair<int64_t, int64_t> read_pair() noexcept {

    int a = read_int();

    int b = read_int();

    return {a, b};

}



int main() {

    int N = read_int();

    vector<pair<int64_t, int64_t>> points(N);

    REP(i, N) points[i] = read_pair();



    vector<vector<int64_t>> f(N);

    REP(i, N) {

        auto [x, y] = points[i];

        f[i] = {x-y, x+y};

    }



    int64_t ans = numeric_limits<int64_t>::min();

    REP(d, 2) {

        auto m1 = numeric_limits<int64_t>::max();

        auto m2 = numeric_limits<int64_t>::min();

        REP(i, N) m1 = min(m1, f[i][d]);

        REP(i, N) m2 = max(m2, f[i][d]);

        ans = max(ans, m2 - m1);

    }

    cout << ans << endl;

}
