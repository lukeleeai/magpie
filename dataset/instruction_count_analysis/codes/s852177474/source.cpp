#include <iostream>

#include <algorithm>



using namespace std;



typedef long long i64;



i64 gcd(i64, i64);



int main(void) {

    i64 N, X;

    cin >> N >> X;



    i64 L=N;

    i64 tmp;

    N -= X;

    if (X > N) swap(N, X);

    while (X) {

        if (N % X > 0) {

            L += 2 * (N / X) * X;

        } else {

            L += 2 * (N / X) * X - X;

            break;

        }



        tmp = X;

        X = N % X;

        N = tmp;

    }



    cout << L << endl;

    return 0;

}





i64 gcd(i64 m, i64 n) {

    i64 tmp;

    while (n) {

        if (m >= n) {

            tmp = m % n;

        } else {

            tmp = m;

        }

        m = n;

        n = tmp;

    }

    return m;

}
