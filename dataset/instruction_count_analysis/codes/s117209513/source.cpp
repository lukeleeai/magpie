#pragma GCC optimize ("O3")

#pragma GCC target ("avx")



#include <cstdio>

#include <cstdint>

#include <unistd.h>



using i64 = std::uint_fast32_t;



namespace io {

  constexpr int is = 1 << 17;

  char ib[is], *ip = ib + is, it;

  inline char getc() {

    if (ip == ib + is) { read(STDIN_FILENO, ib, is); ip = ib; }

    return *ip++;

  }

  inline i64 scan() {

    i64 r = 0;

    if (ip + 16 > ib + is) while ((it = getc()) & 16) r = r * 10 + it - '0';

    else while ((it = *ip++) & 16) r = r * 10 + it - '0';

    return r;

  }

  constexpr int os = 1 << 17;

  char ob[os], *op = ob, ot;

  inline void putc(const char c) {

    *op++ = c;

    if (op == ob + os) { write(STDOUT_FILENO, ob, os); op = ob; }

  }

  /* x shoud be greater than or equal to zero */

  inline void print(i64 x) {

    char d[20];

    int i = 0;

    while (true) {

      d[i] = x % 10 + 48;

      x /= 10;

      ++i;

      if (x <= 0) break;

    }

    while (i--) {

      putc(d[i]);

    }

  }

  inline void flush() {

    write(STDOUT_FILENO, ob, op - ob);

  }

}



signed main() {

  using namespace io;

  i64 h = scan();

  i64 n = scan();

  i64 s = 0;

  for (int i = 0; i < n; i++) {

    s += scan();

  }

  if (s >= h) {

    puts("Yes");

  } else {

    puts("No");

  }

  return 0;

}