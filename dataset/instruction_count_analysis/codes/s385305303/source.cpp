#include "stdc++.h"

using namespace std;



typedef long long ll;

typedef pair<int, int> P;

typedef tuple<int, int, int> T;

const int INF = 1 << 27;

const ll LLINF = (ll)1 << 60;

const ll MOD = 1e9+7;



int dx[4] = {-1, 0, 1, 0};

int dy[4] = {0, -1, 0, 1};



int main() {

  int n;

  scanf("%d", &n);

  vector<T> blocks;

  for (int i = 0; i < n; i++) {

    int w, s, v;

    scanf("%d %d %d", &w, &s, &v);

    blocks.emplace_back(s, w, v);

  }



  sort(blocks.begin(), blocks.end(), [](T& t1, T& t2) {return get<0>(t1) + get<1>(t1) < get<0>(t2) + get<1>(t2);});



  const int MAXS = 2e4+10;

  vector<vector<ll>> dp(n, vector<ll>(MAXS, 0));

  for (int s = get<1>(blocks[0]); s < MAXS; s++) {

    dp[0][s] = get<2>(blocks[0]);

  }

  for (int i = 1; i < n; i++) {

    auto& block = blocks[i];

    int slimit = get<0>(block);

    int w = get<1>(block), v = get<2>(block);

    for (int s = 0; s < w; s++) {

      dp[i][s] = dp[i-1][s];

    }

    for (int s = w; s < MAXS; s++) {

      dp[i][s] = max(dp[i-1][s], v + dp[i-1][min(s - w, slimit)]);

    }

  }

  

  printf("%lld\n", dp[n-1][MAXS - 1]);

}
