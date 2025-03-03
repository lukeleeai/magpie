#include "stdc++.h"

 

using namespace std;



static const long MAX = 1000000L;

 

int main() {

    vector<long> prime;

    vector<long> dp;

    bool isPrime;

    long n, m;

 

    long i, len = sqrt(MAX) + 1;

    long j, lenJ;

    long k;

     

    prime.push_back(2);

    dp.push_back(0);

	dp.push_back(0);

	dp.push_back(1);



    for (i = 3; i <= len; i += 2) {

        isPrime = true;

        lenJ = prime.size();

        k = sqrt(i) + 1;

        for (j = 0; j < lenJ; j++) {

            if (k <= prime[j]) break;



            if (i % prime[j] == 0) {

                isPrime = false;



                break;

            }

	}



        if (isPrime) prime.push_back(i);

    }



    lenJ = prime.size();

     

    while (cin >> n) {

	if (n < dp.size()) {

		cout << dp[n] << endl;



		continue;

	}

         

	m = dp.size();

        for (i = m; i <= n; i += 2) {

            isPrime = true;



            k = sqrt(i) + 1;

            for (j = 0; j < lenJ; j++) {

                if (k <= prime[j]) break;



                if (i % prime[j] == 0) {

                    isPrime = false;



                    break;

                }

            }



            if (isPrime) {

		dp.push_back(dp.back() + 1);

		dp.push_back(dp.back());

	    } else {

		dp.push_back(dp.back());

		dp.push_back(dp.back());

	    }

        }

         

        cout << dp[n] << endl;

    }

 

    return 0;

}