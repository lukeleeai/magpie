#include "stdc++.h"



#define rep(i, n) for (int i = 0; i < int(n); i++)

#define reps(i, n) for (int i = 1; i <= int(n); i++)

#define repc(i, n) for (int i = 0; i <= int(n); i++)



using namespace std;



vector<int> primes = {

  2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97

};

int L = 25;



int dp[26][76];



int main() {

  vector<int> cnt(L);

  int N;

  cin >> N;

  reps(i, N) {

    int x = i;

    rep(j, L) {

      int p = primes[j];

      while (x % p == 0) cnt[j]++, x /= p;

    }

  }

  dp[0][1] = 1;

  rep(i, L) repc(j, 75) repc(k, cnt[i]) {

    if (j * (k + 1) > 75) continue;

    dp[i + 1][j * (k + 1)] += dp[i][j];

  }

  cout << dp[L][75] << endl;

  return 0;

}
