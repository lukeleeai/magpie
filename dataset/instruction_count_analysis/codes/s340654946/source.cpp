#include <iostream>

#include <sstream>

#include <string>

#include <algorithm>

#include <vector>

#include <stack>

#include <queue>

#include <set>

#include <map>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <cmath>

#include <cassert>



using namespace std;



#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)

#define REP(i,n) FOR(i,0,n)

#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)



template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }

inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }



typedef long long ll;

const int INF = 100000000;

const double EPS = 1e-8;

const int MOD = 1000000007;

int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};

int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};



const int MAX = 300;



int main(){

  int S, D, M;

  while(cin >> S >> D >> M){

    int dp[100][MAX + 1] = {};

    REP(i, S){

      int K;

      cin >> K;

      while(K--){

        int w, p;

        cin >> w >> p;

        for(int y = MAX; y >= 0; y--){

          if(y - p >= 0) dp[i][y] = max(dp[i][y], dp[i][y - p] + w);

        }

      }

    }

    int ans[MAX + 1] = {};

    REP(i, D){

      int f; cin >> f;

      for(int j = MAX; j >= 0; j--){

        for(int k = 0; j - k >= 0; k++){

          ans[j] = max(ans[j], ans[j - k] + dp[f][k]);

        }

      }

    }

    while(M > 0 && ans[M] == ans[M - 1]) M--;

    printf("%d %d\n", ans[M], M);

  }

  return 0;

}