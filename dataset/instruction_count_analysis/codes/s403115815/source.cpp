#include <iostream>

#include <algorithm>

#include <array>

#include <bitset>

#include <cassert>

#include <cstring>

#include <deque>

#include <functional>

#include <initializer_list>

#include <math.h>

#include <map>

#include <random>

#include <set>

#include <stack>

#include <tuple>

#include <type_traits>

#include <queue>

#include <vector>





#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))

#define rFOR(i, a, b) for(int (i) = (b); (i) >= (a); --(i))

#define REP(i, n) FOR(i, 0, n)

#define rREP(i, n) rFOR(i, 0, (n-1))

#define SORT(A) std::sort((A).begin(), (A).end())

#define ALL(A) (A).begin(), (A).end()

// 座標圧縮 (for vector) : ソートしてから使うのが一般的 ; SORT(A) => COORDINATE_COMPRESSION(A)

#define COORDINATE_COMPRESSION(A) (A).erase(unique((A).begin(),(A).end()),(A).end())



using lli = long long int;

using pii = std::pair<int, int>;



// グリッド上の縦横移動

constexpr std::array<std::pair<int, int>, 4> dxdy = {

    std::pair<int, int>( 1,  0),

    std::pair<int, int>(-1,  0),

    std::pair<int, int>( 0,  1),

    std::pair<int, int>( 0, -1)

};



void VintOut(std::vector<int>& A){

    const int n = A.size();

    if(n == 0){putchar('\n'); return;}

    printf("%d", A[0]);

    for(int i = 1; i < n; ++i) printf(" %d", A[i]);

    putchar('\n');

}

void VintOut(std::vector<long long int>& A){

    const int n = A.size();

    if(n == 0){ putchar('\n'); return;}

    printf("%lld", A[0]);

    for(int i = 1; i < n; ++i) printf(" %lld", A[i]);

    putchar('\n');

}



template <typename T>

inline bool chmin(T& a, T b){

    if(b < a){ a = b; return true;}

    return false;

}



template <typename T>

inline bool chmax(T& a, T b){

    if(a < b){ a = b; return true;}

    return false;

}



inline bool isIn(int x, int y, int H, int W){

    return 0 <= x and x < H and 0 <= y and y < W;

}

inline bool bitUP(int state, int k){ return (state >> k) & 1; }

inline bool bitUP(long long int state, int k){ return (state >> k) & 1;}



// z-algorithm

template <class T> std::vector<int> z_algorithm(const T &str) {

    const int n = str.size();

    std::vector<int> resOfCP(n); resOfCP[0] = n;

    int i = 1, j = 0;

    while (i < n) {

        while (i + j < n and str[j] == str[i + j]) ++j;

        resOfCP[i] = j;

        if (j == 0) { ++i; continue;}

        int k = 1;

        while (i + k < n and k + resOfCP[k] < j) resOfCP[i + k] = resOfCP[k], ++k;

        i += k; j -= k;

    }

    return resOfCP;

}





// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~







// 遅延伝搬セグメント木

template <typename element_t, typename operate_t, typename monoid_t>

class LazySegmentTree{

private:

    // データ群

    size_t size_;      // データのサイズ : 2のべき乗

    size_t height; // "木の高さ" : n = 2^height ≥ value.size

    std::vector<element_t> data;   // データの値本体

    std::vector<operate_t> lazy;   // 遅延評価の作用素

    std::vector<unsigned int> len; // len[i] = data[i], lazy[i]の指す区間の幅



    // 引数がサブタイプか判定する : virtualの関係でだめ

    //static_assert(std::is_base_of<Monoid_for_LazySegmentTree<element_t, operate_t>, monoid_t>::value, 

    //              "The third argument of LazySegmentTree must be a subtype of monoid_for_LazySegemnetTree"

    //             );



    // lazy[k]の情報を子ノードに伝搬, data[k]の評価を行う

    inline void eval(int k){

        if(lazy[k] == monoid_t::id_ope) return;

        if(k < size_){ // 2 * k + 1 < 2 * size_ : 配列内の参照か

            lazy[2 * k]     = monoid_t::updateOfOp(lazy[2 * k],     lazy[k]);

            lazy[2 * k + 1] = monoid_t::updateOfOp(lazy[2 * k + 1], lazy[k]);

        }

        data[k] = monoid_t::updateByOp(data[k], monoid_t::queryValueOfLazyValueAndLength(lazy[k], len[k]));

        lazy[k] = monoid_t::id_ope;

    }



    // 親ノードからlazyの値を遅延伝搬評価をする (全体に広げる) | トップダウン(lazyの伝搬)

    // -> 区間を完全平衡二分木とした時親から子ノードに向かって繋がっているノード全てにdataの評価, lazyの伝搬を行う

    inline void evalFromTheRoot(int k){

        for(int i = height; i > 0; --i) eval(k >> i);

    }



    // 子ノードから親ノードに向かってdataの値を計算する | ボトムアップ(dataの伝搬, 更新) | すでに伝搬はされていると仮定する

    inline void computeDataToTheRoot(int k) {

         while(k >>= 1) data[k] = monoid_t::queryE(reflect(2 * k), reflect(2 * k + 1));

    }

    // 遅延評価を含んだ値を返す

    element_t reflect(int k){

        if(lazy[k] == monoid_t::id_ope) return data[k];

        return monoid_t::updateByOp(data[k], monoid_t::queryValueOfLazyValueAndLength(lazy[k], len[k]));

    }

public:

    // コンストラクタ based on size

