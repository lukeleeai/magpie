#include <iostream>

#include <algorithm>

#include <array>

#include <bitset>

#include <cassert>

#include <cstring>

#include <complex>

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



using lli = long long int;

using pii = std::pair<int, int>;



#define REP(i, n) for(int (i) = 0; (i) < (n); ++(i))



// グリッド上の縦横移動

constexpr std::array<std::pair<int, int>, 4> dxdy = {

    { {1, 0}, {-1, 0}, {0, 1}, {0, -1} }

};



template <typename T> inline bool chmin(T& a, const T b){ if(b < a){ a = b; return true; } return false; }

template <typename T> inline bool chmax(T& a, const T b){ if(a < b){ a = b; return true; } return false; }

template <typename T> inline bool bitUP(const T state, const unsigned int k) { return (state >> k) & 0b01; }



inline bool isIn(int x, int y, int H, int W){return 0 <= x and x < H and 0 <= y and y < W;}

inline auto isInTheGrid(const int H, const int W){

    return std::bind(isIn, std::placeholders::_1, std::placeholders::_2, H, W);

}



template <class element_t> 

std::vector<element_t> make_vector(const unsigned int n, const element_t& init_value){ return std::vector<element_t>(n, init_value); }

template <class element_t, class ...Tp>

auto make_vector(const unsigned int n, const unsigned int m, Tp... args){

    return std::vector<decltype(make_vector<element_t>(m, args...))>(n, make_vector<element_t>(m, args...));

}



namespace MyInputAndOutput{

    // 入力関係 (cin)

    class user_input{

    private:

        static constexpr unsigned int sizeOfAscii = 128;

        bool isBlankChar[sizeOfAscii];

            /*  < definition of getchar >

                reference

                MacOS   : https://developer.apple.com/library/archive/documentation/System/Conceptual/ManPages_iPhoneOS/man3/getchar.3.html

                Windows : https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/getchar-nolock-getwchar-nolock?view=vs-2019

                Linux   : https://linux.die.net/man/3/unlocked_stdio 

                Ubuntu  : http://manpages.ubuntu.com/manpages/trusty/man3/getchar_unlocked.3posix.html

            */

            #if defined(__APPLE__)

                #define DAGGER_GETCHAR_UNLOCKED_DAGGER getchar_unlocked

            #elif defined(_WIN32) || defined(_WIN64)

                #define DAGGER_GETCHAR_UNLOCKED_DAGGER _getchar_nolock

            #elif defined(__linux) 

                #if _POSIX_C_SOURCE >= 1 || _XOPEN_SOURCE || _POSIX_SOURCE || _BSD_SOURCE || _SVID_SOURCE

                    #define DAGGER_GETCHAR_UNLOCKED_DAGGER getchar_unlocked

                #else

                    #define DAGGER_GETCHAR_UNLOCKED_DAGGER getchar

                #endif

            #else

                #define DAGGER_GETCHAR_UNLOCKED_DAGGER getchar

            #endif

        // 符号あり整数を getchar で読み込んで構成する (もし, 0 ~ 9 以外の文字が含まれると困る)

        template <typename Tp>

        inline void charToInteger(Tp& val) const {

            val = 0; int c; while(true){

                c = DAGGER_GETCHAR_UNLOCKED_DAGGER();

                if(c == EOF) return;

                if('-' or (not isBlankChar[c])) break;

            }

            if(c == '-'){

                while(true){

                    c = DAGGER_GETCHAR_UNLOCKED_DAGGER();

                    if(c < '0' or c > '9') break;

                    val = 10 * val + c - '0';

                } val = -val;

            }

            else{

                if(c < '0' or c > '9') return;

                do{

                    val = 10 * val + c - '0';

                    c = DAGGER_GETCHAR_UNLOCKED_DAGGER();

                } while('0' <= c and c <= '9');

            }

        }

        // 符号なし整数を getchar で読み込んで構成する (もし, 符号付きだとバグる)

        template <typename Tp>

        inline void charToUnsignedInteger(Tp& val) const {

            val = 0; int c; while(true){

                c = DAGGER_GETCHAR_UNLOCKED_DAGGER();

                if(c == EOF) return;

                if(not isBlankChar[c]) break;

            }

            if(c < '0' or c > '9') return;

            do{

                val = 10 * val + c - '0';

                c = DAGGER_GETCHAR_UNLOCKED_DAGGER();

            } while(not (c == EOF or isBlankChar[c]));

        }

    public:

