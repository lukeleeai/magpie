    #include <iostream>

    #include <vector>

    #include <algorithm>

    #include <map>

    #include <functional>

     

    int main() {

      size_t n;

      std::cin >> n;

     

      // std::map<int, int, std::greater<int>> v[2];  // (出現数, 要素)

      // 出現数の降順で並んでほしいです．冷静に考えてこれ map で

      // 持つ必要無くないですか？ vector に突っ込んでいい気がする

      // というかそうしないとだめで，同じ出現数の要素が複数あるときにこわれる．

      // multimap というものがあって云々？

      std::vector<std::pair<int, int>> v[2];

      {

        std::map<int, int> tmp[2];  // (要素, 出現数)

        for (size_t i=0; i<n; i+=2)

          for (size_t j=0; j<2; ++j) {

            int v_i;

            std::cin >> v_i;

            ++tmp[j][v_i];

          }

        for (size_t j=0; j<2; ++j) {

          for (const auto& p: tmp[j])

            v[j].emplace_back(p.second, p.first);

          std::sort(v[j].begin(), v[j].end(), std::greater<>());

        }

      }

     

      // 偶奇で分けたとき，各々のうちで最も多く出現する値とその数（へのイテレータ）

      // *f0 の型は std::pair<int, int> のはず

      auto f0=v[0].begin();

      auto f1=v[1].begin();

     

      if (v[0].size() == 1 && v[1].size() == 1) {

        // 各グループの種類数がどちらも 1 のとき

        if (f0->second == f1->second) {

          // それらが同じなら半分を変える必要があります

          std::cout << n/2 << std::endl;

        } else {

          // 異なっていれば何も変える必要がありません

          std::cout << "0\n";

        }

        return 0;

      }

     

      if (f0->second != f1->second) {

        // 最も多く出現する値が異なっていれば，それら以外を変えます

        std::cout << n-(f0->first+f1->first) << std::endl;

        return 0;

      }

     

      // どちらも同じ場合はどうしますか？

      // 出現数が少ない方は二番目に多く出現する値に変えます

      auto g0=std::next(f0);  // vector になったので，ここは

      auto g1=std::next(f1);  // gi=fi+1 でいいですね

      if (f0->first != f1->first) {

        // 要素数が 1 のとき，std::next(foo.begin()) の要素を取得することは

        // できませんが，今回は問題設定の関係からそうした状況は避けられます．

        // 要素数が 1 だった場合，出現数は n/2 のはずで，相手のグループがそれを

        // 上回ることはできないからです．

        if (f0->first > f1->first) {

          std::cout << n-(f0->first+g1->first) << std::endl;

        } else {

          std::cout << n-(g0->first+f1->first) << std::endl;

        }

        return 0;

      }

     

      // タイの場合はどうしますか？

      // 二番目に多く出現する値の出現数が大きい方のグループは，

      // その値に変えることにし，そうでない方のグループは一番多く出現する

      // 値に変えることにします．それでも同じなら適当に選びます

      std::cout << n-(f0->first+std::max(g0->first, g1->first)) << std::endl;

    }