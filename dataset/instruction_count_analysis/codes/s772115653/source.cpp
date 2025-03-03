#include "stdc++.h"

#define _GLIBCXX_DEBUG

#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;

using ll = long long;

const int INF = 1001001001;

const int mod = 1000000007;



int score = 0;

int N, K;

int R, S, P;

string T;



vector<vector<int>> dp(3,vector<int>(100001, 0));

vector<char> used(100001,'x');



void dps(int idx){

    // 文字列の最終まで来ていたらreturn

    if(idx == N){

        return;

    }

    // 前回までの試行の最大値を計算する

    int before_maxi = max(dp[0][idx - 1], max(dp[1][idx - 1], dp[2][idx - 1]));



    // 今回の各ハンドについて処理する

    if(T[idx] == 's'){

        if(used[idx - K] == 's'){

            dp[0][idx] = -1;

        }else{

            dp[0][idx] = before_maxi + R;

            used[idx] = 's';

        }

    }else if(T[idx] == 'p'){

        if(used[idx - K] == 'p'){

            dp[1][idx] = -1;

        }else{

            dp[1][idx] = before_maxi + S;

            used[idx] = 'p';

        }

    }else if(T[idx] == 'r'){

        if(used[idx - K] == 'r'){

            dp[2][idx] = -1;

        }else{

            dp[2][idx] = before_maxi + P;

            used[idx] = 'r';

        }

    }else{

        cout << "error" << endl;

    }

    for(int i = 0; i < 3; i++){

        if(dp[i][idx] == 0){

            dp[i][idx] = before_maxi;

        }

    }

    dps(idx + 1);

    return;

}



int main(){

    cin >> N >> K;

    cin >> R >> S >> P; //

    cin >> T;

    int before_maxi = 0;

    for(int i = 0; i < K; i++){

        if(T[i] == 's'){

            dp[0][i] += before_maxi + R;

            used[i] = 's';

        }else if(T[i] == 'p'){

            dp[1][i] += before_maxi + S;

            used[i] = 'p';

        }else if(T[i] == 'r'){

            dp[2][i] += before_maxi + P;

            used[i] = 'r';

        }else{

            cout << "error" << endl;

            return 0;

        }

        for(int j = 0; j < 3; j++){

            if(dp[j][i] == 0){

                dp[j][i] = before_maxi;

            }

        }

        before_maxi = max(dp[0][i], max(dp[1][i], dp[2][i]));

    }

    dps(K);

    // 結果を出力

    cout << max(dp[0][N - 1], max(dp[1][N - 1], dp[2][N - 1])) << endl;



    // debug

//    for(int i = 0; i < N; i++){

//        cout << dp[0][i] << " ";

//    }

//    cout << endl;

//    for(int i = 0; i < N; i++){

//        cout << dp[1][i] << " ";

//    }

//    cout << endl;

//    for(int i = 0; i < N; i++){

//        cout << dp[2][i] << " ";

//    }

//    cout << endl;



    return 0;

}
