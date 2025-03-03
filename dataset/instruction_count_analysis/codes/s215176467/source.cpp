#if !defined(__clang__) && defined(__GNUC__)

#include "stdc++.h"

#else

#include <cstdlib>

#include <climits>

#include <iostream>

#include <cstdint>

#include <vector>

#include <string>

#include <complex>

#include <bitset>

#include <queue>

#include <deque>

#include <stack>

#include <utility>

#include <set>

#include <map>

#include <unordered_set>

#include <unordered_map>

#include <regex>

#endif //  !defined(__clang__) && defined(__GNUG__)

#include <boost/lexical_cast.hpp>

#include <boost/algorithm/string.hpp>

#include <boost/multi_array.hpp>

#include <boost/optional.hpp>

#include <boost/math/common_factor_rt.hpp>  // https://boostjp.github.io/tips/math.html

#include <boost/dynamic_bitset.hpp>  // https://boostjp.github.io/tips/dynamic_bitset.html



constexpr int64_t DIV1097 = 1000000007LL;



using namespace std;





/** 10進 -> base進変換



    http://snowytom.hatenablog.com/entry/2018/08/13/230545

    負進数にも対応

    12345, 10 -> [1, 2, 3, 4, 5]

*/

template<typename T>

std::vector<T> conv_base(T n, T base) {

    std::vector<T> ret;

    if (n == 0) {

        ret.push_back(0);

        return ret;

    }



    while (n != 0) {

        auto r = std::abs(n) % std::abs(base);

        ret.push_back(r);

        n -= r;

        n = n / base;;

    }



    std::reverse(std::begin(ret), std::end(ret));



    return ret;

}





int main()

{

    int64_t N, K;

    std::cin >> N >> K;



    std::vector<int> D;

    for (decltype(K) i = 0; i < K; ++i) {

        int t;

        std::cin >> t;

        D.push_back(t);

    }



    for (;;++N) {

        auto b = conv_base(N, (int64_t)10);



        for (auto d: D) {

            auto pos = std::find(std::begin(b), std::end(b), d);

            if (pos != std::end(b)) {

                goto next;

            }

        }

        std::cout << N << std::endl;

        return 0;

    next:

        int a;

    }



    return 0;

}