        constexpr user_input(void) : isBlankChar(){

            for(unsigned int i = 0; i < sizeOfAscii; ++i) isBlankChar[i] = false;

            isBlankChar[int('\n')] = true; isBlankChar[int('\t')] = true; 

            isBlankChar[int(' ')]  = true; isBlankChar[int('\v')] = true;

        }

        inline const user_input& operator >> (int& int_arg) const {

            //scanf("%d", &int_arg);

            charToInteger<int>(int_arg); return *this;

        }

        inline const user_input& operator >> (long long int& llint_arg) const {

            //scanf("%lld", &llint_arg); return *this;

            charToInteger<long long int>(llint_arg); return *this;

        }

        inline const user_input& operator >> (unsigned int& uint_arg) const {

            //scanf("%u", &uint_arg); 

            charToUnsignedInteger<unsigned int>(uint_arg); return *this;

        }

        inline const user_input& operator >> (unsigned long long int& ullint_arg) const {

            //scanf("%llu", &ullint_arg);

            charToUnsignedInteger<unsigned long long int>(ullint_arg); return *this;

        }

        inline const user_input& operator >> (unsigned long& ulint_arg) const {

            charToUnsignedInteger<unsigned long>(ulint_arg); return *this;

        }

        inline const user_input& operator >> (float& float_arg) const {

            scanf("%f", &float_arg); return *this;

        }

        inline const user_input& operator >> (double& double_arg) const {

            scanf("%lf", &double_arg); return *this;

        }

        inline const user_input& operator >> (long double& ldouble_arg) const {

            scanf("%Lf", &ldouble_arg); return *this;

        }

        inline const user_input& operator >> (char* str_arg) const {

            scanf("%s", str_arg); 

            return *this;

        }

        inline const user_input& operator >> (char& char_arg) const {

            do{

                if((char_arg = DAGGER_GETCHAR_UNLOCKED_DAGGER()) == EOF) return *this;

            } while(isBlankChar[int(char_arg)]);

            return *this;

        }

        inline const user_input& operator >> (std::string& str_arg) const {

            str_arg.erase();

            int c; while(true){ 

                c = DAGGER_GETCHAR_UNLOCKED_DAGGER();

                if(c == EOF) return *this;

                if(not isBlankChar[c]) break;

            }

            constexpr unsigned int buffer_size = 128; 

            char buffer_input[buffer_size]; unsigned int buffer_length = 0;

            do{

                buffer_input[buffer_length++] = c;

                if(buffer_length == buffer_size){

                    buffer_length = 0; str_arg.append(buffer_input, buffer_size);

                }

                c = DAGGER_GETCHAR_UNLOCKED_DAGGER();

            } while(c != EOF and (not isBlankChar[c]) );

            str_arg.append(buffer_input, buffer_length);

            return *this;

        }

        template <typename S, typename T>

        inline const user_input& operator >>(std::pair<S, T>& pair_arg) const{

            (*this) >> pair_arg.first >> pair_arg.second; return *this;

        }

        template <typename T>

        inline const user_input& operator >>(std::vector<T>& vec) const {

            for(T& ele : vec) (*this) >> ele; 

            return *this;

        }

        // getchar の define の解除

        #undef DAGGER_GETCHAR_UNLOCKED_DAGGER

    }; constexpr user_input cin;



    void ends(void) {putchar('\0'); }

    void endl(void) {putchar('\n'); fflush(stdout);}

    void flush(void) {fflush(stdout);}

    constexpr char eol = '\n';



    // 出力関係 (cout)

    class user_output{

    public:

        constexpr user_output(void){}

        inline const user_output& operator << (const int int_arg) const{

            printf("%d", int_arg); return *this;

        }

        inline const user_output& operator << (const unsigned int uint_arg) const{

            printf("%u", uint_arg); return *this;

        }

        inline const user_output& operator << (const long long int llint_arg) const {

            printf("%lld", llint_arg); return *this;

        }

        inline const user_output& operator << (const unsigned long long int ullint_arg) const {

            printf("%llu", ullint_arg); return *this;

        }

        inline const user_output& operator << (const unsigned long ulint_arg) const {

            printf("%lu", ulint_arg); return *this;

        }

        inline const user_output& operator << (const float flt_arg) const {

            printf("%.16f", flt_arg); return *this;

        }

        inline const user_output& operator << (const double ld_arg) const {

            printf("%.16lf", ld_arg); return *this;

        }

        inline const user_output& operator << (const long double ld_arg) const {

            printf("%.16Lf", ld_arg); return *this;

        }

        inline const user_output& operator << (const char char_arg) const {

            putchar(char_arg); return *this;

        }

        inline const user_output& operator << (const unsigned char uchar_arg) const {

            putchar(uchar_arg); return *this;

        }

