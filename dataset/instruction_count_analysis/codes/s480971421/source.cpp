#include <iostream>

#include <vector>

#include <numeric>

#include <algorithm>



using namespace std;



const int MOD = 1000000007;



int solve(const vector<int>& w, int W){

    if(w.back() > W || w.size() == 1) return 1;

    int sum = accumulate(w.begin(), w.end(), 0);

    if(sum <= W) return 1;

    vector<int> dp(W+1, 0);

    dp[0] = 1;

    int res = 0;

    for(int i=0;i<w.size();i++){

        for(int j=W-w[i];j>=0;j--){

            dp[j+w[i]] += dp[j];

            dp[j+w[i]] %= MOD;

        }

        sum -= w[i];

        for(int j=max(0, W-sum-w[i]+1);j<=W-sum-(i==w.size()-1?0:w[i+1]);j++){

            res = (res + dp[j]) % MOD;

        }

    }

    return res;

}



int main(){

    int N, W;

    while(cin >> N >> W){

        vector<int> w(N);

        for(auto& t : w) cin >> t;

        sort(w.rbegin(), w.rend());

        cout << solve(w, W) << endl;

    }

}
