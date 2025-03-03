#include <stdio.h>

#include <string.h>



char s[5001], t[6], c[5];

int k, n, l[6], i, j;

inline void findstr(const int x) {

  for (i = l[x]; i < n - x;) {

    for (j = 0; j <= x; ++j) {

      if (s[i + j] != t[j]) goto cont;

    }

    l[x + 1] = i;

    return;

  cont:

    ++i;

  }

  l[x + 1] = -1;

}

int main() {

  scanf("%s", s);

  scanf("%d", &k);

  n = strlen(s);

  for (c[0] = 'a'; c[0] <= 'z'; ++c[0]) {

    t[0] = c[0];

    findstr(0);

    if (l[1] < 0) continue;

    if (k == 1) {

      printf("%s\n", t);

      return 0;

    }

    --k;

    for (c[1] = 'a'; c[1] <= 'z'; ++c[1]) {

      t[1] = c[1];

      findstr(1);

      if (l[2] < 0) continue;

      if (k == 1) {

        printf("%s\n", t);

        return 0;

      }

      --k;

      for (c[2] = 'a'; c[2] <= 'z'; ++c[2]) {

        t[2] = c[2];

        findstr(2);

        if (l[3] < 0) continue;

        if (k == 1) {

          printf("%s\n", t);

          return 0;

        }

        --k;

        for (c[3] = 'a'; c[3] <= 'z'; ++c[3]) {

          t[3] = c[3];

          findstr(3);

          if (l[4] < 0) continue;

          if (k == 1) {

            printf("%s\n", t);

            return 0;

          }

          --k;

          for (c[4] = 'a'; c[4] <= 'z'; ++c[4]) {

            t[4] = c[4];

            findstr(4);

            if (l[5] < 0) continue;

            if (k == 1) {

              printf("%s\n", t);

              return 0;

            }

            --k;

          }

          t[4] = 0;

        }

        t[3] = 0;

      }

      t[2] = 0;

    }

    t[1] = 0;

  }

}
