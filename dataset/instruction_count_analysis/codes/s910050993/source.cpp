#include <algorithm>

#include <array>

#include <bitset>

#include <cctype>

#include <cinttypes>

#include <climits>

#include <cmath>

#include <complex>

#include <cstddef>

#include <cstdint>

#include <cstdio>

#include <cstdlib>

#include <cstring>

#include <ctime>

#include <deque>

#include <fstream>

#include <functional>

#include <iomanip>

#include <iostream>

#include <iterator>

#include <limits>

#include <list>

#include <map>

#include <memory>

#include <new>

#include <numeric>

#include <queue>

#include <random>

#include <set>

#include <sstream>

#include <stack>

#include <string>

#include <tuple>

#include <unordered_map>

#include <unordered_set>

#include <utility>

#include <vector>



using namespace std;



constexpr int Mod = 1000000007;



constexpr int add(int a, int b) { return (a + b) % Mod; }

constexpr int sub(int a, int b) { return (a - b) % Mod; }

constexpr int mul(int a, int b) { return (int) ((long long) a * b % Mod); }

constexpr int fma(int a, int b, int c) { return (int) (((long long) a * b + c) % Mod); }

constexpr int pow(int a, int b) {

  auto c = 1;

  while (b) {

    if (b & 1)

      c = mul(c, a);

    a = mul(a, a);

    b >>= 1;

  }

  return c;

}



int Q[200000];

int R[200000];



struct Cell { int x, y; };



void init(int N) {

  Q[0] = 1;

  for (auto i = 1; i <= N; ++i)

    Q[i] = mul(Q[i - 1], i);

  R[N] = pow(Q[N], Mod - 2);

  for (auto i = N; i; --i)

    R[i - 1] = mul(R[i], i);

}



int calc(const Cell& a, const Cell& b) {

  auto x = b.x - a.x;

  auto y = b.y - a.y;

  return mul(Q[x + y], mul(R[x], R[y]));

}



int main() {

  int N, M, K;

  scanf("%d%d%d", &N, &M, &K);

  init(max(N, M) * 2 - 1);

  static Cell A[3001];

  for (auto i = 0; i < K; ++i)

    scanf("%d%d", &A[i].x, &A[i].y);

  sort(A, A + K, [](const Cell& a, const Cell& b) {

    return a.x != b.x ? a.x < b.x : a.y < b.y;

  });

  A[K] = {N, M};

  static int F[3001];

  for (auto i = 0; i <= K; ++i) {

    F[i] = calc(Cell{1, 1}, A[i]);

    for (auto j = 0; j < i; ++j)

      if (A[j].x <= A[i].x && A[j].y <= A[i].y)

        F[i] = fma(-F[j], calc(A[j], A[i]), F[i]);

  }

  printf("%d\n", add(F[K], Mod));

  return 0;

}
