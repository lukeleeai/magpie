#include "stdc++.h"

using namespace std;

#define rep(i,n) for (int (i)=(0);(i)<(long long)(n);++(i))

using ll = long long;

using P = pair<int, int>;

using namespace std;



int H, W;

vector<P> G[401][401];

string s[401];



int dx[] = {1, 0, -1, 0};

int dy[] = {0, 1, 0, -1};



vector<P> onaji;

map<int, bool> mp;











ll dfs(pair<int, int> p, bool next, bitset<401*401>& ok) {

    ok[p.first*W+p.second] = 1;

    ll ret = 0;

    for (auto v : G[p.first][p.second]) {

        // 白の時

        if (!next and !ok[v.first*W+v.second]) {

            ok[v.first*W+v.second] = 1;

            ret += dfs(v, !next, ok) + 1;

        }

        else if (!ok[v.first*W+v.second]){

            ok[v.first*W+v.second] = 1;

            ret += dfs(v, !next, ok);



            mp[v.first*W+v.second] = true;

            onaji.push_back(v);

        }

    }

    return ret;

}



int main() {

    cin >> H >> W;

    rep(i, H) cin >> s[i];



    vector<P> pos;

    rep(i, H) rep(j, W) {

        if (s[i][j] == '#') {

            pos.emplace_back(i, j);

            rep(d, 4) {

                int nr = i + dy[d];

                int nc = j + dx[d];

                if (0 <= nr and nr < H and 0 <= nc and nc < W and s[nr][nc] == '.') {

                    G[i][j].emplace_back(nr, nc);

                    G[nr][nc].emplace_back(i, j);

                }

            }

        }

    }



    ll ans = 0;

    bitset<401*401> ok;

    int onaji_idx = 0;

    map<int, bool> batu;

    for (auto p : pos) {

        if (mp[p.first*W+p.second]) continue;

        int tmp = dfs(p, false, ok);

        if (onaji_idx < onaji.size()) {

            ans += (onaji.size() - onaji_idx) * tmp;

            onaji_idx = onaji.size();

        }

        ans += tmp;

        ok.reset();

    }



    cout << ans << endl;

}
