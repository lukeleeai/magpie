#include "stdc++.h"

using namespace std;



using i64 = int64_t;



#define rep(i, x, y) for (i64 i = i64(x), i##_max_for_repmacro = i64(y); i < i##_max_for_repmacro; ++i)

#define debug(x) #x << "=" << (x)



#ifdef DEBUG

#define _GLIBCXX_DEBUG

#define print(x) std::cerr << debug(x) << " (L:" << __LINE__ << ")" << std::endl

#else

#define print(x)

#endif



template <i64 p>

class fp {

    public:

    i64 x;

    fp() : x(0) {}

    fp(i64 x_) : x((x_ % p + p) % p) {}

    fp operator+() const { return fp(x); }

    fp operator-() const { return fp(-x); }

    fp& operator+=(const fp& y) {

        x += y.x;

        if (x >= p) x -= p;

        return *this;

    }

    fp& operator-=(const fp& y) { return *this += -y; }

    fp& operator*=(const fp& y) {

        x = x * y.x % p;

        return *this;

    }

    fp& operator/=(const fp& y) { return *this *= fp(inverse(y.x)); }

    fp operator+(const fp& y) const { return fp(x) += y; }

    fp operator-(const fp& y) const { return fp(x) -= y; }

    fp operator*(const fp& y) const { return fp(x) *= y; }

    fp operator/(const fp& y) const { return fp(x) /= y; }

    bool operator==(const fp& y) const { return x == y.x; }

    bool operator!=(const fp& y) const { return !(*this == y); }

    i64 extgcd(i64 a, i64 b, i64& x, i64& y) {

        i64 d = a;

        if (b != 0) {

            d = extgcd(b, a % b, y, x);

            y -= (a / b) * x;

        } else {

            x = 1;

            y = 0;

        }

        return d;

    }

    i64 inverse(i64 a) {

        i64 x, y;

        extgcd(a, p, x, y);

        return (x % p + p) % p;

    }

};



template <i64 p>

i64 abs(const fp<p>& x) { return x.x; }



template <i64 p>

istream& operator>>(istream& is, fp<p>& x) {

    is >> x.x;

    return is;

}



template <i64 p>

ostream& operator<<(ostream& os, const fp<p>& x) {

    os << x.x;

    return os;

}



template <typename T, typename U>

ostream& operator<<(ostream& os, const pair<T, U>& p) {

    os << "(" << p.first << ", " << p.second << ")";

    return os;

}



template <typename T>

ostream& operator<<(ostream& os, const vector<T>& vec) {

    os << "[";

    for (const auto& v : vec) {

        os << v << ",";

    }

    os << "]";

    return os;

}



template <typename T>

bool chmin(T& a, const T& b) {

    if (a > b) {

        a = b;

        return true;

    }

    return false;

}



template <typename T>

bool chmax(T& a, const T& b) {

    if (a < b) {

        a = b;

        return true;

    }

    return false;

}



template <typename A, typename T, size_t size>

void fill(A (&ary)[size], const T& val) {

    fill((T*)ary, (T*)(ary + size), val);

}



constexpr int inf = 1.01e9;

constexpr i64 inf64 = 4.01e18;

constexpr long double eps = 1e-9;



// double(64bit浮動小数)のn分探索のループ回数の上限(2分探索なら50でも十分かもしれない). long double(80ビットの x87 浮動小数点型?)だと, 2分探索であってもこれだと足りないケースがある気がするので, もうちょっと余裕を持たせた方が良さそう.

constexpr i64 max_loop = 100;



// x未満の要素の個数を返す

template <typename T>

i64 count_less(const vector<T>& v, T x) {

    return lower_bound(begin(v), end(v), x) - begin(v);

}



// x以下の要素の個数を返す

template <typename T>

i64 count_less_or_equal(const vector<T>& v, T x) {

    return upper_bound(begin(v), end(v), x) - begin(v);

}



// xより大きい要素の個数を返す

template <typename T>

i64 count_greater(const vector<T>& v, T x) {

    return end(v) - upper_bound(begin(v), end(v), x);

}



// x以上の要素の個数を返す

template <typename T>

i64 count_greater_or_equal(const vector<T>& v, T x) {

    return end(v) - lower_bound(begin(v), end(v), x);

}



template <class T>

T rep_pow(T x, int64_t y) {

    T res(1);

    while (y > 0) {

        if (y & 1) res *= x;

        x *= x;

        y >>= 1;

    }

    return res;

}



template <typename T>

