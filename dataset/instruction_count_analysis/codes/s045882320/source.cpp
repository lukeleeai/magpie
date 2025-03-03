#include "stdc++.h"

using namespace std;

using ll = long long;



template <typename M>

struct DualSegmentTree {

    using T = typename M::T;



    DualSegmentTree(int n) {

        size = 1;

        height = 1;

        while (size < n) size <<= 1, height++;

        lazy.resize(2 * size, M::id);

    }



    T operator[](int k) {

        k += size;

        propagate(k);

        return lazy[k];

    }



    void update(int l, int r, const T& x) {

        l += size;

        r += size;

        propagate(l);

        propagate(r - 1);

        for (; l < r; l >>= 1, r >>= 1) {

            if (l & 1) lazy[l] = M::op(lazy[l], x), l++;

            if (r & 1) --r, lazy[r] = M::op(lazy[r], x);

        }

    }



private:

    int size, height;

    vector<T> lazy;



    void push(int k) {

        if (lazy[k] == M::id) return;

        lazy[2 * k] = M::op(lazy[2 * k], lazy[k]);

        lazy[2 * k + 1] = M::op(lazy[2 * k + 1], lazy[k]);

        lazy[k] = M::id;

    }



    void propagate(int k) {

        for (int i = height; i > 0; i--) push(k >> i);

    }

};



struct Monoid {

    using T = int;

    static inline const int id = 1e9;

    static T op(T a, T b) {

        return min(a, b);

    }

};



int main() {

    ios_base::sync_with_stdio(false);

    cin.tie(0);



    int N, Q;

    cin >> N >> Q;

    DualSegmentTree<Monoid> st1(N - 2), st2(N - 2);

    st1.update(0, N - 2, N - 2);

    st2.update(0, N - 2, N - 2);

    ll ans = 1ll * (N - 2) * (N - 2);

    for (int i = 0; i < Q; i++) {

        int t, x;

        cin >> t >> x;

        x -= 2;

        if (t == 1) {

            int c = st1[x];

            ans -= c;

            st2.update(0, c, x);

        } else {

            int c = st2[x];

            ans -= c;

            st1.update(0, c, x);

        }

    }

    cout << ans << endl;

}