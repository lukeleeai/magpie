#include<iostream>

#include<vector>

#include<algorithm>

#include<string>

using namespace std;



int main() {

  int N, M, cost[300], exp[300][3], dp[301];

  while(cin >> N >> M){

    for(int i = 0 ; i < N ; i++ ){

      string s;

      getline(cin, s), getline(cin, s);

      cin >> cost[i] >> exp[i][0] >> exp[i][1] >> exp[i][2];

    }

    int ret = 0;

    for(int i = 0 ; i < 3 ; i++ ){

      fill_n( dp, 301, 0);

      for(int j = 0 ; j < N ; j++ ){

        for(int k = 0 ; k <= M ; k++ ){

          if(k - cost[j] >= 0 ){

            dp[k] = max( dp[k], dp[k-cost[j]] + exp[j][i]);

            ret = max( ret, dp[k]);

          }

        }

      }

    }

    cout << ret << endl;

  }

}