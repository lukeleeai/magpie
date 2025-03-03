// 個数制限なしナップサックDP

#include "stdc++.h"

using namespace std;

template <class T> bool chmin(T &a, T b) { if (a > b) {a = b; return true; } return false; }



const int MAX_N = 15;

const int MAX_W = 110000;

int dp[MAX_N][MAX_W];



int main() {

    int N; cin >> N;

    vector<int> weight;

    for (int i=1;i<=N;i*=6) weight.push_back(i);

    for (int i=9;i<=N;i*=9) weight.push_back(i);

    int n = (int)weight.size();



    for (int i=0;i < MAX_N; ++i) for (int w=0;w<MAX_W;++w) dp[i][w] = 1<<29;

    for (int i=0;i<=n;++i) dp[i][0] = 0;



    for (int i=0;i<n;++i){

        for (int w=0;w<=N;++w){

            if (w>=weight[i]) chmin(dp[i+1][w], dp[i+1][w-weight[i]]+1);

            chmin(dp[i+1][w], dp[i][w]);

        }

    }



    cout << dp[n][N] << endl;

}