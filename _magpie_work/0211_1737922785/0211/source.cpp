#include <iostream>
#include <deque>
#include <vector>
#include <array>
#include <climits>
using namespace std;

const int MAX_SIZE = 110000;
int n, m, q, dist[MAX_SIZE], mark[MAX_SIZE], u[MAX_SIZE], v[MAX_SIZE];
vector<pair<int, int>> x[MAX_SIZE], y[MAX_SIZE], z[MAX_SIZE]; 
bool used[MAX_SIZE];

bool isgood(int f) {
    for (const auto& p : z[f]) {
        if (mark[p.first] == 0 && !used[p.second]) return true;
    }
    return false;
}

int main() {
    scanf("%d%d%d", &n, &m, &q); 
    deque<int> Q;

    for (int i = 0; i < m; i++) {
        int a, b; 
        scanf("%d%d", &a, &b); 
        u[i + 1] = a; v[i + 1] = b;
        x[a].emplace_back(b, i + 1); 
        x[b].emplace_back(a, i + 1);
    }

    Q.push_back(1); 
    fill(dist, dist + n + 1, INT_MAX); 
    dist[1] = 0;

    while (!Q.empty()) {
        int a1 = Q.front(); Q.pop_front();
        for (const auto& p : x[a1]) {
            if (dist[p.first] > dist[a1] + 1) {
                dist[p.first] = dist[a1] + 1; 
                Q.push_back(p.first);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (const auto& p : x[i]) {
            if (dist[i] < dist[p.first]) {
                y[i].push_back(p);
            }
            if (dist[i] > dist[p.first]) {
                z[i].push_back(p);
            }
        }
    }

    int cnt = 0;
    for (int i = 0; i < q; i++) {
        int a; 
        scanf("%d", &a); 
        used[a] = true;

        int E1 = u[a], E2 = v[a];
        if (dist[E1] == dist[E2]) { cnt += 0; }
        else {
            int a1 = (dist[E1] < dist[E2]) ? E2 : E1;
            if (!isgood(a1) && mark[a1] == 0) {
                deque<int> Q; 
                Q.push_back(a1); 
                cnt++; 
                mark[a1] = 1;

                while (!Q.empty()) {
                    int a2 = Q.front(); Q.pop_front();
                    for (const auto& p : y[a2]) {
                        if (mark[p.first] == 0 && !isgood(p.first)) {
                            mark[p.first] = 1; 
                            Q.push_back(p.first); 
                            cnt++;
                        }
                    }
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
