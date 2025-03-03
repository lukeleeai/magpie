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



// x未満の要素の数を返す

template<typename T>

i64 count_less(const vector<T> &v, T x){

    return lower_bound(begin(v),end(v),x)-begin(v);

}



// x以下の要素の数を返す

template<typename T>

i64 count_less_or_equal(const vector<T> &v, T x){

    return upper_bound(begin(v),end(v),x)-begin(v);

}



// xより大きい要素の数を返す

template<typename T>

i64 count_greater(const vector<T> &v, T x){

    return end(v)-upper_bound(begin(v),end(v),x);

}



// x以上の要素の数を返す

template<typename T>

i64 count_greater_or_equal(const vector<T> &v, T x){

    return end(v)-lower_bound(begin(v),end(v),x);

}



constexpr int inf = 1.01e9;

constexpr i64 inf64 = 4.01e18;

constexpr double eps = 1e-9;



template <class T, T op(T, T)>

class segtree {

public:

    int n, size_;

    vector<T> dat;

    T id_;

    segtree() = default;

    segtree(int size, T id, T initial_value) { init(size, id, initial_value); }

    void init(int size, T id, T initial_value) {

        size_ = size;

        id_ = id;

        n = 1;

        while (n < size) n *= 2;

        dat.assign(2 * n - 1, id);

        for (int i = 0; i < size; ++i) update(i, initial_value);

    }

    int size() const { return size_; }

    void update(int k, T a) {

        k += n - 1;  // leaf

        dat[k] = a;

        while (k > 0) {

            k = (k - 1) / 2;

            dat[k] = op(dat[k * 2 + 1], dat[k * 2 + 2]);

        }

    }

    T at(int index) { return dat[index + n - 1]; }

    void add(int k, T a) { update(k, at(k) + a); }

    T query(int a, int b) { return query(a, b, 0, 0, n); }

    T query(int a, int b, int k, int l, int r) {

        if (r <= a or b <= l) return id_;

        if (a <= l and r <= b) return dat[k];

        int m = (l + r) / 2;

        return op(query(a, b, k * 2 + 1, l, m), query(a, b, k * 2 + 2, m, r));

    }

};



i64 add(i64 a, i64 b){

    return a+b;

};



void solve() {

    constexpr i64 mod = 998244353;



    i64 N;

    cin >> N;



    vector<pair<i64,i64>> xy(N);

    rep(i,0,N) cin >> xy[i].first >> xy[i].second;



    sort(begin(xy),end(xy));



    vector<i64> xs,ys;

    rep(i,0,N){

        xs.emplace_back(xy[i].first);

        ys.emplace_back(xy[i].second);

    }

    sort(begin(xs),end(xs));

    sort(begin(ys),end(ys));



    vector<i64> dcmp;

    rep(i,0,N) dcmp.emplace_back(xy[i].second);

    sort(begin(dcmp), end(dcmp));

    dcmp.erase(unique(begin(dcmp), end(dcmp)), end(dcmp));



    map<i64,i64> cmp;

    rep(i, 0, dcmp.size()) cmp[dcmp[i]]=i;



    constexpr i64 maxn=200000;

    vector<fp<mod>> pow2(maxn+1);

    pow2[0]=1;

    rep(i,1,pow2.size()) pow2[i]=pow2[i-1]*2;



    segtree<i64,add> left_seg(dcmp.size(), 0, 0),right_seg(dcmp.size(), 0, 0);

    rep(i,0,xy.size()){

        i64 yi=cmp[xy[i].second];

        right_seg.add(yi,1);

    }

    auto left_it=xy.begin(),right_it=xy.begin();



    fp<mod> ans=0;

    rep(i,0,N){

        i64 x=xy[i].first,y=xy[i].second;

        i64 yi=cmp[y];



        while(left_it!=xy.end() && left_it->first<x){

            left_seg.add(cmp[left_it->second],1);

            ++left_it;

        }



        while(right_it!=xy.end() && right_it->first<=x){

            right_seg.add(cmp[right_it->second],-1);

            ++right_it;

        }



        // i番目の点を含まない長方形の個数

        fp<mod> sum=0;



        // left

        {

            sum+=pow2[count_less(xs,x)]-1;

        }



        //right

        {

            sum+=pow2[count_greater(xs,x)]-1;

        }



        // up

        {

            sum+=pow2[count_greater(ys,y)]-1;

        }



        // down

        {

            sum+=pow2[count_less(ys,y)]-1;

        }



        // left & up

        {

            sum-=pow2[left_seg.query(yi+1, dcmp.size())] - 1;

        }



        // left & down

        {

            sum-=pow2[left_seg.query(0,yi)]-1;

        }



        // right & up

        {

            sum-=pow2[right_seg.query(yi+1,dcmp.size())]-1;

        }



        // right & down

        {

            sum-=pow2[right_seg.query(0,yi)]-1;

        }



        ans+=pow2[N]-sum-1;

    }



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
