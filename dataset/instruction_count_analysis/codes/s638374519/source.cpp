/**

 * 

 */



// #include {{{

#include <algorithm>

#include <array>

#include <bitset>

#include <cassert>

#include <cfloat>

#include <cmath>

#include <cstdint>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <ctime>

#include <deque>

#include <forward_list>

#include <functional>

#include <iomanip>

#include <iostream>

#include <fstream>

#include <sstream>

#include <iterator>

#include <limits>

#include <list>

#include <map>

#include <numeric>

#include <queue>

#include <random>

#include <regex>

#include <set>

#include <stack>

#include <string>

#include <tuple>

#include <type_traits>

#include <unordered_map>

#include <unordered_set>

#include <utility>

#include <vector>



#ifdef DEBUG

#include <fmt/format.h>

#include <fmt/ostream.h>

#endif



using namespace std;

// }}}



// type {{{

using  s8 =   int8_t;

using  u8 =  uint8_t;

using s16 =  int16_t;

using u16 = uint16_t;

using s32 =  int32_t;

using u32 = uint32_t;

using s64 =  int64_t;

using u64 = uint64_t;



template<typename T>

using max_heap = priority_queue<T, vector<T>, less<T>>;

template<typename T>

using min_heap = priority_queue<T, vector<T>, greater<T>>;

// }}}



// hide {{{

#ifdef __clang__

#pragma clang diagnostic push

#pragma clang diagnostic ignored "-Wunused-const-variable"

#endif

// }}}



// ???????????´

//#define int s64



constexpr bool AUTOFLUSH = false;



constexpr bool STDIO_ENABLE = false;



constexpr int IOS_PREC = 10;



constexpr int INF_S32 =             1'010'000'000;

constexpr s64 INF_S64 = 1'010'000'000'000'000'000LL;



constexpr auto   INF = INF_S64;

constexpr double EPS = 1e-9;



constexpr s64 MOD = 1'000'000'007;



// hide {{{

#ifdef __clang__

#pragma clang diagnostic pop

#endif

// }}}



// util {{{

template<typename T>

constexpr bool is_odd(T x)

{

    return x % 2 != 0;

}



template<typename T>

constexpr bool is_even(T x)

{

    return x % 2 == 0;

}



template<typename T>

constexpr int cmp(T x, T y)

{

    return (x > y) - (x < y);

}



template<typename T>

constexpr int sgn(T x)

{

    return cmp(x, T(0));

}



template<typename T>

constexpr T ipow(T a, T b)

{

    assert(b >= 0);

    T res(1);

    for(T i = 0; i < b; ++i)

        res *= a;

    return res;

}



template<

    typename T,

    std::enable_if_t<

        std::is_integral<T>::value &&

        std::is_signed<T>::value, std::nullptr_t> = nullptr>

constexpr T div_ceil(T a, T b)

{

    return a/b + (((a<0)^(b>0)) && (a%b));

}



template<

    typename T,

    std::enable_if_t<

        std::is_integral<T>::value &&

        std::is_unsigned<T>::value, std::nullptr_t> = nullptr>

constexpr T div_ceil(T a, T b)

{

    return a/b + !!(a%b);

}



template<

    typename T,

    std::enable_if_t<

        std::is_integral<T>::value &&

        std::is_signed<T>::value, std::nullptr_t> = nullptr>

constexpr T div_floor(T a, T b)

{

    return a/b - (((a>0)^(b>0)) && (a%b));

}



template<

    typename T,

    std::enable_if_t<

        std::is_integral<T>::value &&

        std::is_unsigned<T>::value, std::nullptr_t> = nullptr>

constexpr T div_floor(T a, T b)

{

    return a/b;

}



template<typename T>

constexpr typename enable_if<is_signed<T>::value,T>::type modulo(T a, T b)

{

    assert(b > 0);

    T r = a % b;

    return r >= 0 ? r : r+b;

}



template<typename T>

constexpr T clamp(T x, T lo, T hi)

{

    assert(lo <= hi);

    if(x < lo)

        return lo;

    else if(x > hi)

        return hi;

    else

        return x;

}



int sqrti(int x)

