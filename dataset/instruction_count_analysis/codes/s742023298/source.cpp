#include <vector>

#include <functional>

#include <algorithm>

#include <iostream>

#include <climits>

using namespace std;



template <typename MonoidType, typename OperatorType, class SegFunc>

struct LazySegmentTree {

    // node, lazy, update flag (for lazy), identity element

    int n;

    vector<MonoidType> node;

    vector<OperatorType> lazy;

    vector<bool> need_update;

    MonoidType E0;

    OperatorType E1;



    void build(int m, const vector<MonoidType> &v = vector<MonoidType>()) {

        if(v != vector<MonoidType>()) m = v.size();

        n = 1; while(n < m) n *= 2;



        node = vector<MonoidType>(2*n-1, E0);

        lazy = vector<OperatorType>(2*n-1, E1);

        need_update = vector<bool>(2*n-1, false);

        if(v != vector<MonoidType>()) {

            for(int i=0; i<m; i++) {

                node[n-1+i] = v[i];

            }

            for(int i=n-2; i>=0; i--) {

                node[i] = SegFunc::combine(node[2*i+1], node[2*i+2]);

            }

        }

    }



    // initialize

    LazySegmentTree() {}

    LazySegmentTree(int n_, MonoidType E0_, OperatorType E1_,

                    vector<MonoidType> v = vector<MonoidType>()) :

        E0(E0_), E1(E1_) {

        build(n_, v);

    }



    void eval(int k, int l, int r) {

        if(!need_update[k]) return;

        node[k] = SegFunc::update(node[k], SegFunc::accumulate(lazy[k], r - l));

        if(r - l > 1) {

            lazy[2*k+1] = SegFunc::lazy_update(lazy[2*k+1], lazy[k]);

            lazy[2*k+2] = SegFunc::lazy_update(lazy[2*k+2], lazy[k]);

            need_update[2*k+1] = need_update[2*k+2] = true;

        }

        lazy[k] = E1;

        need_update[k] = false;

    }



    void update(int a, int b, OperatorType x, int l, int r, int k) {

        eval(k, l, r);

        if(b <= l or  r <= a) return;

        if(a <= l and r <= b) {

            lazy[k] = SegFunc::lazy_update(lazy[k], x);

            need_update[k] = true;

            eval(k, l, r);

        }

        else {

            int mid = (l + r) / 2;

            update(a, b, x, l, mid, 2*k+1);

            update(a, b, x, mid, r, 2*k+2);

            node[k] = SegFunc::combine(node[2*k+1], node[2*k+2]);

        }

    }



    MonoidType query(int a, int b, int l, int r, int k) {

        if(b <= l or  r <= a) return E0;

        eval(k, l, r);

        if(a <= l and r <= b) return node[k];

        int mid = (l + r) / 2;

        MonoidType vl = query(a, b, l, mid, 2*k+1);

        MonoidType vr = query(a, b, mid, r, 2*k+2);

        return SegFunc::combine(vl, vr);

    }



    // update [a, b)-th element (applied value, x)

    void update(int a, int b, OperatorType x) {

        update(a, b, x, 0, n, 0);

    }



    // range query for [a, b)

    MonoidType query(int a, int b) {

        return query(a, b, 0, n, 0);

    }



    void dump() {

        fprintf(stderr, "[lazy]\n");

        for(int i=0; i<2*n-1; i++) {

            if(i == n-1) fprintf(stderr, "xxx ");

            if(lazy[i] == E1) fprintf(stderr, "  E ");

            else fprintf(stderr, "%3d ", lazy[i]);

        }

        fprintf(stderr, "\n");



        fprintf(stderr, "[node]\n");

        for(int i=0; i<2*n-1; i++) {

            if(i == n-1) fprintf(stderr, "xxx ");

            if(node[i] == E0) fprintf(stderr, "  E ");

            else fprintf(stderr, "%3d ", node[i]);

        }

        fprintf(stderr, "\n");

    }

};





// Verified on Apr 27, 2019

void DSL_2_D() {

    struct SegFunc {

        static int update(int a, int b) { return b; }

        static int combine(int a, int b) { return min(a, b); }

        static int lazy_update(int a, int b) { return b; }

        static int accumulate(int a, int b) { return a; }

    };

    

    int N, Q; cin >> N >> Q;

    LazySegmentTree<int, int, SegFunc> seg(N, INT_MAX, INT_MAX);

    

    int indexed = 0;

    for(int i=0; i<Q; i++) {

        int query_type; cin >> query_type;

        if(query_type == 0) {

            int s, t, x; cin >> s >> t >> x; t++;

            s -= indexed, t -= indexed;

            seg.update(s, t, x);

        }

        if(query_type == 1) {

            int s; cin >> s;

            s -= indexed;

            cout << seg.query(s, s+1) << endl;

        }

        // seg.dump();

    }

}



// Verified on Apr 27, 2019

