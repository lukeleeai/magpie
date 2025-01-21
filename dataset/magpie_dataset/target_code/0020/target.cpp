#include "stdc++.h"

using namespace std;



int main() {

    int n, k;

    cin >> n >> k;



    vector<int> heights(n, 0);

    for(int i=0; i<n; ++i) cin >> heights[i];



    vector<int> dp(n, 0);

    for(int i=1; i<n; ++i)

    {

        dp[i] = dp[i-1] + abs(heights[i]-heights[i-1]);

        for(int j=1; j<=k && i-j>=0; ++j)

            dp[i] = min(dp[i], dp[i-j] + abs(heights[i]-heights[i-j]));

    }

    

    cout << dp[n-1] << '\n';



    return 0;

}