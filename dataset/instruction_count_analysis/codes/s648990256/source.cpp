#pragma GCC optimize ("O3")

#pragma GCC target ("avx")



#include "stdc++.h"

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

}



signed main() {

  i64 h = io::scan();

  i64 n = io::scan();

  i64 s = 0;

  for (int i = 0; i < n; i++) {

    s += io::scan();

  }

  if (s >= h) {

    puts("Yes");

  } else {

    puts("No");

  }

  return 0;

}