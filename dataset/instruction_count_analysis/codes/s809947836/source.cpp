#include <stdio.h>

#include <stdlib.h>

#include <algorithm>

#include <map>

#include <utility>



#define MAX_N (40)

#define INF (1 << 30)



using namespace std;



void create_list(map<pair<int, int>, int> &m, int *as, int *bs, int *cs,

                 int n) {

  for (int k = 0; k < 1 << n; k++) {

    int a = 0, b = 0, c = 0;

    for (int l = 0; l < n; l++) {

      if (k & (1 << l)) {

        a += as[l];

        b += bs[l];

        c += cs[l];

      }

    }

    map<pair<int, int>, int>::iterator it = m.find(pair<int, int>(a, b));

    if (it != m.end()) {

      it->second = min(c, it->second);

    } else {

      m[pair<int, int>(a, b)] = c;

    }

  }

}



int main(int argc, char *argv[]) {

  // read inputs

  int N, Ma, Mb, as[MAX_N], bs[MAX_N], cs[MAX_N];

  scanf("%d %d %d", &N, &Ma, &Mb);

  for (int i = 0; i < N; i++) {

    scanf("%d %d %d", &as[i], &bs[i], &cs[i]);

  }



  // create list of (amount a, amount b) -> cost

  // that can be created by using the first 20 elements

  // and the rest

  const int N1 = N / 2, N2 = N - N1;

  map<pair<int, int>, int> m1, m2;

  create_list(m1, as, bs, cs, N1);

  create_list(m2, as + N1, bs + N1, cs + N1, N2);



  // iterate one of the lists and find its match in the other

  int ans = 1 << 30;

  for (map<pair<int, int>, int>::iterator it = m1.begin(), e = m1.end();

       it != e; ++it) {

    const int a = it->first.first, b = it->first.second, c = it->second;

    for (int i = 1; i <= N; i++) {

      // try to achieve (Ma * i, Mb * i)

      const int a2 = Ma * i - a, b2 = Mb * i - b;

      map<pair<int, int>, int>::iterator it2 = m2.find(pair<int, int>(a2, b2));

      if (it2 != m2.end()) {

        ans = min(ans, c + it2->second);

      }

    }

  }

  if (ans < INF) {

    printf("%d\n", ans);

  } else {

    printf("-1\n");

  }



  return 0;

}
