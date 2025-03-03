#include <iostream>

#include <vector>

using namespace std;

typedef long long ll;



int N,C[200010];

int col_id[200010] = {};

vector<vector<int>> col(200010);

vector<ll> col_sum(200010,0);

ll dp[200010] = {},inf = 1e9+7;

int main(){

    cin >> N;

    int c;

    for(int i=1;i<=N;i++){

        cin >> C[i];

        //col[c].push_back(i);

    }

    dp[0] = 1;

    for(int i=1;i<=N;i++){

        (dp[i] += dp[i-1]+(C[i-1]!=C[i]? col_sum[C[i]]:0))%=inf;

        (col_sum[C[i]] = dp[i])%=inf;

    }

    cout << dp[N] << endl;

}