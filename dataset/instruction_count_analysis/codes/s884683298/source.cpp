#include <iostream>

#include <string>

#include <algorithm>

#include <vector>

#include <cmath>

#include <queue>

#include <map>

#include <unordered_map>

#include <set>

#include <functional>

#include <bitset>

#include <numeric>

#include <complex>

#include <iomanip>

#include <cassert>

#include <random>





long double ternary_search(

    const std::function<long double(long double)> &fn,

    long double lo = 0., long double hi = 1e9) {

    for (int iter = 0; iter < 1000; iter++) {

        long double midl = lo + (hi - lo) / 3;

        long double midr = lo + (hi - lo) / 3 * 2;

        if (fn(midl) < fn(midr)) hi = midr;

        else lo = midl;

    }

    return lo;

}



constexpr long double EPS = 1e-18;



long double binary_search_left(

    const std::function<long double(long double)> &fn,

    long double t, long double lo = 0., long double hi = 1e9) {

    hi = t;

    long double targ = fn(t);

    for (int iter = 0; iter < 100; iter++) {

        long double mid = lo + (hi - lo) / 2;

        if (std::abs(fn(mid) - targ) < EPS) hi = mid;

        else lo = mid;

    }

    return lo;

}



long double binary_search_right(

    const std::function<long double(long double)> &fn,

    long double t, long double lo = 0., long double hi = 1e9) {

    lo = t;

    long double targ = fn(t);

    for (int iter = 0; iter < 100; iter++) {

        long double mid = lo + (hi - lo) / 2;

        if (std::abs(fn(mid) - targ) < EPS) lo = mid;

        else hi = mid;

    }

    return lo;

}



int main() {

    int n; std::cin >> n;

    std::vector<long double> x(n), y(n);

    std::vector<long double> dx(n), dy(n);

    for (int i = 0; i < n; i++) {

        std::cin >> x[i] >> y[i];

        char c; std::cin >> c;

        if (c == 'R') dx[i] = 1;

        if (c == 'L') dx[i] = -1;

        if (c == 'U') dy[i] = 1;

        if (c == 'D') dy[i] = -1;

    }

    auto fxmax = [&](long double t) {

        long double ret = -1e18;

        for (int i = 0; i < n; i++) {

            ret = std::max(ret, x[i] + t*dx[i]);

        }

        return ret;

    };

    auto fxmin = [&](long double t) {

        long double ret = 1e18;

        for (int i = 0; i < n; i++) {

            ret = std::min(ret, x[i] + t*dx[i]);

        }

        return -ret;

    };

    auto fymax = [&](long double t) {

        long double ret = -1e18;

        for (int i = 0; i < n; i++) {

            ret = std::max(ret, y[i] + t*dy[i]);

        }

        return ret;

    };

    auto fymin = [&](long double t) {

        long double ret = 1e18;

        for (int i = 0; i < n; i++) {

            ret = std::min(ret, y[i] + t*dy[i]);

        }

        return -ret;

    };



    std::vector<long double> cand = { 0. };

    auto push = [&](const auto& fn) {

        long double t = ternary_search(fn);

        cand.push_back(binary_search_left(fn, t));

        cand.push_back(binary_search_right(fn, t));

    };

    push(fxmax);

    push(fxmin);

    push(fymax);

    push(fymin);



    long double ans = 2e18;

    for (long double t : cand) {

        ans = std::min(ans, (fxmax(t) + fxmin(t))*(fymax(t) + fymin(t)));

    }

    printf("%.14Lf\n", ans);

    return 0;

}