{

    assert(x >= 0);

    return static_cast<int>(sqrt(x));

}



s64 sqrtl(s64 x)

{

    assert(x >= 0);

    return static_cast<s64>(sqrt(x));

}



template<typename T>

bool chmax(T& xmax, const T& x)

{

    if(x > xmax) {

        xmax = x;

        return true;

    }

    else {

        return false;

    }

}



template<typename T>

bool chmin(T& xmin, const T& x)

{

    if(x < xmin) {

        xmin = x;

        return true;

    }

    else {

        return false;

    }

}



template<typename T>

constexpr int SIZE(const T& c)

{

    return static_cast<int>(c.size());

}



template<typename T, size_t N>

constexpr int SIZE(const T (&)[N])

{

    return static_cast<int>(N);

}



template<typename InputIt, typename T>

int argfind(InputIt first, InputIt last, const T& x)

{

    auto it = find(first, last, x);

    return distance(first, it);

}



template<typename InputIt>

int argmax(InputIt first, InputIt last)

{

    auto it = max_element(first, last);

    return distance(first, it);

}



template<typename InputIt>

int argmin(InputIt first, InputIt last)

{

    auto it = min_element(first, last);

    return distance(first, it);

}



template<typename InputIt>

bool alltrue(InputIt first, InputIt last)

{

    return all_of(first, last, [](bool b) { return b; });

}



template<typename InputIt>

bool anytrue(InputIt first, InputIt last)

{

    return any_of(first, last, [](bool b) { return b; });

}



template<typename InputIt>

bool allfalse(InputIt first, InputIt last)

{

    return !anytrue(first, last);

}



template<typename InputIt>

bool anyfalse(InputIt first, InputIt last)

{

    return !alltrue(first, last);

}



template<typename T>

array<pair<T,T>,4> neighbor4(const T& x, const T& y)

{

    return array<pair<T,T>,4> {{

                    { x, y-1 },

        { x-1, y },             { x+1, y },

                    { x, y+1 },

    }};

}



template<typename T>

array<pair<T,T>,8> neighbor8(const T& x, const T& y)

{

    return array<pair<T,T>,8> {{

        { x-1, y-1 }, { x, y-1 }, { x+1, y-1 },

        { x-1, y   },             { x+1, y   },

        { x-1, y+1 }, { x, y+1 }, { x+1, y+1 },

    }};

}



template<typename T>

bool in_bounds(const T& x, const T& minx, const T& maxx)

{

    return !(x < minx) && !(maxx < x);

}



template<typename T>

bool in_bounds_2(

    const T& x,    const T& y,

    const T& minx, const T& miny,

    const T& maxx, const T& maxy)

{

    return in_bounds(x, minx, maxx) && in_bounds(y, miny, maxy);

}



template<typename T>

bool in_bounds_wh(const T& x, const T& y, const T& w, const T& h)

{

    return in_bounds_2(x, y, 0, 0, w-1, h-1);

}



struct pairhash {

    template<typename T1, typename T2>

    size_t operator()(const pair<T1,T2>& p) const

    {

        size_t ans = 17;

        ans = 31*ans + hash<T1>()(p.first);

        ans = 31*ans + hash<T2>()(p.second);

        return ans;

    }

};



template<typename K, typename V>

pair<typename map<K,V>::iterator, bool> insert_or_assign(map<K,V>& m, const K& k, const V& v)

{

    auto it = m.lower_bound(k);

    if(it != end(m) && !m.key_comp()(k,it->first)) {

        it->second = v;

        return make_pair(it, false);

    }

    else {

        auto it_ins = m.insert(it, make_pair(k,v));

        return make_pair(it_ins, true);

    }

}



template<typename K, typename V>

pair<typename unordered_map<K,V>::iterator, bool>

insert_or_assign(unordered_map<K,V>& m, const K& k, const V& v)

{

    auto it = m.find(k);

    if(it != end(m)) {

        it->second = v;

        return make_pair(it, false);

    }

    else {

        auto it_ins = m.insert(it, make_pair(k,v));

        return make_pair(it_ins, true);

    }

}



template<typename T>

string TO_STRING(const T& x)

