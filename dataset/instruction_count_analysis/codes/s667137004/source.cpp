#include "stdc++.h"

using namespace std;



map<long, long> pf(long n) {

  map<long, long> ma;

  for (long i = 2; i * i <= n; i++) {

    while (n % i == 0) ma[i]++, n /= i;

  }

  if (n != 1) ma[n]++;

  return ma;

}



int main() {

  cin.tie(nullptr);

  ios::sync_with_stdio(false);

  long N;

  cin >> N;

  vector<long> A(N);

  for (long i = 0; i < N; i++) cin >> A.at(i);

  sort(A.begin(), A.end());

  bool diff1 = 0;

  for (long i = 1; i < N; i++) {

    if (A.at(i) - A.at(i - 1) == 1) diff1 = 1;

  }



  bool B = 1;

  vector<long> cnt(1e6+1);

  for (auto a : A) {

    for (auto [b, c] : pf(a)) {

      if (cnt.at(b)) B = 0;

      cnt.at(b) += c;

    }

  }

  if (B) return cout << "pairwise coprime" << "\n", 0;



  long G = 0;

  for (long i = 0; i < N; i++) {

    G = gcd(G, A.at(i));

  }



  if (G == 1) return cout << "setwise coprime" << "\n", 0;



  cout << "not coprime" << "\n";

}
