#include "stdc++.h"

using i64 = long long;



template <typename T, typename F>

class SegmentTree {

    int size;

    T id;

    T *dat;

    F f;



    T query_impl(const int a, const int b, const int k, const int l, const int r) const {

        if (r <= a || b <= l) return id;

        if (a <= l && r <= b) return dat[k];

        return f(query_impl(a, b, k * 2 + 1, l, (l + r) / 2),

                 query_impl(a, b, k * 2 + 2, (l + r) / 2, r));

    }



public:

    SegmentTree(const int n, const T &id, const F f) : id(id), f(f) {

        size = 2;

        while (size < n) size *= 2;

        dat = new T[2 * size - 1];

        for (int i = 0; i < 2 * size - 1; i++) dat[i] = id;

    }



    template <template <class> class Container>

    SegmentTree(const Container<T> &v, const T &id, const F f) : id(id), f(f) {

        size = 2;

        int n = v.size();

        while (size < n) size *= 2;

        dat = new T[2 * size - 1];

        for (int i = size - 1; i < size - 1 + n; i++) dat[i] = v[i - size + 1];

        for (int i = size - 1 + n; i < 2 * size - 1; i++) dat[i] = id;

        dig(0);

    }



    void dig(int v) {

        if (v >= size - 1) return;

        dig(2 * v + 1);

        dig(2 * v + 2);

        dat[v] = f(dat[2 * v + 1], dat[2 * v + 2]);

    }



    ~SegmentTree() {

        delete[] dat;

    }



    void update(int i, const T x) {

        i += size - 1;

        dat[i] = x;

        while (i > 0) {

            i = (i - 1) / 2;

            dat[i] = f(dat[i * 2 + 1], dat[i * 2 + 2]);

        }

    }



    T query(const int a, const int b) const {

        return query_impl(a, b, 0, 0, size);

    }



    T operator[](const int i) const {

        return dat[i + size - 1];

    }

};



template <typename T, typename F>

auto make_st(const int n, const T &id, const F f) {

    return SegmentTree<T, F>(n, id, f);

}



int main() {

    constexpr int inf = 100002;

    int n;

    std::cin >> n;

    std::vector<i64> a(n + 2), r(n + 1);

    a[0] = a[n + 1] = inf;

    std::vector<std::pair<int, int>> sf(n + 2), pf(n + 2);

    for (int i = 1; i <= n; i++) {

        std::cin >> a[i];

        r[a[i]] = i;

    }



    auto st = make_st(101010, std::make_pair(inf, inf), [](const auto &lhs, const auto &rhs) {

        if (lhs.first < rhs.first) return std::make_pair(lhs.first, std::min(lhs.second, rhs.first));

        else return std::make_pair(rhs.first, std::min(rhs.second, lhs.first));

    });



    for (int i = n + 1; i > 0; i--) {

        if (a[i] <= n) sf[a[i]] = st.query(a[i], inf + 1);

        st.update(a[i], std::make_pair(i, inf));

    }



    auto tt = make_st(101010, std::make_pair(-1, -1), [](const auto &lhs, const auto &rhs) {

        if (lhs.first > rhs.first) return std::make_pair(lhs.first, std::max(rhs.first, lhs.second));

        else return std::make_pair(rhs.first, std::max(rhs.second, lhs.first));

    });



    for (int i = 0; i <= n; i++) {

        if (a[i] <= n) pf[a[i]] = tt.query(a[i], inf + 1);

        tt.update(a[i], std::make_pair(i, -1));

    }



    i64 ret = 0;

    for (i64 i = 1; i <= n; i++) {

        if (pf[i].first >= 0 && sf[i].second < inf) ret += i * (r[i] - pf[i].first) * (sf[i].second - sf[i].first);

        if (pf[i].second >= 0 && sf[i].first < inf) ret += i * (pf[i].first - pf[i].second) * (sf[i].first - r[i]);

    }



    std::cout << ret << std::endl;



    return 0;

}
