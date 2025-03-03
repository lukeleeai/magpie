#include <iostream>

#include <iomanip>

#include <string>

#include <vector>

#include <algorithm>

#include <map>

#include <cmath>

#include <queue>

#include <set>

#include <cassert>

#include <random>



#define rep(i, n) for (int i = 0; i < (n); i++)



using namespace std;

typedef long long int ll;

const ll INF = 1000000000;

const double PI = acos(-1);

const int mod = 1000000007;



int dp[100001] = {0};



int main()

{

    int x;

    cin >> x;



    dp[0] = 1;

    for (int i = 100; i <= 105; i++) {

        dp[i] = 1;

    }

    for (int i = 200; i <= x; i++) {

        if (dp[i - 100] || dp[i - 101] || dp[i - 102] || dp[i - 103] || dp[i - 104] || dp[i - 105]) {

            dp[i] = 1;

        }

    }

    cout << dp[x] << endl;

    return 0;

}
