#include <iostream>

#include <cstdio>

#include <cstring>

#include <cmath>

#include <algorithm>

#include <vector>

#include <map>

#include <string>

#include <queue>

using namespace std;

#define SZ(v) ((int)(v).size())

const int maxint = -1u>>1;

const int maxn = 100 + 30;

typedef long long ll;



int n, m;

ll adj[maxn][maxn];

int f[maxn], bestf[maxn];

int find(int v) {

    if (v != bestf[v]) {

        return bestf[v] = find(bestf[v]);

    }

    return v;

}

int bestff;

int v[maxn];

ll w[maxn];

bool a[maxn];

vector<pair<int, int> > res;

ll mincut() {

    ll ans = (-1ull) >> 1;

    //for (int i = 0; i < n; ++i) {

        //for (int j = 0; j < n; ++j) {

            //adj[i][j] = -adj[i][j];

        //}

    //}

    for (int i = 0; i < n; ++i) {

        f[i] = v[i] = i;

    }

    for (int t = n; t > 1; --t) {

        a[0] = true;

        for (int i = 1; i < t; ++i) {

            a[i] =false;

            w[i] = adj[v[0]][v[i]];

        }

        int prev = v[0];

        for (int i = 1; i < t; ++i) {

            int zj = -1;

            for (int j = 1; j < t; ++j) {

                if (a[j] == false && (zj == -1 || w[j] > w[zj])) {

                    zj = j;

                }

            }

            a[zj] = true;

            if (i == t - 1) {

                if (w[zj] < ans) {

                    ans = w[zj];

                    copy(f, f + n, bestf);

                    bestff = v[zj];

                }

                for (int k = 0; k < t; ++k) {

                    adj[v[k]][prev] = adj[prev][v[k]] += adj[v[zj]][v[k]];

                }

                f[v[zj]] = prev;

                v[zj] = v[t - 1];

                break;

            }

            prev = v[zj];

            for (int j = 1; j < t; ++j) {

                if (a[j] == false) {

                    w[j] += adj[v[zj]][v[j]];

                }

            }

        }

    }

    //bool flag[maxn] = {};

    //for (int i = 0; i < n; ++i) {

        //if (find(i) == bestff) {

            //flag[i] = true;

        //}

    //}

    //res.clear();

    //for (int i = 0; i < n; ++i) {

        //for (int j = i + 1; j < n; ++j) {

            //if (flag[i] == flag[j] && save[i][j]) {

                //res.push_back(make_pair(i, j));

            //}

        //}

    //}

    return ans;

}



void gao() {

    ll ans = 0;

    memset(adj, 0, sizeof(adj));

    for (int i = 0, a, b; i < m; ++i) {

        ll c;

        scanf ("%d%d%lld", &a, &b, &c);

        if (c < 0) {

            ans += c;

        } else {

            adj[a][b] = adj[b][a] = adj[a][b] + c;

        }

    }

    printf("%lld\n", ans + mincut());

}



int main() {

    while (scanf("%d%d", &n, &m) == 2 && (n || m)) {

        gao();

    }

    return 0;

}