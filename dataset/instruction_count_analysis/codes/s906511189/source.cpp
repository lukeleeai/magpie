#include <iostream>

#include <vector>

 

using namespace std;

typedef long long ll;

 

// ll naive(ll N, ll K) {

//   int cnt = 0;

//   for (int a = 1; a <= N; a++) {

//     for (int b = 1; b <= N; b++) {

//       for (int c = 1; c <= N; c++) {

//         if ((a + b) % K == 0 && (b + c) % K == 0 && (a + c) % K == 0) {

//           cnt++;

//         }

//       }

//     }

//   }

//   return cnt;

// }



ll solve(ll N, ll K) {

  ll ans = 0;

  vector<ll> cnt(200001);

  for(ll i = 1; i <= N; i++) {

    cnt[i % K]++;

  }

  for(ll b = 1; b <= N; b++) {

    ll m = (K - b) % K;

    if (m < 0) {

      m += K * (-m / K) + K;

      m %= K;

    }

    if ((2 * m) % K == 0) {

      ans += cnt[m] * cnt[m];

    }

  }

  return ans;

}



int main() {

  ll N, K;

  cin >> N >> K;

  cout << solve(N, K) << endl;

  return 0;

}