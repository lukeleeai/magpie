#include <iostream>

#include <set>

#include <map>

#include <vector>

#include <algorithm>

#include <iomanip>

#include <climits>

#include <numeric>

#include <cmath>

#include <queue>

#include <sstream>



using namespace std;

typedef long long ll;



int main() {

  ll N, C;

  cin >> N >> C;

  vector<ll> x(N + 2), v(N + 2);

  for (ll i = 1; i <= N; i++) {

    cin >> x[i] >> v[i];

  }

  x[0] = 0;

  x[N + 1] = C;

  

  vector<vector<ll>> dp(2, vector<ll>(100010, 0));

  ll cal = 0;

  for (ll i = 1; i <= N; i++) {

    cal -= x[i] - x[i - 1];

    cal += v[i];

    dp[0][i] = max(dp[0][i - 1], cal);

  }

  cal = 0;

  for (ll i = N; i >= 1; i--) {

    cal -= x[i + 1] - x[i];

    cal += v[i];

    dp[1][i] = max(dp[1][i + 1], cal);

  }

  

  ll maxcal = 0;

  for (int i = 0; i <= N; i++) {

    cal = dp[0][i] + dp[1][i + 1] - x[i];

    maxcal = max(maxcal, cal);

    

    cal = dp[0][i] + dp[1][i + 1] - C + x[i + 1];

    maxcal = max(maxcal, cal);

  }

  cout << maxcal << endl;

  return 0;

}
