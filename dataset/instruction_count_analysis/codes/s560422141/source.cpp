#include "stdc++.h"

using namespace std;



int main() {

  cin.tie(nullptr);

  ios_base::sync_with_stdio(false);

  

  int N;

  cin >> N;

  vector<int> A(N);

  for (int i = 0; i < N; i++) cin >> A.at(i);



  int G = 0;

  for (auto a : A) G = gcd(G, a);

  if (G > 1) return cout << "not coprime" << "\n", 0;



  auto pf = [&](long n) {

    map<long, int> ret;

    for (long i = 2; i * i <= n; i++) {

      while (n % i == 0) ret[i]++, n /= i;

    }

    if (n != 1) ret[n]++;

    return ret;

  };



  vector<bool> B(1e6+1);

  for (int i = 0; i < N; i++) {

    for (auto [a, b] : pf(A.at(i))) {

      if (B.at(a)) return cout << "setwise coprime" << "\n", 0;

      else B.at(a) = true;

    }

  }

  cout << "pairwise coprime" << "\n";

}