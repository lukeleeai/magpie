#include <iostream>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <algorithm>

#include <string>

#include <sstream>

#include <complex>

#include <vector>

#include <list>

#include <queue>

#include <deque>

#include <stack>

#include <map>

#include <set>

using namespace std;

typedef long long unsigned int ll;



#define EPS (1e-7)

#define INF (1e9)

#define PI (acos(-1))

const long double zero = 0.0;

ll x[1010], y[1010], r[1010];

long double dist(int i, int j)

{

    ll dx = (x[i] - x[j]);

    ll dy = y[i] - y[j];

    return pow((long double)(dx * dx + dy * dy), 0.5);

}



int main() {

    cout.precision(100);

    ll xs, ys, xt, yt;

    cin >> xs >> ys >> xt >> yt;

    int n;

    cin >> n;

    for(int i = 1; i <= n; i++){

        cin >> x[i] >> y[i] >> r[i];

    }

    x[0] = xt;

    y[0] = yt;

    r[0] = 0;

    x[n + 1] = xs;

    y[n + 1] = ys;

    vector<pair<long double, int> > cost;

    for(int i = 0; i <= n; i++){

        pair<long double, int> in;

        in.first = max(zero, dist(i, n + 1) - r[i]);

        in.second = i;

        cost.push_back(in);

    }

    sort(cost.begin(), cost.end());

    for(int i = 0; i <= n; i++){

        if(cost[i].second == 0){

            cout << cost[i].first << endl;

            return 0;

        }

        for(int j = i + 1; j <= n; j++){

            cost[j].first = min(cost[j].first, cost[i].first + max(zero, dist(cost[i].second, cost[j].second) - r[cost[i].second] - r[cost[j].second]));

        }

        sort(cost.begin() + i + 1, cost.end());

    }

    return 0;

}
