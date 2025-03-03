#include "stdc++.h"

using namespace std;

#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))

using ll = long long;

using P = pair<int, int>;

using namespace std;



int main() {

    string s;

    vector<pair<int, int>> d;

    cin >> s;

    char ch = s[0];

    int cnt = 1;

    for (int i=1; i<s.size(); ++i) {

        if (ch == s[i]) {

            cnt++;

        }

        else {

            d.emplace_back(cnt, ch);

            cnt = 1;

            ch = s[i];

        }

    }

    d.emplace_back(cnt, ch);



    vector<int> ans(s.size(), 0);

    int cur = 0;

    rep(i, d.size()) {

        int cnt = d[i].first;

        char ch = d[i].second;

        rep(x, cnt) {

            if (ch == 'R') {

                if (x%2 == 0) ans[cur + cnt - 1]++;

                else ans[cur + cnt]++;

            }

            else {

                if (x%2 == 0) ans[cur]++;

                else ans[cur-1]++;

            }

        }

        cur += cnt;

    }



    rep(i, s.size()) cout << ans[i] << " ";

    cout << endl;

}
