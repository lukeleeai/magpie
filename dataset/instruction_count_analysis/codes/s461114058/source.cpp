#include <vector>

#include <bitset>

#include <cstdio>



using B = std::bitset<32>;



int main()

{

  int N;

  scanf("%d\n", &N);

  int S[500000];

  for(int i = 0; i < N; ++i) {

    char c;

    scanf("%c", &c);

    S[i] = 1 << (c - 'a');

  }

  int Q;

  scanf("\n%d\n", &Q);

  while (Q--) {

    int q;

    scanf("%d ", &q);

    if (q == 1) {

      int i;

      char c;

      scanf("%d %c\n", &i, &c);

      S[i - 1] = 1 << (c - 'a');

    } else {

      int r, l;

      scanf("%d %d\n", &r, &l);

      --r;

      int res{};

      for (int i = r; i < l; ++i) {

          res |= S[i];

      }

      B ans(res);

      printf("%d\n", ans.count());

    }

  }

  return 0;

}
