#include "stdc++.h"



using namespace std;



using int64 = long long;

const int64 INF = 1 << 30;





int L, X[200000];

int64 dp[200002][5];



int64 rec(int idx, int flag) {

  if(idx == L) return 0;

  if(~dp[idx][flag]) return dp[idx][flag];

  int64 ret = INF;

  if(flag == 0) {

    ret = min(ret, rec(idx + 1, 0) + X[idx]);

    ret = min(ret, rec(idx, 1));

  } else if(flag == 1) { // 偶数

    ret = min(ret, rec(idx + 1, 1) + (X[idx] == 0 ? 2 : X[idx] % 2));

    ret = min(ret, rec(idx, 2));

  } else if(flag == 2) { // 奇数

    ret = min(ret, rec(idx + 1, 2) + 1 - X[idx] % 2);

    ret = min(ret, rec(idx, 3));

  } else if(flag == 3) {

    ret = min(ret, rec(idx + 1, 3) + (X[idx] == 0 ? 2 : X[idx] % 2));

    ret = min(ret, rec(idx, 4));

  } else {

    ret = min(ret, rec(idx + 1, 4) + X[idx]);

  }

  return dp[idx][flag] = ret;

}



int main() {

  memset(dp, -1, sizeof(dp));

  cin >> L;

  for(int i = 0; i < L; i++) {

    cin >> X[i];

  }

  cout << rec(0, 0) << endl;

}






