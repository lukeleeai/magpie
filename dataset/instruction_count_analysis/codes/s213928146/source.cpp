#include "stdc++.h"



using namespace std;

#define all(x) (x).begin(), (x).end()

#define rep(i, n) for (int i = 0; i < (n); i++)

#define endl "\n"

typedef long long ll;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;



template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os; }

template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;}



void solve() {

    int N, K;

    cin >> N >> K;

    vector<ll> cnt(K);

    for(int i = 1; i <= N; i++) cnt[i % K]++;



    ll ans = 0;

    for(int b = 0; b < K; b++) {

        int a = (K - b) % K;

        int c = (K - b) % K;

        if ((a + c) % K != 0) continue;

        ans += cnt[a] * cnt[b] * cnt[c];

    }

    cout << ans << endl;

}



int main() {

    cin.tie(0);

    ios::sync_with_stdio(false);

    cout.setf(ios::fixed);

    cout.precision(16);

    solve();

    return 0;

}