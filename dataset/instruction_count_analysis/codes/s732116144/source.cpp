#include "stdc++.h"

using namespace std;

#define finish(x) return cout << x << endl, 0

#define ll long long



const int N = 100001;



int n, dp[2 * N], mod = 1e9 + 7;

vector <int> a;



int solve(int idx, int open){

    if(idx == 2 * n) return open == 0;

    if(open < 0) return 0;

    if(dp[idx] != -1) return dp[idx];

    if(((open & 1) ^ a[idx]) == 0) return 1LL * open * solve(idx + 1, open - 1) % mod;

    return solve(idx + 1, open + 1);

}

int main(){

    ios_base::sync_with_stdio(0);

    cin.tie(0);

    memset(dp, -1, sizeof dp);

    cin >> n;

    for(int i = 0 ; i < 2 * n ; i++){

        char c;

        cin >> c;

        a.push_back(c == 'W' ? 0 : 1);

    }

    int ans = solve(0, 0);

    for(int i = 1 ; i <= n ; i++){

        ans = 1LL * ans * i % mod;

    }

    cout << ans << endl;

}
