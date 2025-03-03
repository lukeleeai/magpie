#include "stdc++.h"

using namespace std;

typedef long long ll;

const ll inf = 1e18;

#define rep(i, a, b) for (int i = a; i < b; i++)

#define per(i, a, b) for (int i = b - 1; i >= a; i--)

#define int ll

using pint = pair<int, int>;

int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};



signed main() {

    int n, m;

    cin >> n >> m;

    vector<int> vec;

    rep (i, 0, n) {

        int a;

        cin >> a;

        vec.push_back (a);

    }

    sort (vec.begin(), vec.end(), greater<int>());

    pint bc[m];

    rep (i, 0, m) { cin >> bc[i].second >> bc[i].first; }

    sort (bc, bc + m, greater<pint>());

    int cnt = 0;

    int i = 0, j = 0;

    int ans = 0;

    while (cnt < n) {

        if (i < n && j < m) {



            if (vec[i] > bc[j].first) {

                ans += vec[i];

                i++;

                cnt++;

            } else {

                if (n - cnt > bc[j].second) {

                    ans += bc[j].second * bc[j].first;

                    cnt += bc[j].second;

                    j++;

                } else {

                    ans += bc[j].first * (n - cnt);

                    j++;

                    cnt = n;

                }

            }

        } else if (i < n) {

            ans += vec[i];

            i++;

            cnt++;

        } else {

            if (n - cnt > bc[j].second) {

                ans += bc[j].second * bc[j].first;

                cnt += bc[j].second;

                j++;

            } else {

                ans += bc[j].first * (n - cnt);

                j++;

                cnt = n;

            }

        }

        // cout << i << " " << j << " " << cnt << "\n";

    }

    cout << ans << "\n";

}
