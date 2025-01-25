#include "stdc++.h"

using namespace std;



int h, n;

vector<int> b;



int dp[101010][10];



int dfs(int i = 1, int bit = 0) {

  if (i == h) {

    return 0;

  }

  bit |= b[i];



  int &ret = dp[i][bit];

  if (~ret)

    return ret;



  ret = 0;

  if (bit == 0)

    ret = max(ret, dfs(i + 1, 0b111) + 2);

  if ((bit & (0b100)) == 0)

    ret = max(ret, dfs(i + 1, 0b110) + 1);

  if ((bit & (0b010)) == 0)

    ret = max(ret, dfs(i + 1, 0b111) + 1);

  if ((bit & (0b001)) == 0)

    ret = max(ret, dfs(i + 1, 0b011) + 1);

  ret = max(ret, dfs(i + 1, 0));



  return ret;

}



int main() {

  memset(dp, -1, sizeof(dp));

  cin >> h >> n;



  int ei[4] = {0b100, 0b110, 0b011, 0b001};

  b.assign(h + 1, 0);

  for (int i = 0; i < n; ++i) {

    int x, y;

    cin >> x >> y;

    b[y + 1] |= ei[x];

    b[y] |= ei[x];

  }



  cout << dfs() << endl;

}
