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

#include <boost/math/common_factor_rt.hpp>



using namespace std;



int main()

{

    int64_t N, K;

    std::cin >> N >> K;



    std::string D;

    D = "[";

    for (size_t i = 0; i < K; ++i) {

        char t;

        std::cin >> t;

        D += t;

    }

    D += "]";



    cerr << D << endl;



    std::regex re(D);

    for (;;) {

        auto s = boost::lexical_cast<std::string>(N);

        if (!std::regex_search(s, re)) {

            std::cout << s << std::endl;

            return 0;

        }

        N++;

    }





    return 0;

}
