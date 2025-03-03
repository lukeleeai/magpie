#include <iostream>

#include <string>

#include <vector>



using namespace std;



const int MX = 100000;

bool isprime[MX];



vector<int> getPrimes() {

    vector<int> ret;

    fill_n(isprime, MX, true);

    isprime[0] = isprime[1] = false;

    for (int i=2; i<=MX; ++i) {

        if ( ! isprime[i]) continue;

        ret.push_back(i);

        for (int j=i*i; 0<j && j<=MX; j+=i) {

            isprime[j] = false;

        }

    }

    return ret;

}



int main() {

    vector<int> primes = getPrimes();

    long long m, a, b;

    while (1) {

        cin >> m >> a >> b;

        if (!m && !a && !b) break;

        long long pq = 0;

        pair<int,int> ans;

        for (int i=0; i<(int)primes.size(); ++i) {

            long long p = primes[i];

            if (p * p > m) break;

            for (int j=i; j<(int)primes.size(); ++j) {

                long long q = primes[j];

                if (p * q > m || a * q > b * p) break;

                if (pq < p * q) {

                    pq = p * q;

                    ans.first = p;

                    ans.second = q;

                }

            }

        }

        cout << ans.first << " " << ans.second << endl;

    }

    return 0;

}