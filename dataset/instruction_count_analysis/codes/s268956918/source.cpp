#pragma GCC optimize ("O3")

#include "stdc++.h"

typedef long double ld;



using namespace std;



const int N = 105;



struct Pt {

  ld x, y, ang;

  Pt(ld _x=0, ld _y=0): x(_x), y(_y), ang(atan2(_y, _x)){

    if(ang < 0) ang += 2 * M_PI;

  };

  Pt operator+(const Pt &a) const {

    return Pt(x+a.x, y+a.y);

  }

  Pt operator-(const Pt &a) const {

    return Pt(x-a.x, y-a.y);

  }

  Pt operator*(const ld &a) const {

    return Pt(x*a, y*a);

  }

  Pt operator/(const ld &a) const {

    return Pt(x/a, y/a);

  }

  ld operator*(const Pt &a) const {

    return x*a.x + y*a.y;

  }

  ld operator^(const Pt &a) const {

    return x*a.y - y*a.x;

  }

  bool operator<(const Pt& ret) const {

    return ang < ret.ang;

  }

};

ld norm2(const Pt &a) {

  return a*a;

}

ld norm(const Pt &a) {

  return sqrt(norm2(a));

}



int n;

Pt dp[N];

vector<Pt> v;



void init() {

  cin >> n;

  for(int i = 0 ; i < n ; ++i) {

    ld x, y; cin >> x >> y;

    v.push_back(Pt(x, y));

  }

}

void solve() {

  sort(v.begin(), v.end());

  dp[0] = {0, 0};

  Pt ans = {0, 0};

  for(int i = 1 ; i <= n ; ++i) {

    dp[i] = {0, 0};

    for(int j = 0 ; j < i ; ++j) {

      Pt x = dp[j] + v[i - 1];

      if(norm(x) > norm(dp[i])) dp[i] = x;

    }

    if(norm(dp[i]) > norm(ans)) ans = dp[i];

  }

  reverse(v.begin(), v.end());

  for(int i = 1 ; i <= n ; ++i) {

    dp[i] = {0, 0};

    for(int j = 0 ; j < i ; ++j) {

      Pt x = dp[j] + v[i - 1];

      if(norm(x) > norm(dp[i])) dp[i] = x;

    }

    if(norm(dp[i]) > norm(ans)) ans = dp[i];

  }

  int cnt = 5000;

  while(cnt--) {

    random_shuffle(v.begin(), v.end());

    for(int i = 1 ; i <= n ; ++i) {

      dp[i] = {0, 0};

      for(int j = 0 ; j < i ; ++j) {

        Pt x = dp[j] + v[i - 1];

        if(norm(x) > norm(dp[i])) dp[i] = x;

      }

      if(norm(dp[i]) > norm(ans)) ans = dp[i];

    }

  }

  cout << fixed << setprecision(15) << norm(ans) << '\n';

}



int32_t main() {

  ios_base::sync_with_stdio(0), cin.tie(0);

  init();

  solve();

}
