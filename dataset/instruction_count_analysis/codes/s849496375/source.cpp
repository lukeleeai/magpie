/*                         _

                        _ooOoo_

                       o8888888o

                       88" . "88

                       (| -_- |)

                       O\  =  /O

                    ____/`---'\____

                  .'  \\|     |//  `.

                 /  \\|||  :  |||//  \

                /  _||||| -:- |||||_  \

                |   | \\\  -  /'| |   |

                | \_|  `\`---'//  |_/ |

                \  .-\__ `-. -'__/-.  /

              ___`. .'  /--.--\  `. .'___

           ."" '<  `.___\_<|>_/___.' _> \"".

          | | :  `- \`. ;`. _/; .'/ /  .' ; |

          \  \ `-.   \_\_`. _.'_/_/  -' _.' /

===========`-.`___`-.__\ \___  /__.-'_.'_.-'================



                  Please give me AC.

*/



#include <iostream>

#include <iomanip>

#include <cstdio>

#include <cmath>

#include <cstdlib>

#include <cstring>

#include <algorithm>

#include <numeric>

#include <string>

#include <sstream>

#include <complex>

#include <bitset>

#include <vector>

#include <list>

#include <set>

#include <map>

#include <queue>

#include <deque>

#include <stack>

#include <unordered_map>

#include <unordered_set>

#include <utility>

#include <chrono>

#include <random>



using namespace std;



using int64 = long long;

using uint64 = unsigned long long;

using vi = vector<int>;

using vl = vector<int64>;

using pii = pair<int, int>;

using pll = pair<int64, int64>;



#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

#define all(v) (v).begin(), (v).end()

#define print(x) cout << (x) << '\n'

#define print2(x, y) cout << (x) << ' ' << (y) << '\n'

#define print3(x, y, z) cout << (x) << ' ' << (y) << ' ' << (z) << '\n'

#define printn(v) rep(i, (v).size() - 1) cout << (v)[i] << ' '; cout << (v)[n - 1] << '\n';

#define debug(x) cerr << #x << ": " << (x) << '\n'

#define debug2(x, y) cerr << #x << ": " << (x) << ", " << #y << ": " << (y) << '\n'

#define debug3(x, y, z) cerr << #x << ": " << (x) << ", " << #y << ": " << (y) << ", " << #z << ": " << (z) << '\n'

#define dbg(v) for (size_t _ = 0; _ < v.size(); ++_){cerr << #v << "[" << _ << "] : " << v[_] << '\n';}

// constant

const int INF = (1<<30) - 1;

const int64 INF64 = (1LL<<62) - 1;



template<typename T> T gcd(T a, T b) {

    if (a < b) return gcd(b, a);

    T r;

    while ((r = a % b)) {

        a = b;

        b = r;

    }

    return b;

}



template<typename T> T lcm(const T a, const T b) {

    return a / gcd(a, b) * b;

}



template<typename T> bool chmin(T& a, const T& b) {

    if (a > b) return a = b, true; else return false;

}



template<typename T> bool chmax(T& a, const T& b) {

    if (a < b) return a = b, true; else return false;

}



// End of template.

// begin monoid

template<typename T, T f_(T const, T const)>

class Monoid {

public:

    using type = T;



    static T f(T const a, T const b) {

        return f_(a, b);

    }



    static const T unit;



    template<typename I>

    static T concat(I const& begin, I const& end) {

        return accumulate(begin, end, unit, f);

    }



    static T pow(T base, int exp) {

        T res = unit;

        while (exp > 0) {

            if (exp & 1) res = f(base, res);

            base = f(base, base);

            exp >>= 1;

        }

        return res;

    }

};

// end monoid





// begin segment_tree

// monoid に依存

template<typename M>

typename M::type st_default(typename M::type const m, typename M::type const op, int const b) {

    return M::f(m, op);

}



/*

 * セグメントツリー

 */

template<typename M>

class SegmentTree {

public:

    using MT = typename M::type;

    SegmentTree(const int n) {

        depth = int (ceil(log2(max(2, n))));

        this->n = 1 << depth;

        v.resize(2 * this->n, M::unit);

    }

    void set(int i, MT const m) {

        i += n;

        v[i] = m;

        build(i, i + 1);

    }

    void set(int l, int r, MT const m) {

        l += n; r += n;

        for (int i = l; i < r; ++i) v[i] = m;

        build(l, r);

    }

    template<typename I>

    void set(int l, int r, I it) {

        l += n; r += n;

        for (int i = l; i < r; ++i) v[i] = *it++;

        build(l, r);

    }

    MT get() const {

        return v[1];

    }

    MT get(int const i) {

        return v[n + i];

    }

    MT get(int l, int r) {

        MT L = M::unit, R = M::unit;

        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {

            if (l & 1) L = M::f(L, v[l++]);

            if (r & 1) R = M::f(v[--r], R);

        }

        return M::f(L, R);

    }



    void build(int l, int r) {

        r--;

        l >>= 1; r >>= 1;

        while (l > 0) {

            for (int i = l; i <= r; ++i) v[i] = M::f(v[2 * i], v[2 * i + 1]);

            l >>= 1; r >>= 1;

        }

    }

    

    vector<MT> v;

    int n;

    int depth;

};









// end segment_tree



int f(int a, int b) { return a | b; }

using M = Monoid<int, f>;

template<> int const Monoid<int, f>::unit(0);



SegmentTree<M> seg(500500);



int main() {

    cout << fixed << setprecision(15);

    ios::sync_with_stdio(false);

    cin.tie(nullptr);

    // cin.read(buf, sizeof buf); // 注意: ./a.out < in か pbp | ./a.out で入力すること



    int n, q;

    string s;

    cin >> n >> s >> q;

    rep(i, n) {

        seg.set(i, 1 << (s[i] - 'a'));

    }

    debug(seg.get(0, 1));

    debug(seg.get(0, 2));



    rep(i, q) {

        int t, a, b;

        char c;

        cin >> t;

        if (t == 1) {

            cin >> a >> c;

            seg.set(a - 1, 1 << (c - 'a'));

        } else {

            cin >> a >> b;

            print(__builtin_popcount(seg.get(a - 1, b)));

        }

    }



    return 0;

}


