#include"stdc++.h"

using namespace std;

#define all(v) ((v).begin()),((v).end())

#define ll long long

#define fastIO cout << fixed << setprecision(12), ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr)

double const EPS = 1e-12, PI = acos(-1);

const int N = 2e5 + 9, M = 3e3 + 9, OO = 1e9 + 7, MOD = 1e9 + 7;

const ll inf = 1e18;



ll mem[109][109][109], arr[N];

int n, m;



ll solve(int l, int r, int steps) {

  if(steps < 0)

    return -inf;

  if(steps == 0 || l > r)

    return 0;

  ll& ret = mem[l][r][steps];

  if(~ret)

    return ret;

  ret = -inf;

  ll c1 = solve(l + 1, r, steps - 1) + arr[l];

  ll c2 = solve(l, r - 1, steps - 1) + arr[r];

  ll c3 = solve(l + 1, r, steps - 2);

  ll c4 = solve(l, r - 1, steps - 2);

  ret = max(max(c1, c2), max(c3, c4));

  return ret;

}



int main() {

  fastIO;

#ifdef LOCAL

  freopen("input.in", "rt", stdin);

#endif

  cin >> n >> m;

  for (int i = 0; i < n; ++i) {

    cin >> arr[i];

  }

  memset(mem, -1, sizeof mem);

  ll best = -inf;

  for (int i = 0; i <= m; ++i) {

    best = max(best, solve(0, n - 1, i));

  }

  cout << best;

  return 0;

}
