#include <algorithm>

#include <iostream>

#include <vector>



using namespace std;



typedef long long ll;

typedef pair<ll, ll> P;



#define MOD 1000000007

#define REP(i, N) for (int i = 0; i < N; ++i)

#define REP1(i, N) for (int i = 1; i <= N; ++i)

#define RREP(i, N) for (int i = N - 1; i >= 0; --i)

#define ALL(a) a.begin(), a.end()



int main() {

  int n;

  cin >> n;

  vector<int> pos[200001];

  bool ng = true;

  for (int i = 0; i < n; ++i) {

    int a;

    cin >> a;

    if (a == 1) ng = false;

    pos[a].push_back(i);

  }

  if (ng) {

    cout << -1 << endl;

    return 0;

  }

  int ans = 0, before = -1;

  for (int i = 1; i <= n; ++i) {

    auto it = upper_bound(pos[i].begin(), pos[i].end(), before);

    if (it == pos[i].end()) break;

    ans++;

    before = *it;

  }

  cout << n - ans << endl;

  return 0;

}