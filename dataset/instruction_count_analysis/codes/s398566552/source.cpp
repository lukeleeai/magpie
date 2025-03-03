#include "stdc++.h"

#define loop for(;;)

typedef std::vector<long> LI;

template<typename T> void scan1(T& x) { fprintf(stderr, "unknown type\n"); }

template<> void scan1(long& x) { if( scanf("%ld", &x) < 0 ) exit(0); }

template<> void scan1(std::string& x) { if( not ( std::cin >> x ) ) exit(0); }

void scan() {}

template<typename Head, typename... Tail>

void scan(Head& x, Tail&... xs) {

  scan1(x); scan(xs...);

}



struct Solver {

   long memo[314][314];

   LI xs;

   long dfs(long left, long right) {

      if( memo[left][right] != -1 ) return memo[left][right];

      if( right - left <= 1 ) return 0;

      long res = 0;

      if( std::abs(xs[right-1] - xs[left]) <= 1 ) {

         long x = dfs(left + 1, right - 1);

         if( x == (right - 1) - (left + 1) ) {

            res = std::max(res, x + 2);

         }

      }

      for(long i = left + 1; i <= right - 1; ++i) {

         res = std::max(res, dfs(left, i) + dfs(i, right));

      }

      return memo[left][right] = res;

   }

   void solve() {

      long n; scan(n);

      if( n == 0 ) exit(0);

      xs.resize(n); for(long &x : xs) scan(x);

      init();

      printf("%ld\n", dfs(0, n));

   }

   void init() {

      for(long i = 0; i < 314; ++i) {

         for(long k = 0; k < 314; ++k) {

            memo[i][k] = -1;

         }

      }

   }

};



int main() {

   loop std::shared_ptr<Solver>(new Solver())->solve();

}