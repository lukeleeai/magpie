#include <cstdio>

#include <iostream>

#include <string>

#include <vector>

#include <sstream>

#include <map>

#include <set>

#include <queue>

#include <algorithm>

#include <cmath>

#include <cstring>

#include <typeinfo>

#include <numeric>

#include <functional>

#include <unordered_map>

#include <bitset>

#include <stack>

#include <assert.h>

#include <unordered_set>

#include <random>







using namespace std;

using ll = long long;

using ull = unsigned long long;



const ll INF = 1e18;

const ll MOD = 1e9 + 7;



#define REP(i, n) for(ll i = 0; i < n; i++)



































int main(){

    int n, t;

    scanf("%d %d", &n, &t);

    pair<int, int> v[3000];

    int max_a = 0;

    for(int i = 0; i < n; i++){

        scanf("%d %d", &v[i].first, &v[i].second);

        max_a = max(max_a, v[i].first);

    }

    sort(v, v + n);

    int dp[6000] = {}, tmp[6000] = {};

    for(int i = 0; i < n; i++){

        for(int j = 0; j < t; j++){

            tmp[j + v[i].first] = dp[j] + v[i].second;

        }

        for(int j = 0; j < t + max_a; j++){

            dp[j] = max(dp[j], tmp[j]);

        }

    }

    printf("%d\n", *max_element(dp, dp + t + max_a));

}