        inline const user_output& operator << (const char* str_arg) const {

            fputs(str_arg, stdout); return *this;

        }

        inline const user_output& operator << (const std::string& str_arg) const {

            fputs(str_arg.c_str(), stdout); return *this;

        }

        inline const user_output& operator << (void(* const func_arg)(void)) const {

            func_arg(); return *this;

        }

        template <typename S, typename T>

        inline const user_output& operator <<(const std::pair<S, T>& pair_arg) const{

            (*this) << pair_arg.first << ' ' << pair_arg.second; return *this;

        }

        template <typename Tp_name>

        inline const user_output& operator << (const std::vector<Tp_name>& vec) const {

            const size_t size_of_vec = vec.size();

            if(size_of_vec <= 0) return *this;

            (*this) << vec[0]; 

            for(size_t index = 1; index < size_of_vec; ++index) (*this) << ' ' << vec[index];

            return *this;

        }

    }; constexpr user_output cout;



    // その他出力関数

    void binary_output(int64_t value, size_t length = 64){

        char out[length + 1];

        for(size_t i = 0; i < length; ++i) out[length - 1 - i] = ((value >> i) & 1) ? '1' : '0';

        out[length] = '\0'; puts(out);

    }

    template <typename InputType>

    void print(InputType first, InputType last, const char separate_c = ' ', const char end_c = '\n'){

        InputType it = first;

        while(true){

            MyInputAndOutput::cout << *it;

            if(++it == last){MyInputAndOutput::cout << end_c; return;}

            MyInputAndOutput::cout << separate_c;  

        }

    }

}; namespace MIO = MyInputAndOutput;



// z-algorithm