pair<vector<T>, map<T, T>> compress(const vector<T>& xs) {

    vector<T> unzip;

    unzip.reserve(xs.size());

    for (const auto& x : xs) unzip.emplace_back(x);



    sort(begin(unzip), end(unzip));

    unzip.erase(unique(begin(unzip), end(unzip)), end(unzip));



    map<T, i64> zip;

    rep(i, 0, unzip.size()) zip[unzip[i]] = i;



    return make_pair(unzip, zip);

}



template <typename T, typename F>

class segtree {

    F op;

    T id;

    i64 n, size_;

    vector<T> dat;



public:

    segtree() = default;

    segtree(F op, T id, i64 size, T initial_value) : op(op), id(id) { init(size, initial_value); }

    void init(int size, T initial_value) {

        size_ = size;

        n = 1;

        while (n < size) n *= 2;

        dat.assign(2 * n - 1, id);



        rep(i, n - 1, n - 1 + size_) dat[i] = initial_value;

        for (i64 i = n - 2; i >= 0; --i) dat[i] = op(dat[i * 2 + 1], dat[i * 2 + 2]);

    }

    int size() const { return size_; }

    void update(i64 k, T a) {

        k += n - 1;  // leaf

        dat[k] = a;

        while (k > 0) {

            k = (k - 1) / 2;

            dat[k] = op(dat[k * 2 + 1], dat[k * 2 + 2]);

        }

    }

    T at(int index) { return dat[index + n - 1]; }

    void add(i64 k, T a) { update(k, at(k) + a); }

    T query(i64 l, i64 r) {

        if(l>=r or r<=0 or n<=l) return id;

        l += n - 1;

        r += n - 1;

        T res_l = id, res_r = id;

        while (l < r) {

            if ((l & 1) == 0) {

                res_l = op(res_l, dat[l]);

                ++l;

            }

            if ((r & 1) == 0) {

                res_r = op(dat[r - 1], res_r);

                --r;

            }

            l = (l - 1) / 2;

            r = (r - 1) / 2;

        }

        return op(res_l, res_r);

    }

};



void solve() {

    constexpr i64 mod = 998244353;



    i64 N;

    cin >> N;

    vector<i64> x(N),y(N);

    rep(i,0,N) cin >> x[i] >> y[i];



    vector<i64> xs(N),ys(N);

    rep(i,0,N){

        xs[i]=x[i];

        ys[i]=y[i];

    }

    sort(begin(xs),end(xs));

    sort(begin(ys),end(ys));



    fp<mod> ans;

    rep(i,0,N){

        i64 u=count_less(ys,y[i]);

        i64 d=count_greater(ys,y[i]);

        i64 l=count_less(xs,x[i]);

        i64 r=count_greater(xs,x[i]);



        fp<mod> excl=rep_pow(fp<mod>(2),u)+rep_pow(fp<mod>(2),d)+rep_pow(fp<mod>(2),l)+rep_pow(fp<mod>(2),r);

        ans+=rep_pow(fp<mod>(2),N)-excl;

    }



    using pii=pair<i64,i64>;

    vector<pii> xy(N);

    rep(i,0,N) xy[i]=make_pair(x[i],y[i]);

    sort(begin(xy),end(xy));



    {

        auto add=[](i64 a,i64 b){ return a+b; };



        vector<i64> unzip;

        map<i64,i64> zip;

        tie(unzip,zip)=compress(ys);



        {

            segtree<i64, decltype(add)> left(add, 0, unzip.size(), 0);

            queue<pii> q;

            rep(i, 0, N) {

                while (!q.empty() and q.front().first < xy[i].first) {

                    i64 zy = zip[q.front().second];

                    q.pop();

                    left.add(zy, 1);

                }



                i64 zy = zip[xy[i].second];

                i64 lu = left.query(0, zy);

                i64 ld = left.query(zy + 1, unzip.size());

                ans += rep_pow(fp<mod>(2), lu);

                ans += rep_pow(fp<mod>(2), ld);



                q.push(xy[i]);

            }

        }

        {

            segtree<i64, decltype(add)> right(add, 0, unzip.size(), 0);

            queue<pii> q;

            for(i64 i=N-1; i>=0; --i){

                while (!q.empty() and q.front().first > xy[i].first) {

                    i64 zy = zip[q.front().second];

                    q.pop();

                    right.add(zy, 1);

                }



                i64 zy = zip[xy[i].second];

                i64 ru = right.query(0, zy);

                i64 rd = right.query(zy + 1, unzip.size());

                ans += rep_pow(fp<mod>(2), ru);

                ans += rep_pow(fp<mod>(2), rd);



                q.push(xy[i]);

            }

        }

    }

    ans-=N;



    cout << ans << endl;

}



int main() {

    std::cin.tie(0);

    std::ios::sync_with_stdio(false);

    cout.setf(ios::fixed);

    cout.precision(16);

    solve();

    return 0;

}