{

    ostringstream out;

    out << x;

    return out.str();

}



template<typename InputIt>

string JOIN(InputIt first, InputIt last, const string& sep)

{

    ostringstream out;

    while(first != last) {

        out << *first++;

        if(first != last)

            out << sep;

    }

    return out.str();

}



template<typename InputIt>

auto SUM(InputIt first, InputIt last)

{

    using T = typename iterator_traits<InputIt>::value_type;

    return accumulate(first, last, T());

}



template<typename T>

void UNIQ(T& c)

{

    c.erase(unique(begin(c), end(c)), end(c));

}



template<typename T, typename F>

enable_if_t<rank<T>::value==0> ARRAY_FOREACH(T& e, F f)

{

    f(e);

}



template<typename Array, typename F>

enable_if_t<rank<Array>::value!=0> ARRAY_FOREACH(Array& ary, F f)

{

    for(auto& e : ary)

        ARRAY_FOREACH(e, f);

}



template<typename Array, typename U>

enable_if_t<rank<Array>::value!=0> ARRAY_FILL(Array& ary, const U& v)

{

    ARRAY_FOREACH(ary, [&v](auto& elem) { elem = v; });

}



template<typename T, typename C>

T POP(stack<T,C>& stk)

{

    T x = stk.top(); stk.pop();

    return x;

}



template<typename T, typename C>

T POP(queue<T,C>& que)

{

    T x = que.front(); que.pop();

    return x;

}



template<typename T, typename Cont, typename Cmp>

T POP(priority_queue<T,Cont,Cmp>& que)

{

    T x = que.top(); que.pop();

    return x;

}



template<typename T>

void RD(T& x)

{

    cin >> x;

#ifdef DEBUG

    if(!cin) assert(false);

#endif

}



// ?????? {{{

// FPRINTSEQ {{{

template<typename InputIt>

ostream& FPRINTSEQ(ostream& out, InputIt first, InputIt last)

{

    for(InputIt it = first; it != last; ++it) {

        if(it != first) out << ' ';

        out << *it;

    }

    return out;

}

template<typename InputIt>

ostream& PRINTSEQ(InputIt first, InputIt last)

{

    return FPRINTSEQ(cout, first, last);

}

template<typename InputIt>

ostream& DPRINTSEQ(InputIt first, InputIt last)

{

    return FPRINTSEQ(cerr, first, last);

}

// }}}



// 1?¬????????????? {{{

template<typename T, size_t N>

ostream& FPRINTARRAY1(ostream& out, const T (&c)[N])

{

    return FPRINTSEQ(out, cbegin(c), cend(c));

}

template<typename T, size_t N>

ostream& PRINTARRAY1(const T (&c)[N])

{

    return FPRINTARRAY1(cout, c);

}

template<typename T, size_t N>

ostream& DPRINTARRAY1(const T (&c)[N])

{

    return FPRINTARRAY1(cerr, c);

}

// }}}



// 2?¬????????????? {{{

template<typename T, size_t N1, size_t N2>

ostream& FPRINTARRAY2(ostream& out, const T (&c)[N1][N2])

{

    out << '\n';

    for(const auto& e : c) {

        FPRINTARRAY1(out, e) << '\n';

    }

    return out;

}

template<typename T, size_t N1, size_t N2>

ostream& PRINTARRAY2(const T (&c)[N1][N2])

{

    return FPRINTARRAY2(cout, c);

}

template<typename T, size_t N1, size_t N2>

ostream& DPRINTARRAY2(const T (&c)[N1][N2])

{

    return FPRINTARRAY2(cerr, c);

}

// }}}



// ???map???????????? {{{

template<typename T>

ostream& operator<<(ostream& out, const vector<T>& c)

{

    return FPRINTSEQ(out, cbegin(c), cend(c));

}



// ?????\??±???

template<typename T>

ostream& operator<<(ostream& out, const vector<vector<T>>& c)

{

    out << '\n';

    for(const auto& e : c) {

        out << e << '\n';

    }

    return out;

}



// ?????\??±???

ostream& operator<<(ostream& out, const vector<string>& c)

{

    out << '\n';

    for(const string& e : c) {

        out << e << '\n';

    }

    return out;

}



