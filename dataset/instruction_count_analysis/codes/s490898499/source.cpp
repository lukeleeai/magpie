// #include"stdc++.h"

#include<vector>

#include<iostream>

using namespace std;

// #pragma GCC optimize("-O3")



#ifndef ConanYu

#define CPPIO

#endif

#ifdef CPPIO

#define endl "\n"

#endif



#define push_back emplace_back

template<typename T>

class List : public vector<T>

{

public:

//  new

    template<typename... U>

    List(const U &... tail) : vector<T>(0)

    {

        pb(tail...);

    }



//  push_back

    void pb() {}

    template<typename... U>

    void pb(const T & head, const U &... tail)

    {

        this->push_back(head);

        pb(tail...);

    }



//print

    void print()

    {

        const int LEN = this->size();

        for (int i = 0; i < LEN; i++)

        {

            cout << (*this)[i] << (i == LEN - 1 ? '\n' : ' ');

        }

    }

};





typedef long long ll;

typedef pair<int, int>pii;

typedef pair<long long, long long>pll;

typedef long double ld;



pll exgcd(const long long x, const long long y)

{

    if (!y)

    {

        return make_pair(1, 0);

    }

    pll cur = exgcd(y, x % y);

    return make_pair(cur.second, cur.first - (x / y) * cur.second);

}



const long long __mod__ = 998244353;

long long mmod()

{

    return 1LL;

}

template <typename T, typename ...U>

long long mmod(const T &head, const U &... tail)

{

    return (head * mmod(tail...)) % __mod__;

}



long long mod(long long x, long long p = __mod__)

{

    return ((x % p) + p) % p;

}



void print() {}

template <typename T, typename... U>

void print(const T &head, const U &... tail)

{

    cout << head << (sizeof...(tail) ? ' ' : '\n');

    print(tail...);

}



#ifdef ConanYu

#define debug(...) print(__VA_ARGS__)

#else

#define debug(...) 0

#endif



inline long long fmul(long long a, long long c, const long long& Mod)

{

    a %= Mod, c %= Mod ;

    return (a * c - (long long)(((long double) a * c + 0.5) / Mod) * Mod) % Mod ;

}



long long gcd(long long x, long long y)

{

    return y == 0 ? x : gcd(y, x % y);

}



void solve();

int main()

{

#ifdef ConanYu

    freopen("test.txt", "r", stdin);

    // freopen("out.txt", "w", stdout);

    // freopen("2.in", "r", stdin);

    // freopen("2.out", "w", stdout);

    clock_t st = clock();

#endif



#ifdef CPPIO

    ios::sync_with_stdio(false);

    cin.tie(0);

    cout.tie(0);

#endif



    solve();



#ifdef ConanYu

    clock_t ed = clock();

    cerr << "time: " << ((ed - st) * 1.0 / CLOCKS_PER_SEC) << endl;

#endif

    return 0;

}



// *********************************************************************************************************



ll a[3333];

void solve()

{

    int n;

    cin >> n;

    int sum = 0;

    for(int i = 0; i < n; i++)

    {

        cin >> a[i];

        sum += a[i];

    }

    cout << (sum - n) << endl;

}
