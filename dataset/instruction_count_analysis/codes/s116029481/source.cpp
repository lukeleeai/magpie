#include <algorithm>

#include <climits>

#include <complex>

#include <cstring>

#include <iostream>

#include <map>

#include <queue>

#include <set>

#include <vector>



// using

using namespace std;



// typedef

typedef long long ll;



// define

#define FOR(i, a, b, c) for (int i = (int)(a); i < (int)(b); i += (int)(c))

#define REP(i, n) FOR(i, 0, n, 1)

#define RFOR(i, a, b, c) for (int i = (int)(a); i >= (int)(b); i -= (int)(c))

#define RREP(i, n) RFOR(i, n, 0, 1)

#define ALL(c) (c).begin(), (c).end()

#define SORT(c) sort(ALL(c))

#define REVERSE(c) reverse(ALL(c))

#define UNIQ(c) unique(ALL(c))

#define LB(c, x) lower_bound(c.begin(), c.end(), x)

#define UB(c, x) upper_bound(c.begin(), c.end(), x)

#define LI(c, x) distance(c.begin(), LB(c, x))

#define UI(c, x) distance(c.begin(), UB(c, x))



// functions

template <class T> T ceil(T a, T b) {

    return (a + b - 1) / b;

}

template <class T> T round(T a, T b) {

    return (a + b / 2) / b;

}

template <class T> T gcd(T a, T b) {

    return b ? gcd(b, a % b) : a;

}

template <class T> T lcm(T a, T b) {

    return a / gcd(a, b) * b;

}

template <class T> bool amax(T& a, const T& b) {

    if (a < b) {

        a = b;

        return true;

    }

    return false;

}

template <class T> bool amin(T& a, const T& b) {

    if (b < a) {

        a = b;

        return true;

    }

    return false;

}



int dp[101][4][4][4];



bool is_valid(int c3, int c2, int c1, int c0) {

    if (c2 == 0 && c1 == 2 && c0 == 1) {

        return false;

    } else if (c2 == 2 && c1 == 0 && c0 == 1) {

        return false;

    } else if (c2 == 0 && c1 == 1 && c0 == 2) {

        return false;

    } else if (c3 == 0 && c2 == 2 && c0 == 1) {

        return false;

    } else if (c3 == 0 && c1 == 2 && c0 == 1) {

        return false;

    }

    return true;

}



// main

int main() {

    cin.tie(0);

    ios::sync_with_stdio(false);

    const int MOD = 1e9 + 7;

    int N;

    cin >> N;

    dp[0][3][3][3] = 1;

    REP(i, N) {

        REP(c3, 4) {

            REP(c2, 4) {

                REP(c1, 4) {

                    if (dp[i][c3][c2][c1] == 0) {

                        continue;

                    }

                    REP(c0, 4) {

                        if (!is_valid(c3, c2, c1, c0)) {

                            continue;

                        }

                        dp[i + 1][c2][c1][c0] += dp[i][c3][c2][c1];

                        dp[i + 1][c2][c1][c0] %= MOD;

                    }

                }

            }

        }

    }

    int res = 0;

    REP(c3, 4) {

        REP(c2, 4) {

            REP(c1, 4) {

                res += dp[N][c3][c2][c1];

                res %= MOD;

            }

        }

    }

    cout << res << endl;

    return 0;

}
