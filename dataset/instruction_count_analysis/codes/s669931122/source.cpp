#include <cstdio>

#include <algorithm>

#include <functional>

#include <set>

using namespace std;



using i32 = int;

using i64 = long long;



#define REP(i, stop) for (register int i = 0; i < stop; ++i)



template<typename T>

T read() {

  T a = 0;

  register int c;

  for(;;) {

    c = getchar_unlocked();

    if (c & 16) {

      a = a * 10 + c - 48;

    } else {

      return a;

    }

  }

}



void writeln(i64 a) {

  char buf[20];

  register int i = 0;

  // if (a <= 0)

  while (a > 0) {

    buf[i++] = a % 10;

    a = a / 10;

  }

  while (i > 0) {

    putchar_unlocked(buf[--i] + 48);

  }

  putchar_unlocked('\n');

}



i64 A[1000], B[1000], C[1000];

i64 ABC[3000];

signed main() {

  i32 X = read<i32>(),

      Y = read<i32>(),

      Z = read<i32>(),

      K = read<i32>();

  REP(i, X) A[i] = read<i64>();

  REP(i, Y) B[i] = read<i64>();

  REP(i, Z) C[i] = read<i64>();

  sort(A, A + X, greater<i64>());

  sort(B, B + Y, greater<i64>());

  sort(C, C + Z, greater<i64>());

  i64 A0 = A[0],

      B0 = B[0],

      C0 = C[0];

  REP(i, X) A[i] = A0 - A[i];

  REP(i, Y) B[i] = B0 - B[i];

  REP(i, Z) C[i] = C0 - C[i];

  i64 l = 0,

      r = A0 + B0 + C0,

      m;

  while (l < r) {

    m = (l + r) / 2;

    i32 cnt = 0;

    REP(i, X) {

      if (A[i] > m) break;

      REP(j, Y) {

        if (A[i] + B[j] > m) break;

        REP(k, Z) {

          if (A[i] + B[j] + C[k] > m) break;

          ++cnt;

          if (cnt >= K) {

            r = m;

            goto NEXT;

          }

        }

      }

    }

    l = m + 1;

    NEXT:;

  }

  i32 c = 0;

  REP(i, X) {

    if (A[i] >= l) break;

    REP(j, Y) {

      if (A[i] + B[j] >= l) break;

      REP(k, Z) {

        if (A[i] + B[j] + C[k] >= l) break;

        ABC[c++] = A[i] + B[j] + C[k];

      }

    }

  }

  sort(ABC, ABC + c);

  REP(i, c) {

    writeln(A0 + B0 + C0 - ABC[i]);

  }

  REP(_, K - c) {

    writeln(A0 + B0 + C0 - l);

  }

}