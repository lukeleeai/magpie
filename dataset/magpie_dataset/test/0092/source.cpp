#include "stdc++.h"



using namespace std;



typedef long long int ll;

#define inf 0x3f3f3f3f

#define endl '\n'

// #define case(i) "Case #" << i << ": "



int n, k;

vector<int> v;

int dp[100001];



int solve(int i) {

    if(i == 0) return 0;

    else {

        int mn = inf;

        for(int j = 1; j <= k && i - j >= 0; ++j) {

            if(dp[i-j] == -1) dp[i-j] = solve(i-j);

            mn = min(mn, abs(v[i] - v[i-j]) + dp[i-j]);

        }

        return mn;

    }

}



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);



    memset(dp, -1, sizeof(dp));



    cin >> n >> k;

    v.resize(n);



    for(int i = 0; i < n; ++i) cin >> v[i];



    cout << solve(n-1) << endl;

}