#include "stdc++.h"

using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

const int inf = 1e9;

const ll INF = 1e18;

const double pi = 3.14159265358979323846;

#define rep(i, n) for (int i = 0; i < n; i++)

using Graph = vector<vector<int>>;

using pint = pair<int, int>;

int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

int dxx[8] = { 1, 1, 1, 0, 0, -1, -1, -1 }, dyy[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };



int main() {

    int n, m;

    cin >> n >> m;

    pair<ll, ll> p[200005];

    ll l;

    vector<ll> a (n), b (m), c (m);

    rep (i, n) {

        cin >> p[i].first;

        p[i].second = 1;

        l++;

    }

    rep (i, m) {

        cin >> p[n + i].second >> p[n + i].first;

        l += p[n + i].first;

    }

    sort (p, p + n + m, greater<pair<ll, ll>>());

    ll ans = 0, now = n;

    rep (i, n) {

        if (now > p[i].second) {

            ans += p[i].first * p[i].second;

            now -= p[i].second;

        } else {

            ans += p[i].first * now;

            break;

        }

    }

    cout << ans << "\n";

}