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

#include <cassert>

#include <random>





double ternary_search(

        const std::function<double(double)> &fn,

        double lo=0., double hi=1e9) {

    for (int iter = 0; iter < 100; iter++) {

        double midl = lo + (hi - lo) / 3;

        double midr = lo + 2*(hi - lo) / 3;

        if (fn(midl) < fn(midr)) hi = midr;

        else lo = midl;

    }

    return lo;

}



constexpr double EPS = 1e-12;



double binary_search_left(

        const std::function<double(double)> &fn,

        double t, double lo = 0., double hi = 1e9) {

    hi = t;

    double targ = fn(t);

    for (int iter = 0; iter < 100; iter++) {

        double mid = lo + (hi - lo)/2;

        if (std::abs(fn(mid) - targ) < EPS) hi = mid;

        else lo = mid;

    }

    return lo;

}



double binary_search_right(

    const std::function<double(double)> &fn,

    double t, double lo = 0., double hi = 1e9) {

    lo = t;

    double targ = fn(t);

    for (int iter = 0; iter < 100; iter++) {

        double mid = lo + (hi - lo) / 2;

        if (std::abs(fn(mid) - targ) < EPS) lo = mid;

        else hi = mid;

    }

    return lo;

}



int main() {

    int n; std::cin >> n;

    std::vector<double> x(n), y(n);

    std::vector<double> dx(n), dy(n);

    for (int i = 0; i < n; i++) {

        std::cin >> x[i] >> y[i];

        char c; std::cin >> c;

        if (c == 'R') dx[i] = 1;

        if (c == 'L') dx[i] = -1;

        if (c == 'U') dy[i] = 1;

        if (c == 'D') dy[i] = -1;

    }

    auto fxmax = [&](double t) {

        double ret = -1e9;

        for (int i = 0; i < n; i++) {

            ret = std::max(ret, x[i] + t*dx[i]);

        }

        return ret;

    };

    auto fxmin = [&](double t) {

        double ret = 1e9;

        for (int i = 0; i < n; i++) {

            ret = std::min(ret, x[i] + t*dx[i]);

        }

        return -ret;

    };

    auto fymax = [&](double t) {

        double ret = -1e9;

        for (int i = 0; i < n; i++) {

            ret = std::max(ret, y[i] + t*dy[i]);

        }

        return ret;

    };

    auto fymin = [&](double t) {

        double ret = 1e9;

        for (int i = 0; i < n; i++) {

            ret = std::min(ret, y[i] + t*dy[i]);

        }

        return -ret;

    };



    std::vector<double> cand;

    auto push = [&](const auto& fn) {

        double t = ternary_search(fn);

        cand.push_back(binary_search_left(fn, t));

        cand.push_back(binary_search_right(fn, t));

    };

    push(fxmax);

    push(fxmin);

    push(fymax);

    push(fymin);



    double ans = 2e18;

    for (double t : cand) {

        ans = std::min(ans, (fxmax(t) + fxmin(t))*(fymax(t) + fymin(t)));

    }

    printf("%.14f\n", ans);

    return 0;

}
