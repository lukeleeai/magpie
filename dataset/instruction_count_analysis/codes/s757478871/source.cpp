#include"stdc++.h"

 

using namespace std;

 

const int INF = 1 << 30;

 

int main()

{

  int N, W;

  int dp[10001] = {}, deq[10001], deqv[10001];

 

  cin >> N >> W;

  for(int i = 0; i < N; i++) {

    int v, w, m;

    cin >> v >> w >> m;

    for(int k = 0; k < w; k++) {

      int s = 0, t = 0;

      for(int l = 0; l * w + k <= W; l++) {

        int val = dp[l * w + k] - l * v;

        while(s < t && deqv[t - 1] <= val) --t;

        deq[t] = l;

        deqv[t++] = val;

        dp[l * w + k] = deqv[s] + l * v;

        if(deq[s] == l - m) ++s;

      }

    }

  }

 

  cout << dp[W] << endl;

}
