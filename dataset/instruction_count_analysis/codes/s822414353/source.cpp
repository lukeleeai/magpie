#include "stdc++.h"

using namespace std;



int main() {

    ios::sync_with_stdio(false);

    cin.tie(0);



    while (1) {

        int n, m, c, s, t;

        cin >> n >> m >> c >> s >> t;

        if (n == 0) break;

        vector<vector<vector<int>>> dist(c, vector<vector<int>>(n, vector<int>(n, 1e9)));

        for (int i = 0; i < m; i++) {

            int a, b, d, type;

            cin >> a >> b >> d >> type;

            a--, b--, type--;

            dist[type][a][b] = min(dist[type][a][b], d);

            dist[type][b][a] = min(dist[type][b][a], d);

        }

        for (int type = 0; type < c; type++) {

            for (int k = 0; k < n; k++) {

                for (int i = 0; i < n; i++) {

                    for (int j = 0; j < n; j++) {

                        dist[type][i][j] = min(dist[type][i][j], dist[type][i][k] + dist[type][k][j]);

                    }

                }

            }

        }

        vector<int> segs(c);

        for (int i = 0; i < c; i++) cin >> segs[i];

        vector<vector<int>> da(c), dd(c);

        for (int i = 0; i < c; i++) {

            int prev = 0;

            for (int j = 0; j < segs[i] - 1; j++) {

                int a;

                cin >> a;

                if (j > 0) {

                    da[i].push_back(a - prev);

                } else {

                    da[i].push_back(a);

                }

                prev = a;

            }

            da[i].push_back(1e9);

            for (int j = 0; j < segs[i]; j++) {

                int a;

                cin >> a;

                dd[i].push_back(a);

            }

        }

        function<int(int, int, int, int)> find_cost = [&](int type, int d, int acc, int idx) -> int {

            if (d <= da[type][idx]) return acc + dd[type][idx] * d;

            return find_cost(type, d - da[type][idx], acc + dd[type][idx] * da[type][idx], idx + 1);

        };



        vector<vector<int>> cost(n, vector<int>(n, 1e9));

        for (int type = 0; type < c; type++) {

            for (int i = 0; i < n; i++) {

                for (int j = 0; j < n; j++) {

                    if (dist[type][i][j] != 1e9) {

                        cost[i][j] = min(cost[i][j], find_cost(type, dist[type][i][j], 0, 0));

                    }

                }

            }

        }

        for (int k = 0; k < n; k++) {

            for (int i = 0; i < n; i++) {

                for (int j = 0; j < n; j++) {

                    cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);

                }

            }

        }

        s--, t--;

        if (cost[s][t] == 1e9) {

            cout << -1 << endl;

            continue;

        }

        cout << cost[s][t] << endl;

    }

}
