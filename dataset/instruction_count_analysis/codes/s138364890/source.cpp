#ifdef _MSC_VER

#include <__msvc_all_public_headers.hpp>

#undef min

#undef max

#else

#define NDEBUG

#include "stdc++.h"

#endif



using namespace std;

using large = long long;



int main() {

    int n;

    cin >> n; // 200'000

    assert(n % 2 == 0);



    auto a = vector<int>(n);

    for (auto& a_i : a)

        cin >> a_i;



    auto xor_total = accumulate(a.begin(), a.end(), 0, [](auto sum, auto item) { return sum xor item; });

    for (auto i = 0; i < n; ++i) {

        auto orig = a[i] ^ xor_total;

        printf("%d%c", orig, (i + 1 == n ? '\n' : ' '));

    }

    return 0;

}