    LazySegmentTree(const size_t N){

        size_ = 1; height = 0; while(size_ < N){ size_ *= 2; ++height; }

        data.assign(2 * size_, monoid_t::id_ele);

        lazy.assign(2 * size_, monoid_t::id_ope);

        // 区間の幅を与える

        len.resize( 2 * size_);

        for(int level = 0; level <= height; ++level){

            int length = size_ >> level; // 高さ level における幅

            int rng    =   1   << level; // rng, rng + 1, ..., 2*rng - 1

            for(int x = 0; x < rng; ++x) len[x + rng] = length;

        }

    }

    // コンストラクタ based on size and value

    LazySegmentTree(const size_t N, const element_t init_val){

        size_ = 1; height = 0; while(size_ < N){ size_ *= 2; ++height; }

        data.assign(2 * size_, monoid_t::id_ele);

        lazy.assign(2 * size_, monoid_t::id_ope);

         // あらかじめ data の値を更新しておく

        for(int i = 0; i < N; ++i) data[i + size_] = init_val;

        for(int i = size_ - 1; i >= 0; --i) data[i] = monoid_t::queryE(data[2 * i], data[2 * i + 1]);

        // 区間の幅を与える

        len.resize( 2 * size_);

        for(int level = 0; level <= height; ++level){

            int length = size_ >> level; // 高さ level における幅

            int rng    =   1   << level; // rng, rng + 1, ..., 2*rng - 1

            for(int x = 0; x < rng; ++x) len[x + rng] = length;

        }

    }

    // コンストラクタ based on vector

	LazySegmentTree(const std::vector<element_t>& A) {

        const size_t N = A.size();

        size_ = 1; height = 0; while(size_ < N){ size_ *= 2; ++height; }

        data.assign(2 * size_, monoid_t::id_ele);

        lazy.assign(2 * size_, monoid_t::id_ope);

        // あらかじめ data の値を更新しておく

        for(int i = 0; i < N; ++i) data[i + size_] = A[i];

        for(int i = size_ - 1; i >= 0; --i) data[i] = monoid_t::queryE(data[2 * i], data[2 * i + 1]);

		// 区間の幅を与える

        len.resize( 2 * size_);

        for(int level = 0; level <= height; ++level){

            int length = size_ >> level; // 高さ level における幅

            int rng    =   1   << level; // rng, rng + 1, ..., 2*rng - 1

            for(int x = 0; x < rng; ++x) len[x + rng] = length;

        }

	}

    // 区間 [left, right) (0-indexed) に (遅延評価)作用素を与える

    inline void update(int left, int right, const operate_t& op){

        if(left >= right) return ;



        // ボトムアップに伝搬を伝える

        int l = left  + size_ ;    evalFromTheRoot(l);

        int r = right + size_ - 1; evalFromTheRoot(r);



        for(int ll = l, rr = r + 1; ll < rr; ll >>= 1, rr >>= 1){

            if(ll & 1){ 

                lazy[ll] = monoid_t::updateOfOp(lazy[ll], op); // eval(ll);

                ++ll;

            }

            if(rr & 1){ 

                --rr; 

                lazy[rr] = monoid_t::updateOfOp(lazy[rr], op); // eval(rr);

            }

        }

        computeDataToTheRoot(l); computeDataToTheRoot(r);

    }



    // 区間 [left, right) (0-indexed) の値を求める

    inline element_t query(int left, int right){



        if(left >= right) return monoid_t::id_ele;

        // ボトムアップに伝搬を伝える

        int l = left  + size_ ;    evalFromTheRoot(l);

        int r = right + size_ - 1; evalFromTheRoot(r);



        element_t vl = monoid_t::id_ele, vr = monoid_t::id_ele;

        for(int ll = l, rr = r + 1; ll < rr; ll >>= 1, rr >>= 1) {

            if (ll & 1) {

                vl = monoid_t::queryE(vl, 

                                     monoid_t::updateByOp(

                                                data[ll], 

                                                monoid_t::queryValueOfLazyValueAndLength(lazy[ll], len[ll])

                                                )

                                    ); 

                ++ll;

            }

            if (rr & 1) {

                --rr;

                vr = monoid_t::queryE( monoid_t::updateByOp( 

                                                data[rr], 

                                                monoid_t::queryValueOfLazyValueAndLength(lazy[rr], len[rr])

                                                ),

                                       vr

                                    ); 

            }

        }

        return monoid_t::queryE(vl, vr);

    }

};





constexpr lli inf = 1e18 + 334 + 810 + 1919 + 114514;



// 区間更新, 区間最小

struct Seg{

    static const lli id_ele;

    static const lli id_ope;

    static lli queryE(lli x, lli y){return x > y ? y : x;}

    static lli updateByOp(lli x, lli op){return x + op;}

    static lli updateOfOp(lli op1, lli op2){return op1 + op2;}

    static lli queryValueOfLazyValueAndLength(lli op1, int len){return op1;}

};

const lli Seg::id_ele = inf;

const lli Seg::id_ope = 0;

std::vector<std::pair<int, int>> A;

std::vector<lli> V;



int main(void){

    int n, d, a; scanf("%d%d%d", &n, &d, &a);

    A.resize(n); REP(i, n) scanf("%d%d", &A[i].first, &A[i].second);

    std::sort(A.begin(), A.end());

    V.resize(n);

    REP(i, n) V[i] = A[i].second;

    LazySegmentTree<lli, lli, Seg> Tree(V);

    int r = 0;

    lli res = 0;

    REP(i, n){

        while(r < n and A[r].first - A[i].first <= 2 * d) r++;

        lli t = Tree.query(i, i+1);

        if(t <= 0) continue;

        lli p = t / a; if(p * a < t) p++;

        Tree.update(i, r, -p * a);

        res += p;

    }

    printf("%lld\n", res);



    

    

    

    return 0;

}