template<typename T>

ostream& operator<<(ostream& out, const deque<T>& c)

{

    return FPRINTSEQ(out, cbegin(c), cend(c));

}



template<typename T>

ostream& operator<<(ostream& out, const list<T>& c)

{

    return FPRINTSEQ(out, cbegin(c), cend(c));

}



template<typename T>

ostream& operator<<(ostream& out, const forward_list<T>& c)

{

    return FPRINTSEQ(out, cbegin(c), cend(c));

}



template<typename T>

ostream& operator<<(ostream& out, const set<T>& c)

{

    return FPRINTSEQ(out, cbegin(c), cend(c));

}



template<typename T>

ostream& operator<<(ostream& out, const unordered_set<T>& c)

{

    return out << set<T>(cbegin(c), cend(c));

}



template<typename T>

ostream& operator<<(ostream& out, const multiset<T>& c)

{

    return FPRINTSEQ(out, cbegin(c), cend(c));

}



template<typename T>

ostream& operator<<(ostream& out, const unordered_multiset<T>& c)

{

    return out << multiset<T>(cbegin(c), cend(c));

}



template<typename T, size_t N>

ostream& operator<<(ostream& out, const array<T,N>& c)

{

    return FPRINTSEQ(out, cbegin(c), cend(c));

}

// }}}



// map???????????? {{{

template<typename InputIt>

ostream& FPRINTMAP(ostream& out, InputIt first, InputIt last)

{

    out << "{\n";

    for(auto it = first; it != last; ++it) {

        out << "  " << it->first << " : " << it->second << '\n';

    }

    out << "}\n";

    return out;

}

template<typename InputIt>

ostream& PRINTMAP(InputIt first, InputIt last)

{

    return FPRINTMAP(cout, first, last);

}

template<typename InputIt>

ostream& DPRINTMAP(InputIt first, InputIt last)

{

    return FPRINTMAP(cerr, first, last);

}



template<typename K, typename V>

ostream& operator<<(ostream& out, const map<K,V>& c)

{

    return FPRINTMAP(out, cbegin(c), cend(c));

}



template<typename K, typename V>

ostream& operator<<(ostream& out, const unordered_map<K,V>& c)

{

    return out << map<K,V>(cbegin(c), cend(c));

}



template<typename K, typename V>

ostream& operator<<(ostream& out, const multimap<K,V>& c)

{

    return FPRINTMAP(out, cbegin(c), cend(c));

}



template<typename K, typename V>

ostream& operator<<(ostream& out, const unordered_multimap<K,V>& c)

{

    return out << multimap<K,V>(cbegin(c), cend(c));

}

// }}}



// stack/queue/priority_queue {{{

template<typename T, typename C>

ostream& operator<<(ostream& out, stack<T,C> c)

{

    while(!c.empty()) {

        out << c.top();

        c.pop();

        if(!c.empty()) out << ' ';

    }

    return out;

}



template<typename T, typename C>

ostream& operator<<(ostream& out, queue<T,C> c)

{

    while(!c.empty()) {

        out << c.front();

        c.pop();

        if(!c.empty()) out << ' ';

    }

    return out;

}



template<typename T, typename Cont, typename Cmp>

ostream& operator<<(ostream& out, priority_queue<T,Cont,Cmp> c)

{

    while(!c.empty()) {

        out << c.top();

        c.pop();

        if(!c.empty()) out << ' ';

    }

    return out;

}

// }}}



// pair/tuple {{{

template<typename T1, typename T2>

ostream& operator<<(ostream& out, const pair<T1,T2>& p)

{

    return out << '(' << p.first << ',' << p.second << ')';

}



template<typename Tuple, size_t Pos>

ostream& FPRINTTUPLE(ostream& out, const Tuple&)

{

    return out;

}



template<typename Tuple, size_t Pos, typename T, typename... TS>

ostream& FPRINTTUPLE(ostream& out, const Tuple& t)

{

    if(Pos != 0)

        out << ',';

    out << get<Pos>(t);

    return FPRINTTUPLE<Tuple,Pos+1,TS...>(out, t);

}



