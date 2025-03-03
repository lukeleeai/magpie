#include <iostream>

#include <type_traits>

#include <vector>

#include <cstdint>

#include <cassert>

#include <numeric>

#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_A"



using i32   = int32_t;

using i64   = int64_t;

using u32   = uint32_t;

using u64   = uint64_t;

using uint  = unsigned int;

using usize = std::size_t;

using ll    = long long;

using ull   = unsigned long long;

using ld    = long double;

template<typename T, usize n>

using arr = T (&)[n];

template<typename T, usize n>

using c_arr = const T (&)[n];

template<typename T>

T in()

{

    T v;

    return std::cin >> v, v;

}

template<typename T, typename Uint, usize n, usize i>

T in_v(typename std::enable_if<(i == n), c_arr<Uint, n>>::type) { return in<T>(); }

template<typename T, typename Uint, usize n, usize i>

auto in_v(typename std::enable_if<(i < n), c_arr<Uint, n>>::type& szs)

{

    const usize s = (usize)szs[i];

    std::vector<decltype(in_v<T, Uint, n, i + 1>(szs))> ans(s);

    for (usize j = 0; j < s; j++) { ans[j] = in_v<T, Uint, n, i + 1>(szs); }

    return ans;

}

template<typename T, typename Uint, usize n>

auto in_v(c_arr<Uint, n> szs) { return in_v<T, Uint, n, 0>(szs); }

template<typename... Types>

auto in_t() { return std::tuple<std::decay_t<Types>...>{in<Types>()...}; }



template<typename T>

void out(const T& v) { std::cout << v; }

template<typename T>

void out(const std::vector<T>& v)

{

    for (usize i = 0; i < v.size(); i++) {

        if (i > 0) { std::cout << ' '; }

        out(v[i]);

    }

    std::cout << "\n";

}

template<typename T1, typename T2>

void out(const std::pair<T1, T2>& v) { out(v.first), std::cout << ' ', out(v.second); }

template<typename T, typename... Args>

void out(const T& v, const Args... args) { out(v), std::cout << ' ', out(args...); }

template<typename... Args>

void outln(const Args... args) { out(args...), std::cout << '\n'; }

template<typename... Args>

void outel(const Args... args) { out(args...), std::cout << std::endl; }



class unionfind

{

public:

    unionfind(const usize sz) : sz{sz}, rt(sz), comp_sz(sz, 1) { std::iota(rt.begin(), rt.end(), 0); }

    usize root_of(const usize a) { return assert(a < sz), rt[a] == a ? a : rt[a] = root_of(rt[a]); }

    bool unite(usize a, usize b)

    {

        assert(a < sz), assert(b < sz), a = root_of(a), b = root_of(b);

        if (a == b) { return false; }

        if (comp_sz[a] < comp_sz[b]) { std::swap(a, b); }

        return comp_sz[a] += comp_sz[b], rt[b] = a, true;

    }

    usize size_of(const usize a) { return assert(a < sz), comp_sz[root_of(a)]; }

    friend std::ostream& operator<<(std::ostream& os, const unionfind& uf)

    {

        os << "[";

        for (usize i = 0; i < uf.sz; i++) { os << uf.rt[i] << (i + 1 == uf.sz ? "" : ","); }

        return (os << "]\n");

    }



private:

    const usize sz;

    std::vector<usize> rt, comp_sz;

};

int main()

{

    const auto n = in<usize>();

    const auto q = in<usize>();

    unionfind uf(n);

    for (usize i = 0; i < q; i++) {

        const auto c = in<usize>();

        const auto u = in<usize>() ;

        const auto v = in<usize>() ;

        if (c == 0) {

            uf.unite(u, v);

        } else {

            outln(uf.root_of(u) == uf.root_of(v));

        }

    }

    return 0;

}


