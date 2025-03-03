#include "stdc++.h"



#include <boost/range/adaptors.hpp>

#include <boost/range/combine.hpp>

#include <boost/range/irange.hpp>



using namespace std;

using namespace boost;

using namespace boost::adaptors;



int64_t count_i(int64_t k, int64_t p) {

    int64_t t = 0;

    while (k % p == 0) {

        ++t;

        k /= p;

    }



    return min(t, 9L);

}



int main() {

    int64_t n;

    cin >> n;



    vector<pair<int64_t, int64_t>> a(n);

    for (auto&& aa : a) {

        double d;

        cin >> d;



        int64_t dd = llround(d * 1000000000L);

        int64_t g = gcd(dd, 1000000000L);



        aa = {dd / g, 1000000000L / g};

    }



    vector m(10, vector(10, vector(10, vector(10, 0L))));

    for (auto aa : a) {

        auto b2 = count_i(aa.first, 2);

        auto b5 = count_i(aa.first, 5);

        auto c2 = count_i(aa.second, 2);

        auto c5 = count_i(aa.second, 5);



        ++m[b2][b5][c2][c5];

    }



    for (auto i : irange(0L, 10L)) {

        for (auto j : irange(0L, 10L)) {

            for (auto k : irange(0L, 10L)) {

                for (auto k2 : irange(1L, 10L)) {

                    m[i][j][k][k2] += m[i][j][k][k2 - 1];

                }

            }

            for (auto k : irange(1L, 10L)) {

                for (auto k2 : irange(0L, 10L)) {

                    m[i][j][k][k2] += m[i][j][k - 1][k2];

                }

            }

        }

    }



    int64_t ans = 0;

    for (auto aa : a) {

        auto b2 = count_i(aa.first, 2);

        auto b5 = count_i(aa.first, 5);

        auto c2 = count_i(aa.second, 2);

        auto c5 = count_i(aa.second, 5);



        for (auto i2 : irange(c2, 10L)) {

            for (auto i5 : irange(c5, 10L)) {

                ans += m[i2][i5][b2][b5];

            }

        }



        if (aa.second == 1) {

            --ans;

        }

    }



    assert(ans % 2 == 0);

    cout << ans / 2 << endl;

}
