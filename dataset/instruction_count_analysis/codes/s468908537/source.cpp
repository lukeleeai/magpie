#include "stdc++.h"

using namespace std;

using ll = long long;

using pii = pair<int, int>;



const ll MOD = 1e9 + 7;

int N;

int T[100010], A[100010];

int L[100010], R[100010];



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



  int tmp = -1;

  for (int i = 0; i < N; i++) {

    if (T[i] != tmp) {

      tmp = T[i];

      L[i] = T[i];

    }

  }

  tmp = -1;

  for (int i = N - 1; i >= 0; i--) {

    if (A[i] != tmp) {

      tmp = A[i];

      R[i] = A[i];

    }

  }



  ll ans = 1;  

  for (int i = 0; i < N; i++) {

    if (L[i] != 0 && R[i] != 0) {

      if (L[i] != R[i]) ans = 0;

    } else if (L[i] == 0 && R[i] != 0) {

      if (T[i] < A[i]) ans = 0;

    } else if (L[i] != 0 && R[i] == 0) {

      if (T[i] > A[i]) ans = 0;

    } else {

      ans *= min(T[i], A[i]);

      ans %= MOD;

    }

  }

  cout << ans << endl;



  return 0;

}