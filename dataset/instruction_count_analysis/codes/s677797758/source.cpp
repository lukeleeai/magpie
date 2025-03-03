#include "stdc++.h"

#define ull uint64_t

#define ll long long int

#define pb push_back

#define mp make_pair

#define ff first

#define ss second

#define mx4 10005

#define mx5 100005

#define mx6 1000005

#define mod 1000000007

#define nfs ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;



struct block {

    int w, s, v;

    bool operator<(const block& b) {

        return w + s < b.w + b.s;

    }

};



int main() {

    nfs

    int i, j, n, w, s, v;

    ll ans = 0;

    ll dp[mx4] = {};

    

    cin >> n;

    

    vector <block> blocks;

    for (i = 0; i < n; i++) {

        cin >> w >> s >> v;

        blocks.pb({w, s, v});

    }

    sort(blocks.begin(), blocks.end());



    for (auto& b : blocks) {

        for (j = b.s; j >= 0; j--) {

            if (b.w + j < mx4) {

                dp[b.w + j] = max(dp[b.w + j], b.v + dp[j]);

            }

            ans = max(ans, b.v + dp[j]);

        }

    }

    cout << ans;

}