#include <iostream>

#include <cstdio>

#include <cstdlib>

#include <algorithm>

#include <vector>

#include <set>

#include <map>

#include <cmath>

#include <ctime>

#include <string>

#include <cstring>

#include <complex>

using namespace std;



typedef long long ll;

typedef pair<int, int> pii;

#define mp make_pair



const int N = 100100;

const int K = 20;



vector<int> g[N];

vector<pii> dp[N];

vector<pii> a[K];

int n;



void dfs(int v, int par)

{

    int d = 0;

    for (int u : g[v])

    {

        if (u == par) continue;

        dfs(u, v);

        d = max(d, dp[u][0].second);

    }

    for (int i = 0; i < K; i++)

        a[i].clear();

    for (int u : g[v])

        if (u != par)

            a[dp[u][0].second].push_back(mp(u, 0));

//    printf("solving %d\n", v);

    int goodLen = 0;

    int goodD = d + 1;

    while(true)

    {

//        printf("d = %d\n", d);

        if (d < 0)

        {

            break;

        }

        if (a[d].empty())

        {

            while(d > 0 && a[d - 1].empty()) d--;

            goodLen = dp[v].size();

            goodD = d;

            d--;

            continue;

        }

        if ((int)a[d].size() >= 2)

        {

            break;

        }

        int u = a[d][0].first;

        int p = a[d][0].second;

//        printf("%d %d\n", u, p);

        dp[v].push_back(dp[u][p]);

        p++;

        if (p < (int)dp[u].size())

            a[dp[u][p].second].push_back(mp(u, p));

        d--;

    }

    while((int)dp[v].size() > goodLen) dp[v].pop_back();

    dp[v].push_back(mp(v, goodD));

    return;

}



int main()

{

//    freopen("input.txt", "r", stdin);

//    freopen("output.txt", "w", stdout);



    scanf("%d", &n);

    for (int i = 1; i < n; i++)

    {

        int v, u;

        scanf("%d%d", &v, &u);

        v--;u--;

        g[v].push_back(u);

        g[u].push_back(v);

    }

    dfs(0, -1);

    printf("%d\n", dp[0][0].second);



    return 0;

}