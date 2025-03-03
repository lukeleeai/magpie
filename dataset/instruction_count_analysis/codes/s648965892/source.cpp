#include "stdc++.h"

using namespace std;

using ll = long long;

using ull = unsigned long long;

using ld = long double;

using pii = pair<int, int>;

using pll = pair<ll, ll>;

using pli = pair<ll, int>;

using pil = pair<int, ll>;

using uint = unsigned int;

template <typename T>

using Graph = vector<vector<T>>;

const int MOD = 1e9 + 7;

const ld PI = acosl(-1);



int main() {

    cin.tie(0);

    ios::sync_with_stdio(false);



    int N;

    cin >> N;



    vector<int> cnt(13);

    cnt[0] = 1;

    bool iszero = false;

    for (int i = 0; i < N; ++i) {

        int a;

        cin >> a;

        cnt[a]++;

        if (cnt[a] >= 3)

            iszero = true;

    }



    if (iszero) {

        cout << 0 << endl;

        return 0;

    }



    int ans = 0;

    for (int i = 0; i < (1 << 13); ++i) {

        vector<int> v;

        for (int j = 0; j < 13; ++j) {

            if (!cnt[j])

                continue;

            if (cnt[j] == 2) {

                v.push_back(j);

                v.push_back(24 - j);

                continue;

            }

            if (i & (1 << j))

                v.push_back(24 - j);

            else

                v.push_back(j);

        }



        int siz = v.size();

        int res = 12;

        for (int j = 0; j < siz; ++j) {

            for (int k = j + 1; k < siz; ++k) {

                int dif = abs(v[j] - v[k]);

                res = min(res, min(dif, 24 - dif));

            }

        }

        ans = max(ans, res);

    }



    cout << ans << endl;

    return 0;

}
