#include <iostream>

#include <cstdio>

#include <cmath>

#include <vector>

#include <list>

#include <set>

#include <map>

#include <stack>

#include <queue>

#include <string>

#include <utility>

#include <algorithm>

#include <functional>

#include <deque>

#define INF 1e9

#define MOD 1000000007

#define MAX_N 100001

#define mod(x) ((x % MOD) + MOD) % MOD



using namespace std;



typedef long long ll;

typedef pair<int,int> P;



struct edge { int from, to; };

vector<edge> G[MAX_N];

int value[MAX_N];

bool used[MAX_N];

vector<int> idx_list;

vector<int> value_list;



void dfs(int i) {

    used[i] = true;

    idx_list.push_back(i);

    value_list.push_back(value[i]);

    

    for (int j = 0; j < G[i].size(); j++) {

        edge e = G[i][j];

        if (!used[e.to]) {

            dfs(e.to);

        }

    }

}









int main() {

    int N, M;

    cin >> N >> M;

    

    for (int i = 1; i <= N; ++i) {

        cin >> value[i];

    }

    for (int i = 1; i <= M; ++i) {

        int x, y;

        cin >> x >> y;

        G[x].push_back(edge{x, y});

        G[y].push_back(edge{y, x});

    }

    

    int ans = 0;

    

    fill(used, used + MAX_N, false);

    for (int i = 1; i <= N; ++i) {

        idx_list.clear();

        value_list.clear();

        if (!used[i]) {

            dfs(i);

            sort(idx_list.begin(), idx_list.end());

            sort(value_list.begin(), value_list.end());

        

            vector<int> list_inter;

            set_intersection(idx_list.begin(), idx_list.end(), value_list.begin(), value_list.end(), back_inserter(list_inter));

            ans += (int)list_inter.size();

        }

    }

    

    cout << ans << endl;

    

    return 0;

}
