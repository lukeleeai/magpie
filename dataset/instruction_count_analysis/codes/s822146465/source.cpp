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



const int MOD = 1e9 + 7;

int N;

vector<map<string, ll>> cnt;

string S[4] = {"A", "C", "G", "T"};



bool is_valid(string s) {

    REP(i, 4) {

        string t = s;

        if (i > 0) {

            swap(t[i - 1], t[i]);

        }

        if (t.find("AGC") != string::npos) {

            return false;

        }

    }

    return true;

}



ll dfs(int i, string s) {

    if (cnt[i].count(s) > 0) {

        return cnt[i][s];

    }

    if (i == N) {

        return 1;

    }

    ll res = 0;

    REP(j, 4) {

        string t = s + S[j];

        if (is_valid(t)) {

            res = (res + dfs(i + 1, t.substr(1))) % MOD;

        }

    }

    cnt[i][s] = res;

    return res;

}



// main

int main() {

    cin.tie(0);

    ios::sync_with_stdio(false);

    cin >> N;

    cnt = vector<map<string, ll>>(N + 1);

    cout << dfs(0, "ZZZ") << endl;

    return 0;

}
