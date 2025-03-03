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



int calc(int x1, int y1, int x2, int y2) {

  auto x = x2 - x1;

  auto y = y2 - y1;

  return mul(Q[x + y], mul(R[x], R[y]));

}



struct Cell {

  int x, y;

};



int main() {

  Q[0] = 1;

  for (auto i = 1; i < 200000; ++i)

    Q[i] = mul(Q[i - 1], i);

  R[199999] = pow(Q[199999], Mod - 2);

  for (auto i = 199999; i; --i)

    R[i - 1] = mul(R[i], i);

  int N, M, K;

  scanf("%d%d%d", &N, &M, &K);

  static Cell A[3001];

  for (auto i = 0; i < K; ++i)

    scanf("%d%d", &A[i].x, &A[i].y);

  sort(A, A + K, [](const Cell& a, const Cell& b) {

    return a.x != b.x ? a.x < b.x : a.y < b.y;

  });

  A[K] = {N, M};

  static int F[3001];

  for (auto i = 0; i <= K; ++i) {

    F[i] = calc(1, 1, A[i].x, A[i].y);

    for (auto j = 0; j < i; ++j)

      if (A[j].x <= A[i].x && A[j].y <= A[i].y)

        F[i] = sub(F[i], mul(F[j], calc(A[j].x, A[j].y, A[i].x, A[i].y)));

  }

  printf("%d\n", add(F[K], Mod));

  return 0;

}
