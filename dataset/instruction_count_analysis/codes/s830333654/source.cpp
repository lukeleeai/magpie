#include <iostream>

#include <algorithm>

#include <string>

#include <vector>

#include <functional>

#include <queue>

#include <stack>

#include <set>

#include <map>

#include <numeric>

#include <cstdio>

#include <cstring>

#include <cmath>

#include <cctype>

#include <cassert>

#include <sstream>

 

#define rep(i, a) REP(i, 0, a)

#define REP(i, a, b) for(int i = a; i < b; ++i)

#define rrep(i, a) RREP(i, a, 0)

#define RREP(i, a, b) for(int i = a; i >= b; --i)

#define repll(i, a) REPLL(i, 0, a)

#define REPLL(i, a, b) for(ll i = a; i < b; ++i)

#define rrepll(i, a) RREPLL(i, a, 0)

#define RREPLL(i, a, b) for(ll i = a; i >= b; --i)

 

typedef long long ll;

typedef unsigned long long ull;

typedef std::pair<int, int> P;

typedef std::pair<int, P> PP;

const double PI = 3.14159265358979323846;

const double eps = 1e-9;

const int infi = (int)1e+9 + 7;

const ll infll = (ll)1e+17 + 7;

 

 

#include <time.h>

 

const int maxN = 100001;

 

int n, d;

std::vector<P>g[maxN];

std::vector<int>alive;

 

 

bool used[maxN];

P dfs(int v) {

    used[v] = true;

 

    P ret = P(0, v);

    for (int i = 0; i < g[v].size(); i++) {

        int u = g[v][i].first;

        int w = g[v][i].second;

        if (used[u]) continue;

        P tmp = dfs(u);

        ret = std::max(ret, P(w + tmp.first, tmp.second));

    }

    return ret;

}

 

int main() {

    std::cin >> n;

 

    for (int i = 0; i < n - 1; ++i) {

        int a, b, c;

        std::cin >> a >> b >> c;

        g[a].push_back(P(b, c));

        g[b].push_back(P(a, c));

    }

 

    int v = dfs(0).second;

    for (int i = 0;i < n; ++i)used[i] = false;

    std::cout << dfs(v).first << std::endl;

    return 0;

 

}