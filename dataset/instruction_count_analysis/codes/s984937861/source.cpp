//

//  ROIGold.cpp

//  Main calisma

//

//  Created by Rakhman on 05/02/2019.

//  Copyright © 2019 Rakhman. All rights reserved.

//



#include <cstring>

#include <vector>

#include <list>

#include <map>

#include <set>

#include <deque>

#include <stack>

#include <bitset>

#include <algorithm>

#include <functional>

#include <numeric>

#include <utility>

#include <sstream>

#include <iostream>

#include <iomanip>

#include <cstdio>

#include <queue>

#include <cmath>

#include <cstdlib>

#include <ctime>

#include <cassert>

#include <iterator>



#define ios ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);

#define S second

#define F first

#define pb push_back

#define nl '\n'

#define NL cout << '\n';

#define EX exit(0)

#define all(s) s.begin(), s.end()

#define FOR(i, start, finish, k) for(int i = start; i <= finish; i += k)



const int MXN = 1e6 + 200;

const long long MNN = 4e2 + 200;

const long long MOD = 1e9 + 7;

const long long INF = 1e18;

const int OO = 1e9 + 500;



typedef long long llong;

typedef unsigned long long ullong;



using namespace std;



int n;

llong a[MXN], pr[MXN], dp[MNN][MNN];



int main () {

    ios;

    cin >> n;

    for(int i = 1; i <= n; i++){

        for(int j = 1; j <= n; j++){

            dp[i][j] = INF;

        }

    }

    for(int i = 1; i <= n; i++){

        cin >> a[i];

        pr[i] = pr[i - 1] + a[i];

        dp[i][i] = 0;

    }

    for(int sz = 1; sz <= n - 1; sz++){

        for(int l = 1; l + sz <= n; l++){

            int r = l + sz;

            for(int i = l; i < r; i++){

                dp[l][r] = min(dp[l][r], dp[l][i] + dp[i + 1][r] + pr[r] - pr[l - 1]);

                //cout << i << ' ' << l << ' ' << r << ' ' << dp[l][i] + dp[i + 1][r] + pr[r] - pr[l - 1] << nl;

            }

            //cout << l << ' ' << r << ' ' << dp[l][r] << nl;

        }

    }

    cout << dp[1][n];

}
