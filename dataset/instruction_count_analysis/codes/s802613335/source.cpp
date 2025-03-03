#include <vector>

#include <bitset>

#include <iostream>



using B = std::bitset<32>;



int main()

{

  int N;

  std::cin >> N;

  int S[500000];

  for(int i = 0; i < N; ++i) {

    char c;

    std::cin >> c;

    S[i] = 1 << (c - 'a');

  }

  int Q;

  std::cin >> Q;

  while (Q--) {

    int q;

    std::cin >> q;

    if (q == 1) {

      int i;

      char c;

      std::cin >> i >> c;

      S[i - 1] = 1 << (c - 'a');

    } else {

      int r, l;

      std::cin >> r >> l;

      --r;

      int res{};

      for (int i = r; i < l; ++i) {

          res |= S[i];

      }

      B ans(res);

      std::cout << ans.count() << '\n';

    }

  }

  return 0;

}