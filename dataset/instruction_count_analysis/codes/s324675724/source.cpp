#include "stdc++.h"

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

int n;

int dp[(1 << 21)];

int a[21][21];

int main()

{

//  freopen("in.txt", "r", stdin);

//  freopen("out.txt", "w", stdout);

  cin >> n;

  for(int i = 0;i < n;i++)

    for(int j = 0;j < n;j++)

      cin >> a[i][j];

  dp[0] = 1;

  for(int i = 0;i < (1 << n);i++){

    for(int j = 0;j < n;j++){

      int in = __builtin_popcount(i);

      if(((1 << j) & i) || !a[in][j])continue;



      dp[i | (1 << j)] = (1LL * dp[i | (1 << j)] + dp[i]) % MOD;

    }

  }

  cout << dp[(1 << n) - 1];

  return 0;

}
