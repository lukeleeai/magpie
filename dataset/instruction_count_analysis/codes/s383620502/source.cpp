#define _USE_MATH_DEFINES

#include <cassert>

#include <cstdio>

#include <cstring>

#include <iostream>

#include <string>

#include <sstream>

#include <vector>

#include <queue>

#include <stack>

#include <list>

#include <set>

#include <map>

#include <unordered_set>

#include <unordered_map>

#include <algorithm>

#include <complex>

#include <cmath>

#include <numeric>

#include <bitset>



using namespace std;



#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)

template <typename Arg1>

void __f(const char* name, Arg1&& arg1){

  cerr << name << ": " << arg1 << endl;

}

template <typename Arg1, typename... Args>

void __f(const char* names, Arg1&& arg1, Args&&... args){

  const char* comma = strchr(names + 1, ',');

  cerr.write(names, comma - names) << ": " << arg1 << " |";

  __f(comma + 1, args...);

}



typedef long long int64;

typedef pair<int, int> ii;

const int INF = 1 << 30;

const int MOD = 1e9 + 7;



struct Frac {

  int64 p, q;

};



Frac operator -(const Frac& a, const Frac& b) {

  int64 p = a.p * b.q - a.q * b.p;

  int64 q = a.q * b.q;

  int64 d = abs(__gcd(p, q));

  p /= d; q /= d;

  return Frac{p, q};

}



int main() {

  int n;

  cin >> n;

  for (int i = 1; i <= 3500; ++i) {

    for (int j = 1; j <= 3500; ++j) {

      auto cur = Frac{4, n} - Frac{1, i} - Frac{1, j};

      if (cur.p == 1) {

        cout << i << " " << j << " " << cur.q << endl;

        return 0;

      }

    }

  }

  return 0;

}
