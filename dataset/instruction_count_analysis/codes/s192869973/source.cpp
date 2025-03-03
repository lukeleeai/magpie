#include <cstdio>

#include <algorithm>

using namespace std;



struct C {

  int id;

  int w;

  int s;

  static bool compare(const C &l, const C &r) {

    if (l.w > r.w) {

      return true;

    } else if (l.w < r.w) {

      return false;

    } else {

      return (l.s > r.s);

    }

  }

};



int main() {

  C c[10];

  char f[10][21];

  int n, tw, a[10];

  bool u[10];

  while (1) {

    scanf("%d", &n);

    if (!n) break;

    for (int i=0; i<n; i++) {

      c[i].id = i;

      scanf("%s %d %d", f[i], &c[i].w, &c[i].s);

    }

    sort(c, c+n, C::compare);

    tw = 0;

    for (int i=0; i<n; i++) {

      tw += c[i].w;

    }

    for (int i=0; i<n; i++) {

      u[i] = false;

    }

    for (int i=0; i<n; i++) {

      for (int j=0; j<n; j++) {

        if (!u[j] && tw - c[j].w <= c[j].s) {

          tw -= c[j].w;

          a[i] = c[j].id;

          u[j] = true;

          break;

        }

      }

    }

    for (int i=0; i<n; i++) {

      printf("%s\n", f[a[i]]);

    }

  }

  return 0;

}