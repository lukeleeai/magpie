#include "stdc++.h"

using namespace std;

#define rep(i,n) for (int (i)=(0);(i)<(int)(n);++(i))

using ll = long long;

using P = pair<int, int>;

using namespace std;



int dist[101010];

vector<int> G[101010];



int solve(int v) {

    int u = G[v][0];

    if (G[u][0] == v) {

        // 戻ってきたら

        dist[u] = dist[v] = 0;

        return 0;

    }

    dist[v] = solve(u) + 1;

    return dist[v];

}



int main() {

    string s;

    cin >> s;



    rep(i, s.size()) {

        if (s[i] == 'L') G[i].push_back(i-1);

        else G[i].push_back(i+1);

    }



    rep(i, s.size()) dist[i] = -1;



    rep(i, s.size()) {

        if (dist[i] == -1) {

            if (s[i] == 'L' and i+1<s.size() and s[i+1] == 'L') continue;

            solve(i);

        }

    }



    vector<int> ans(s.size(), 0);



    rep(i, s.size()) {

        if (s[i] == 'R') {

            if (dist[i]%2 == 0) ans[i + dist[i]]++;

            else ans[i + dist[i] + 1]++;

        }

        else {

            if (dist[i]%2 == 0) ans[i - dist[i]]++;

            else ans[i - dist[i] - 1]++;

        }

    }



    rep(i, s.size()) {

        if (i) cout << " ";

        cout << ans[i];

    }

    cout << endl;





}
