#include <algorithm>

#include <bitset>

#include <climits>

#include <cmath>

#include <cstring>

#include <ctime>

#include <functional>

#include <iostream>

#include <map>

#include <numeric>

#include <queue>

#include <set>

#include <sstream>

#include <stack>

#include <string>

#include <tuple>

#include <unordered_map>

#include <utility>

#include <vector>

#include <complex>



using namespace std;



const int SIZ = 100000;



vector<int> getPrimes() {

    vector<int> primes;

    int sieve[SIZ];

    fill_n(sieve, SIZ, true);

    sieve[0] = sieve[1] = false;

    primes.push_back(2);

    for (int i=4; i<SIZ; i+=2) {

        sieve[i] = false;

    }

    for (int i=3; i*i<SIZ; i+=2) {

        if ( ! sieve[i]) continue;

        for (int j=i*2; j<SIZ; j+=i) {

            sieve[j] = false;

        }

    }

    for (int i=3; i<SIZ; i+=2) {

        if (sieve[i]) primes.push_back(i);

    }

    return primes;

}



int main() {

    ios::sync_with_stdio(false);

    vector<int> primes = getPrimes();

    int m, a, b;

    while (1) {

        cin >> m >> a >> b;

        if (!m && !a && !b) break;

        int tp, tq, p = 0, q = 0, max_m = 0;

        for (int i=0; i<(int)primes.size(); ++i) {

            for (int j=i; j<(int)primes.size(); ++j) {

                tp = primes[i];

                tq = primes[j];

                if (tp * tq < 0) break;

                if (m < tp * tq || b * tp < a * tq) {

                    break;

                }

                if (max_m < tp * tq) {

                    p = tp;

                    q = tq;

                    max_m = tp * tq;

                }

            }

        }

        cout << p << " " << q << endl;

    }

    return 0;

}