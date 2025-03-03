#include "stdc++.h"



using namespace std;



const int INF = 1 << 30;



int L, X[200000];

int dp[200002][5];



int rec(int idx, int state) {

  if(idx == L) return 0;

  if(~dp[idx][state]) return dp[idx][state];

  int ret = INF;

  if(state == 0 || state == 4) {

    ret = min(ret, rec(idx + 1, state) + X[idx]);

    if(state == 0) ret = min(ret, rec(idx, state + 1));

  } else if(state == 1 || state == 3) {

    ret = min(ret, rec(idx + 1, state) + (X[idx] == 0 ? 2 : X[idx] % 2));

    ret = min(ret, rec(idx, state + 1));

  } else {

    ret = min(ret, rec(idx + 1, state) + 1 - X[idx] % 2);

    ret = min(ret, rec(idx, state + 1));

  }

  return dp[idx][state] = ret;

}



int main() {

  cin >> L;

  for(int i = 0; i < L; i++) cin >> X[i];

  memset(dp, -1, sizeof(dp));

  cout << rec(0, 0) << endl;

}
