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

  vector<ll> dp(MAXS, 0);

  for (int s = get<1>(blocks[0]); s < MAXS; s++) {

    dp[s] = get<2>(blocks[0]);

  }

  for (int i = 1; i < n; i++) {

    auto& block = blocks[i];

    int slimit = get<0>(block);

    int w = get<1>(block), v = get<2>(block);

    for (int s = MAXS - 1; s >= w; s--) {

      dp[s] = max(dp[s], v + dp[min(s - w, slimit)]);

    }

  }



  printf("%lld\n", dp[MAXS - 1]);

}