template<typename... TS>

ostream& operator<<(ostream& out, const tuple<TS...>& t)

{

    out << '(';

    FPRINTTUPLE<tuple<TS...>,0,TS...>(out, t);

    out << ')';

    return out;

}

// }}}



// PRINT {{{

ostream& FPRINT(ostream& out) { return out; }



template<typename T, typename... TS>

ostream& FPRINT(ostream& out, const T& x, const TS& ...args)

{

    out << x;

    if(sizeof...(args))

        out << ' ';

    return FPRINT(out, args...);

}



template<typename... TS>

ostream& FPRINTLN(ostream& out, const TS& ...args)

{

    FPRINT(out, args...);

    return out << '\n';

}



template<typename... TS>

ostream& PRINT(const TS& ...args)

{

    return FPRINT(cout, args...);

}



template<typename... TS>

ostream& PRINTLN(const TS& ...args)

{

    return FPRINTLN(cout, args...);

}



template<typename... TS>

ostream& DPRINT(const TS& ...args)

{

    return FPRINT(cerr, args...);

}



template<typename... TS>

ostream& DPRINTLN(const TS& ...args)

{

    return FPRINTLN(cerr, args...);

}

// }}}

// }}}



void FLUSH()

{

    if(STDIO_ENABLE)

        fflush(stdout);

    else

        cout.flush();

}



[[noreturn]] void EXIT()

{

#ifdef DEBUG

    fflush(stdout);

    fflush(stderr);

    cout.flush();

    cerr.flush();

#else

    FLUSH();

#endif

    //quick_exit(0); // does not work on codeforces

    _Exit(0);

}



struct IoInit {

    IoInit()

    {

#ifndef DEBUG

        cin.tie(nullptr);

        if(!STDIO_ENABLE)

            ios::sync_with_stdio(false);

#endif

        cout << fixed << setprecision(IOS_PREC);



        if(AUTOFLUSH) {

            if(STDIO_ENABLE)

                setvbuf(stdout, nullptr, _IONBF, 0);

            cout << unitbuf;

        }

    }

} IOINIT;



#define FOR(i, start, end) for(s64 i = (start); i < (end); ++i)

#define REP(i, n) FOR(i, 0, n)



#define ALL(f,c,...) (([&](decltype((c)) cc) { return (f)(begin(cc), end(cc), ## __VA_ARGS__); })(c))



#define GENERIC(f) ([](auto&&... args) -> decltype(auto) { return (f)(forward<decltype(args)>(args)...); })



#define MEMSET(a,v) memset((a), (v), sizeof(a))



#define DBG(x) DPRINTLN('L', __LINE__, ':', #x, ':', (x))

// }}}



s64 N;

s64 C;



vector<s64> V;

vector<s64> W;



bool done[101][10001];

s64  memo[101][10001];



// i???????????§??§??????j?????¨??????????°???????

s64 f(s64 i, s64 j)

{

    if(j == 0) return 0;

    if(i == 0 && j != 0) return INF;



    if(!done[i][j]) {

        int v = V[i-1];

        int w = W[i-1];



        memo[i][j] = f(i-1,j);



        if(j >= v)

            chmin(memo[i][j], w+f(i-1,j-v));



        done[i][j] = true;

    }



    return memo[i][j];

}



void solve()

{

    s64 ans = 0;

    REP(j, 10001) {

        if(f(N,j) <= C)

            chmax(ans, j);

    }



    PRINTLN(ans);



#ifdef DEBUG

    deque<bool> use(N, false);



    for(int i=N, j=ans; i > 0; --i) {

        int v = V[i-1];

        if(j < v || f(i,j) == f(i-1,j)) {

            ;

        }

        else {

            use[i-1] = true;

            j -= v;

        }

    }

    DBG(use);



    assert(ALL(inner_product, use, begin(V), 0) == ans);

#endif

}



signed main(signed /*argc*/, char** /*argv*/)

{

    RD(N);

    V.resize(N);

    W.resize(N);

    RD(C);



    REP(i, N) {

        RD(V[i]);

        RD(W[i]);

    }



#ifdef DEBUG

    

#endif



    solve();



    EXIT();

}