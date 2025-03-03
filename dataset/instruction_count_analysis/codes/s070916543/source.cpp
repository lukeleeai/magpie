#include "stdc++.h"

using i64 = long long;



int main() {

    int n;

    std::cin >> n;

    std::vector<int> b(n + 1);

    for (int i = 0; i < n; i++) {

        int in;

        std::cin >> in;

        b[in] = i;

    }



    i64 ret = 0;

    std::multiset<int> v { -1, -1, n, n };

    for (i64 i = n; i > 0; i--) {

        auto d = v.upper_bound(b[i]), f = std::next(d), s = std::prev(d), a = std::prev(s);

        ret += i * (*f - *d) * (b[i] - *s) + i * (*d - b[i]) * (*s - *a);

        v.insert(b[i]);

    }



    std::cout << ret << std::endl;



    return 0;

}
