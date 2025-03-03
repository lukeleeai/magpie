#include <iostream>

#include <vector>

#include <algorithm>



using namespace std;



typedef long long ll;

typedef pair<ll, ll> P;



#define MOD 1000000007

#define REP(i, N) for (int i = 0; i < N; ++i)

#define REP1(i, N) for (int i = 1; i <= N; ++i)

#define RREP(i, N) for (int i = N - 1; i >= 0; --i)

#define ALL(a) a.begin(), a.end()



int main()

{

  int N;

  cin >> N;

  vector<int> A(N);

  REP(i, N)

  cin >> A[i];

  ll dp[100010][2] = {};

  dp[2][0] = A[0] + A[1];

  dp[2][1] = -dp[2][0];

  REP(i, N)

  {

    if (i < 2)

      continue;

    dp[i + 1][0] = max(dp[i][0] + A[i], dp[i][1] + A[i]);

    dp[i + 1][1] = max(dp[i][0] - 2 * A[i - 1] - A[i], dp[i][1] + 2 * A[i - 1] - A[i]);

  }

  cout << max(dp[N][0], dp[N][1]) << endl;

  return 0;

}