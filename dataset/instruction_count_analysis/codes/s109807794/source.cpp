#include "stdc++.h"



using namespace std;

#define pb push_back

#define mp make_pair

#define all(x) (x).begin(),(x).end()

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

typedef unsigned long long ull;

typedef pair<int,int> pii;

constexpr int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};

constexpr int dy[] = {0, -1, 0, 1, 1, -1, -1, 1};



template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec){os << "["; for (const auto &v : vec) {os << v << ","; } os << "]"; return os; }

template <typename T, typename U> ostream &operator<<(ostream &os, const pair<T, U> &p) {os << "(" << p.first << ", " << p.second << ")"; return os;}



bool check(int j, int W) {

    bool ok = true;

    for (int k = 0; k + 1 < (W - 1); k++) {

        if ((j >> k & 1) && ((j >> (k + 1)) & 1)) ok = false;

    }

    return ok;

}



void solve() {

    int H, W, K;

    const int mod = 1e9 + 7;

    cin >> H >> W >> K;

    K--;



    vector<vector<vector<int>>> dp(H + 1, vector<vector<int>>(1 << (W - 1), vector<int>(W)));

    



    dp[0][0][0] = 1;

    for (int i = 0; i < H; i++) {

        for (int j = 0; j < 1 << (W - 1); j++) {

            if (!check(j, W)) continue;

            for (int k = 0; k < W; k++) {

                for (int l = 0; l < 1 << (W - 1); l++) {

                    if (!check(l, W)) continue;

                    int pos = k;

                    if (k % 2 == 0) {

                        if (l >> k & 1) pos++;

                        else if (k >= 1 && l >> (k - 1) & 1) pos--;

                    } else {

                        if (l >> (k - 1) & 1) pos--;

                        else if (l >> k & 1) pos++;

                    }

                    dp[i + 1][l][pos] += dp[i][j][k];

                    dp[i + 1][l][pos] %= mod;

                }

            }

        }

    }

    

    int ans = 0;

    for (int j = 0; j < 1 << (W - 1); j++) {

        ans += dp[H][j][K];

        ans %= mod;

    }



    cout << ans << endl;

}



int main() {

    solve();

    return 0;

}