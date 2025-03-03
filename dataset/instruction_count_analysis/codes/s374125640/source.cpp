#include "stdc++.h"

using namespace std;

using ll = long long;

using pii = pair<int, int>;



const ll MOD = (ll)1e9 + 7;

int N;

int T[100010], A[100010];



int main() {

  cin.tie(0);

  ios_base::sync_with_stdio(false);

  cout << fixed << setprecision(10);

  

  cin >> N;

  for (int i = 0; i < N; i++) {

    cin >> T[i];

  }  

  for (int i = 0; i < N; i++) {

    cin >> A[i];

  }



  int a[100010], b[100010];

  fill_n((int*)a, 100010, -1);

  fill_n((int*)b, 100010, -1);



  int tmp = -1;

  for (int i = 0; i < N; i++) {

    if (T[i] == tmp) continue;

    a[i] = tmp = T[i];

  }

  tmp = -1;

  for (int i = N - 1; i >= 0; i--) {

    if (A[i] == tmp) continue;

    b[i] = tmp = A[i];

  }



  for (int i = 0; i < N; i++) {

    if (a[i] < 0 && b[i] < 0) continue;

    if (a[i] < 0 && T[i] >= A[i]) continue;

    if (b[i] < 0 && T[i] <= A[i]) continue;

    if (a[i] == b[i]) continue;

    cout << 0 << endl;

    return 0;

  }

  ll ans = 1;

  for (int i = 0; i < N; i++) {

    if (a[i] >= 0 || b[i] >= 0) continue;

    ans = ans * min(T[i], A[i]) % MOD;

  }

  cout << ans << endl;



  return 0;

}