#include "stdc++.h"

using namespace std;

#define Rep(i,N) for(int i = 0; i < N; i++)



inline void chmax(int &a, int b) { a = max(a, b); }



int main()

{

  int N, M;

  int A[5005], B[5005];

  int maxv = 0;

  

  cin >> N >> M;

  Rep(i,N) cin >> A[i];

  Rep(i,M) cin >> B[i];



  vector<vector<int> >dp(2,vector<int>(5005,0));

  Rep(i,M) {

    Rep(j,N) {

      if(j) dp[1][j + 1] = dp[1][j];

      if(A[j] == B[i])chmax(dp[1][j + 1], dp[0][j] + 1);

      chmax(maxv,dp[1][j + 1]);

    }

    dp[0] = dp[1];

    fill(dp[1].begin(), dp[1].end(),0);

  }



  cout << maxv << endl;

  return 0;

}