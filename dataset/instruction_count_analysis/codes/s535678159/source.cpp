#include "stdc++.h"

using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

int n;

int dp[(1 << 21)];

int a[21][21];

int solve(int msk){

  if(msk == (1 << n) - 1)

    return 1;

  int in = __builtin_popcount(msk);

//  cout << msk << ' ' << in << endl;

  int& res = dp[msk];

  if(res != -1)

    return res;

  res = 0;

  for(int i = 0;i < n;i++){

    if(!((1 << i) & msk) && a[in][i]){

      res = (1ll * res + solve(msk | (1 << i))) % MOD;

    }

  }

  return res;

}

int main()

{

//  freopen("in.txt", "r", stdin);

//  freopen("out.txt", "w", stdout);

  memset(dp, -1, sizeof(dp));

  cin >> n;

  for(int i = 0;i < n;i++)

    for(int j = 0;j < n;j++)

      cin >> a[i][j];

  cout << solve(0);

  return 0;

}
