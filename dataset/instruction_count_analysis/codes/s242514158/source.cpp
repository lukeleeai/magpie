#include <cstdio>

#include "stdc++.h"



using namespace std;



int main() {

  int N, M;

  scanf("%d%d", &N, &M);

  char S[100000], T[100000];

  scanf("%s%s", S, T);

  

  // 最大公約数を計算

  int g = __gcd(N, M);

  int stepS = N / g;

  int stepT = M / g;

  for (int i = 0; i < g; ++i) {

    if (S[stepS * i] != T[stepT * i]) {

      cout << -1 << '\n';

      return 0;

    }

  }

  cout << (long long) N / g * M << '\n';

  return 0;

}
