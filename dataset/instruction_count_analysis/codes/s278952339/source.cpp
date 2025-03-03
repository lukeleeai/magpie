#include<iostream>

#include<algorithm>

#include<vector>

#include<map>

#include<cstdint>





int64_t const MOD = 1e9+7;

int const MAXN = 2e5;

int N;



template<int64_t Prime>

struct mod_int {

  int64_t v_;

  mod_int(int64_t x=0) : v_(x) { normalize(); }

  void normalize() { ((v_ %= Prime) += Prime) %= Prime; }

  mod_int operator+=(mod_int const& r){ (v_ += r.v_) %= Prime; return *this; }

  mod_int operator-=(mod_int const& r){ (v_ += Prime - r.v_) %= Prime; return *this; }

  mod_int operator*=(mod_int const& r){ (v_ *= r.v_) %= Prime; return *this; }

  mod_int operator+(mod_int const& r) { mod_int res(*this); return res += r; }

  mod_int operator-(mod_int const& r) { mod_int res(*this); return res -= r; }

  mod_int operator*(mod_int const& r) { mod_int res(*this); return res *= r; }

  mod_int pow(int x) const {

    int64_t res = 1, v = v_;

    while(x > 0) {

      if(x&1) (res *= v) %= Prime;

      x/=2; (v *= v) %= Prime;

    }

    return mod_int(res);

  }

  mod_int inv() const { return pow(Prime-2); }

  //operator int64_t() const { return v_; }

};

typedef mod_int<MOD> mint;



std::vector<int> G[MAXN];



int nc[MAXN];

mint dfs1(int v, int p) {

  int num = 1;

  mint res;

  for(auto c: G[v]) if(c != p) {

    res += dfs1(c, v);

    num += nc[c];

  }

  res += (mint(2).pow(num)-1)*(mint(2).pow(N - num)-1);

  nc[v] = num;

  return res;

}



int main() {

  std::cin >> N;

  for(int i = 0; i < N-1; ++i) {

    int A, B; std::cin >> A >> B; --A; --B;

    G[A].push_back(B);

    G[B].push_back(A);

  }

  mint ans = (dfs1(0, -1) - 1)*mint(2).pow(N).inv();

  ans -= mint(N)*mint(2).inv() - 1;

  std::cout << ans.v_ << std::endl;

  return 0;

}