template <class T> std::vector<unsigned int> z_algorithm(const T &str) {

    const size_t n = str.size();

    std::vector<unsigned int> resOfCP(n); resOfCP[0] = n;

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



using MIO::cin; using MIO::cout; using MIO::eol;







// 全方位木DPクラス : build関数を忘れないこと！

template <class reroot_structure_type> 

class ReRooting{

private:

    const unsigned int n;       // 頂点の数

    const unsigned int theRoot; // 根



    using element_t = typename reroot_structure_type::element_t;

    using weight_t  = typename reroot_structure_type::weight_t;

    // 辺の型

    struct edge_t{

        unsigned int to;  // 頂点

        weight_t weight; // 辺の重み

        edge_t( const unsigned int to = 0, 

                const weight_t& weight = reroot_structure_type::id_weight())

                : to(to), weight(weight){}

    };



    std::vector<element_t> dp;

    std::vector<std::vector<edge_t>> edge;  // 枝集合

    std::vector<unsigned int> order;        // 計算順序 (DFSの順序が格納されている)

    std::vector<unsigned int> parent;       // 親ノード

    std::vector<std::vector<element_t>> SL; // 左累積和

    std::vector<std::vector<element_t>> SR; // 右累積和

    

    // DFS で 全ての頂点の深さを計算する & 計算順序を構成

    void make_order(void){

        std::vector<bool> yet(n, true);

        order.resize(n); parent.resize(n); 



        std::vector<unsigned int> stk; stk.reserve(n);

        unsigned int idx = 0;

        yet[theRoot] = false;

        stk.emplace_back(theRoot); order[idx++] = theRoot;

        while(not stk.empty()){

            unsigned int v = stk.back(); stk.pop_back();

            for(const edge_t& x : edge[v]) if(yet[x.to]){

                yet[x.to] = false;

                parent[x.to] = v; order[idx++] = x.to;

                stk.emplace_back(x.to);

            }

        }

    }

    void dfs(void){

        dp.assign(n, reroot_structure_type::id_merge());

        SL.assign(n, std::vector<element_t>(0)); SR.assign(n, std::vector<element_t>(0));

        for(unsigned int i = 0; i < n; ++i){

            SL[i].reserve(edge[i].size()); SR[i].reserve(edge[i].size());

        }



        for(unsigned int i = n - 1; i > 0; --i){

            const unsigned int v = order[i]; const unsigned int nv = parent[v];

            dp[v]  = reroot_structure_type::update(dp[v]);

            SL[nv].push_back(dp[v]); SR[nv].push_back(dp[v]);

            dp[nv] = reroot_structure_type::merge(dp[v], dp[nv]);

        }



        {

            const unsigned int v = order[0];

            const unsigned int sz = SL[v].size();

            dp[v] = reroot_structure_type::update(dp[v]);

            element_t vl = reroot_structure_type::id_merge(), vr = reroot_structure_type::id_merge();

            for(unsigned int j1 = 0, j2 = sz - 1; j1 < sz; ++j1, --j2){

                SR[v][j1] = reroot_structure_type::merge(SR[v][j1], vr); std::swap(SR[v][j1], vr);

                SL[v][j2] = reroot_structure_type::merge(vl, SL[v][j2]); std::swap(SL[v][j2], vl);

            }

            unsigned int idx = sz - 1;

            for(const edge_t& x : edge[v]){

                const element_t tmp = reroot_structure_type::update(reroot_structure_type::merge(SL[v][idx], SR[v][idx]));

                dp[x.to] = reroot_structure_type::merge(tmp, dp[x.to]);

                SL[x.to].push_back(tmp); SR[x.to].push_back(tmp);

                --idx;

            }

        }

        for(unsigned int i = 1; i < n; ++i){

            const unsigned int v = order[i];

            const unsigned int sz = SL[v].size();

            // dp[v] = reroot_structure_type::update(dp[v]);

            element_t vl = reroot_structure_type::id_merge(), vr = reroot_structure_type::id_merge();

            for(unsigned int j1 = 0, j2 = sz - 1; j1 < sz; ++j1, --j2){

                SR[v][j1] = reroot_structure_type::merge(SR[v][j1], vr); std::swap(SR[v][j1], vr);

                SL[v][j2] = reroot_structure_type::merge(vl, SL[v][j2]); std::swap(SL[v][j2], vl);

            }

            dp[v] = reroot_structure_type::update(vl);

            unsigned int idx = sz - 2;

            for(const edge_t& x : edge[v]) if(x.to != parent[v]){

                const element_t tmp = reroot_structure_type::update(reroot_structure_type::merge(SL[v][idx], SR[v][idx]));

                dp[x.to] = reroot_structure_type::merge(tmp, dp[x.to]);

                SL[x.to].push_back(tmp); SR[x.to].push_back(tmp);

                --idx;

            }

        }

    }

    /*

    void dfs2(void){

        for(unsigned int i = 0; i < n; ++i){

            const unsigned int v = order[i]; unsigned int idx = 0;

            for(const edge_t& x : edge[v]) if(x.to != parent[v]){

                const element_t&& tmp1 = reroot_structure_type::merge(SL[v][idx], SR[v][idx]);

                const element_t&& tmp2 = reroot_structure_type::update(tmp1);

                const element_t&& tmp3 = reroot_structure_type::add_weight(tmp2, x.weight);

                cout << v << " -> " << x.to << " : " << tmp3.first.val << " , " << tmp3.second.val << eol;

                dp[x.to] = reroot_structure_type::merge(dp[x.to], tmp2);

                idx++;

            }

        }





        // 右累積和 (i, size) を計算

                SR[v][sz - 1] = reroot_structure_type::id_merge(); 

                for(unsigned int j1 = sz - 2, j2 = sz - 1; j2 > 0; --j1, --j2){

                    SR[v][j1] = reroot_structure_type::merge(SL[v][j2], SR[v][j2]);

                }

                // 左累積和 [0, i) を計算

                for(unsigned int j = 0; j < sz; ++j){

                    std::swap(dp[v], SL[v][j]); dp[v] = reroot_structure_type::merge(SL[v][j], dp[v]);

                }

    }

    */



public:

    ReRooting(const unsigned int n, const unsigned int theRoot = 0):n(n), theRoot(theRoot){ edge.assign(n, std::vector<edge_t>(0)); }

    // (u - v) の無向辺 の 追加 (0-index)

    inline void add(const unsigned int u, const unsigned int v, const weight_t& weight = reroot_structure_type::id_weight()){

        edge[u].emplace_back(v, weight);

    }

    // 実行

    inline void build(void){ make_order(); dfs(); }

    inline const element_t& operator [](const unsigned int idx) const { return dp[idx]; }

};



template <unsigned int modulus> struct modint{

    static_assert(modulus > 0, "modulus must be a positive integer.");

    int val; // 値本体



    // コンストラクタ

    constexpr modint():val(0){}

    template <class T> constexpr modint(T v):val(){

        val = v % (int)(modulus); 

        if(val < 0) val += modulus;

    }

    constexpr modint& operator+= (const modint<modulus> other) noexcept {

        val += other.val; if(val >= modulus) val -= modulus;

        return *this;

    }

    constexpr modint& operator -= (const modint<modulus> other) noexcept {

        val -= other.val; if(val < 0) val += modulus;

        return *this;

    }

    constexpr modint& operator *= (const modint<modulus> other) noexcept {

        val = (unsigned long long int)(val) * other.val % modulus;

        return *this; 

    }

    constexpr modint& operator /= (const modint<modulus> other) noexcept {

        val = (unsigned long long int)(val) * other.inverse() % modulus;

        return *this;

    }

    constexpr modint operator +(const modint<modulus> v)const noexcept{

        return modint<modulus>(*this) += v;

    }

    constexpr modint operator -(const modint<modulus> v)const noexcept{

        return modint<modulus>(*this) -= v;

    }

    constexpr modint operator *(const modint<modulus> v)const noexcept{

        return modint<modulus>(*this) *= v;

    }

    constexpr modint operator /(const modint<modulus> v)const noexcept{

        return modint<modulus>(*this) /= v;

    }

    constexpr modint& operator ++(void) noexcept {

        if(++val == modulus) val = 0;

        return *this;

    }

    constexpr modint& operator --(void) noexcept {

        if(val-- == 0) val = modulus - 1;

        return *this;

    }

    constexpr modint operator -()const noexcept{

        return modint<modulus>((val == 0 ? 0 : modulus - val));

    }



    // aの逆元を求める関数

    constexpr unsigned int inverse(unsigned int a) const noexcept {

        unsigned int b = modulus;

                 int u = 1,   v = 0;

        while (b != 0) {

            unsigned int t = a / b; 

            a -= t * b; std::swap(a, b);

            u -= t * v; std::swap(u, v);

        }

        if(u < 0) u += modulus;

        return u;

    }

    constexpr unsigned int inverse(void) const noexcept {return inverse(val);}

    // a^nを返す関数 : nは負の数でも可

    constexpr unsigned int power(unsigned long long int a, long long int n)const noexcept{

        if(n == 0) return 1;

        unsigned long long res = 1, waiting = a;

        if(n < 0) waiting = inverse(), n = -n;

        while(n != 0){ 

            if((n & 1UL) != 0){ res *= waiting; res %= modulus; }

            waiting *= waiting; waiting %= modulus; 

            n /= 2;

        }

        return res;

    }

    constexpr unsigned int power(long long int n) const noexcept {return power(val, n);}

};



template <std::size_t N, unsigned int modulus>

struct combinationMod{

public:

    modint<modulus> Power[N + 1];

    modint<modulus> powInverse[N + 1];

    modint<modulus> inverse[N + 1];

//public:

    constexpr combinationMod(void): Power(), powInverse(), inverse(){

        Power[0] = 1;

        int x = 0; modint<modulus> mx;

        for(x = 1, mx = 1; x <= N; ++x, ++mx) Power[x] = Power[x - 1] * mx;

        powInverse[N] = Power[N].inverse();

        for(x = N, mx = N; x > 0; --x, --mx){

            powInverse[x - 1] = powInverse[x] * mx;

            inverse[x] = powInverse[x] * Power[x - 1];

        }

        inverse[0] = 1;

    }

    constexpr modint<modulus> combination(int n, int k) const {

        if(k < 0 or n < k) return modint<modulus>();

        return Power[n] * powInverse[k] * powInverse[n - k];

    }

};



constexpr unsigned int mod = 1000'000'007;

constexpr unsigned int N = 200'000;

using mint = modint<mod>;

const combinationMod<N, mod> Cmb;



class reroot_structure{

public:

    using element_t = std::pair<mint, mint>; // 各頂点の情報(DP)

    using weight_t = char; // 辺の重み



    // (子ノードのdp値) x (親ノードへの辺の重み) → dp値への寄与

    static element_t add_weight(const element_t& child_dp, const weight_t& weight){ return child_dp; }

    // 上の重みを付け加えて伝搬する関数の 重みの単位元

    static constexpr weight_t id_weight(void){ return EOF; }



    // (各子ノードのdp値の寄与)をマージする関数 (二項演算)

    static element_t merge(const element_t& child_dp1, const element_t& child_dp2){

        const mint count = child_dp1.second + child_dp2.second;

        return element_t(child_dp1.first * child_dp2.first * Cmb.combination(count.val, child_dp2.second.val), count);

    }

    // 上のマージ関数の単位元

    static constexpr element_t id_merge(void){

        return element_t(mint(1), mint(0));

    }



    // 頂点

    static constexpr element_t update(const element_t& dp_value){

        return element_t(dp_value.first, dp_value.second + mint(1));

    }

};





int main(void){

    unsigned int n; cin >> n;

    ReRooting<reroot_structure> RRT(n);

    for(unsigned int i = 1; i < n; ++i){

        unsigned int u, v; cin >> u >> v; --u; --v;

        RRT.add(u, v); RRT.add(v, u);

    }

    RRT.build();

    for(unsigned int i = 0; i < n; ++i) cout << RRT[i].first.val << eol;

    



    return 0;

}