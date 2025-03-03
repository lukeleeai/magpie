#include "stdc++.h"

using namespace std;



const int N = 2e5 + 7;



int n;

vector<int> pos[N];

int cnt[N], res[N];

set<int> have_a, have_b;

set<pair<int, int>> st;



int get(int i) {

    return (int)pos[i].size() + cnt[i];

}



void pairup(int i, int j) {

    res[pos[i].back()] = j;

    pos[i].pop_back();

    --cnt[j];

}



void add(int i) {

    if (get(i) > 0) st.insert({get(i), i});

    if (!pos[i].empty()) have_a.insert(i);

    if (cnt[i] > 0) have_b.insert(i);

}



void del(int i) {

    if (get(i) > 0) st.erase({get(i), i});

    if (!pos[i].empty()) have_a.erase(i);

    if (cnt[i] > 0) have_b.erase(i);

}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(0);

    cin >> n;

    for (int i = 0; i < n; ++i) {

        int a;

        cin >> a;

        pos[a].push_back(i);

    }

    for (int i = 0; i < n; ++i) {

        int b;

        cin >> b;

        ++cnt[b];

    }

    for (int i = 0; i < N; ++i) {

        if (get(i) > n) {

            cout << "No\n";

            return 0;

        }

        add(i);

    }

    int cur_n = n;

    while (!st.empty()) {

        int cur = st.rbegin()->second;

        del(cur);

        if (!st.empty() && st.rbegin()->first == cur_n) {

            int who = st.rbegin()->second;

            del(who);

            if (!pos[cur].empty() && cnt[who] > 0) pairup(cur, who); else pairup(who, cur);

            add(who);

        } else {

            if (!pos[cur].empty() && !have_b.empty()) {

                int who = *have_b.begin();

                del(who);

                pairup(cur, who);

                add(who);

            } else {

                int who = *have_a.begin();

                del(who);

                pairup(who, cur);

                add(who);

            }

        }

        add(cur);

        --cur_n;

    }

    cout << "Yes\n";

    for (int i = 0; i < n; ++i) cout << res[i] << " ";

    return 0;

}
