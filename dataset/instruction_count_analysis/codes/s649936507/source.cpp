#include <algorithm>

#include <array>

#include <assert.h>

#include <bitset>

#include <chrono>

#include <cmath>

#include <complex>

#include <cstring>

#include <functional>

#include <fstream>

#include <iomanip>

#include <iostream>

#include <istream>



#include <map>

#include <math.h>

#include <numeric>

#include <ostream>

#include <queue>

#include <set>

#include <stack>

#include <string>

#include <unordered_map>

#include <unordered_set>

#include <vector>



#include <experimental/optional>



namespace asl

{

    

    template <typename T>

    std::istream &operator>>(std::istream &is, std::vector<T> &vec)

    {

        for (auto &value : vec)

            is >> value;

        return is;

    }



} 



namespace asl

{

    

    const int m1000000007 = 1000000007;

    

    int MOD = m1000000007;



    void set_mod(int mod)

    {

        MOD = mod;

    }



    class Mint

    {

    public:

        int val;



        Mint(long long v = 0)

        {

            if (v >= 0)

            {

                if (v < MOD)

                    val = v;

                else

                    val = v % MOD;

            }

            else

            {

                if (v >= -MOD)

                {

                    val = v + MOD;

                }

                else

                {

                    v %= MOD;

                    if (v < 0)

                        v += MOD;

                    val = v;

                }

            }

        }



        Mint &operator+=(const Mint &other)

        {

            val += other.val;

            if (val >= MOD)

                val -= MOD;

            return *this;

        }



        friend Mint operator+(const Mint &a, const Mint &b) { return Mint(a) += b; }

        

        friend std::ostream &operator<<(std::ostream &stream, const Mint &m)

        {

            return stream << m.val;

        }



    };

} 



#include <random>



#define endl '\n'



using namespace std;

using namespace asl;



int main()

{

    ios_base::sync_with_stdio(0);

    cin.tie(0);



    set_mod(m1000000007);



    int n;

    cin >> n;

    long long a, b;

    vector<long long> v(n);



    cin >> a >> b >> v;



    if (a >= b)

        swap(a, b);



    vector<Mint> dpA(n), dpB(n);

    dpA[0] = 1, dpB[0] = 1;

    int good_seq = 0;



    for (int i = 1, j = 0; i < n; ++i)

    {

        while (v[i] - v[j] >= b)

            ++j;



        if (good_seq >= i - j - 1)

        {

            dpB[i] += j == 0 ? 1 : dpB[j - 1];

            if (j > 0 && v[j] - v[j - 1] >= a)

                dpB[i] += dpA[j - 1];

        }



        if (v[i] - v[i - 1] >= a)

            good_seq++;

        else

            good_seq = 0;



        if (good_seq)

            dpA[i] += dpA[i - 1];



        if (i < 2 || v[i] - v[i - 2] >= a)

            dpA[i] += dpB[i - 1];

    }



    cout << dpA.back() + dpB.back() << endl;



    return 0;

}