void DSL_2_E() {

    struct SegFunc {

        static int update(int a, int b) { return a + b; }

        static int combine(int a, int b) { return a + b; }

        static int lazy_update(int a, int b) { return a + b; }

        static int accumulate(int a, int x) { return a * x; }

    };



    int N, Q; cin >> N >> Q;

    LazySegmentTree<int, int, SegFunc> seg(N, 0, 0);

    

    int indexed = 1;

    for(int i=0; i<Q; i++) {

        int query_type; cin >> query_type;

        if(query_type == 0) {

            int s, t, x; cin >> s >> t >> x; t++;

            s -= indexed, t -= indexed;

            seg.update(s, t, x);

        }

        if(query_type == 1) {

            int s; cin >> s;

            s -= indexed;

            cout << seg.query(s, s+1) << endl;

        }

        // seg.dump();

    }    

}



// Verified on Apr 27, 2019

void DSL_2_F() {

    struct SegFunc {

        static int update(int a, int b) { return b; }

        static int combine(int a, int b) { return min(a, b); }

        static int lazy_update(int a, int b) { return b; }

        static int accumulate(int a, int x) { return a; }

    };

    

    int N, Q; cin >> N >> Q;

    LazySegmentTree<int, int, SegFunc> seg(N, INT_MAX, 0);

    

    int indexed = 0;

    for(int i=0; i<Q; i++) {

        int query_type; cin >> query_type;

        if(query_type == 0) {

            int s, t, x; cin >> s >> t >> x; t++;

            s -= indexed, t -= indexed;

            seg.update(s, t, x);

        }

        if(query_type == 1) {

            int s, t; cin >> s >> t; t++;

            s -= indexed; t -= indexed;

            cout << seg.query(s, t) << endl;

        }

        // seg.dump();

    }    

}



// Verified on Apr 27, 2019

void DSL_2_G() {

    using ll = long long int;

    struct SegFunc {

        static ll update(ll a, ll b) { return a + b; }

        static ll combine(ll a, ll b) { return a + b; }

        static ll lazy_update(ll a, ll b) { return a + b; }

        static ll accumulate(ll a, ll x) { return a * x; }

    };



    int N, Q; cin >> N >> Q;

    LazySegmentTree<ll, ll, SegFunc> seg(N, 0, 0);

    

    int indexed = 1;

    for(int i=0; i<Q; i++) {

        int query_type; cin >> query_type;

        if(query_type == 0) {

            int s, t, x; cin >> s >> t >> x; t++;

            s -= indexed, t -= indexed;

            seg.update(s, t, x);

        }

        if(query_type == 1) {

            int s, t; cin >> s >> t; t++;

            s -= indexed; t -= indexed;

            cout << seg.query(s, t) << endl;

        }

        // seg.dump();

    }    

}



// Verified on Apr 27, 2019

void DSL_2_H() {

    int N, Q; cin >> N >> Q;

    using ll = long long int;



    struct SegFunc {

        static ll update(ll a, ll b) { return a + b; }

        static ll combine(ll a, ll b) { return min(a, b); }

        static ll lazy_update(ll a, ll b) { return a + b; }

        static ll accumulate(ll a, ll x) { return a; }

    };

    

    LazySegmentTree<ll, ll, SegFunc> seg(N, INT_MAX, 0, vector<ll>(N));

    

    int indexed = 0;

    for(int i=0; i<Q; i++) {

        int query_type; cin >> query_type;

        if(query_type == 0) {

            int s, t, x; cin >> s >> t >> x; t++;

            s -= indexed, t -= indexed;

            seg.update(s, t, x);

        }

        if(query_type == 1) {

            int s, t; cin >> s >> t; t++;

            s -= indexed; t -= indexed;

            cout << seg.query(s, t) << endl;

        }

        // seg.dump();

    }    

}



/*

// Verified on Apr 27, 2019

void DSL_2_I() {

    int N, Q; cin >> N >> Q;

    using ll = long long int;

    LazySegmentTree<ll, ll> seg(N, 0, 0,

                                [](ll a, ll  b) { return b;     },  // upd

                                [](ll a, ll  b) { return a + b; },  // cmb

                                [](ll a, ll  b) { return b;     },  // lzy

                                [](ll a, int x) { return a * x; },  // acc

                                vector<ll>(N));

    

    int indexed = 0;

    for(int i=0; i<Q; i++) {

        int query_type; cin >> query_type;

        if(query_type == 0) {

            int s, t, x; cin >> s >> t >> x; t++;

            s -= indexed, t -= indexed;

            seg.update(s, t, x);

        }

        if(query_type == 1) {

            int s, t; cin >> s >> t; t++;

            s -= indexed; t -= indexed;

            cout << seg.query(s, t) << endl;

        }

        // seg.dump();

    }    

}



void yuki_749() {

    int N, Q; cin >> N >> Q;



    

    

}

*/



int main() {

    // DSL_2_D();

    // DSL_2_E();

    // DSL_2_F();

    // DSL_2_G();

    DSL_2_H();

    // DSL_2_I();

    return 0;

}


