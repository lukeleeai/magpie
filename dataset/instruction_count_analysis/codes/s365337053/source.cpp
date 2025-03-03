#include <iostream>

#include <algorithm>

#include <vector>

#include <cmath>



using namespace std;



typedef long long i64;



i64 f(i64 b, i64 n) {

    i64 s=0;

    while (n) {

        s += n % b;

        n /= b;

    }

    return s;

}



int main(void) {

    i64 n, s;

    cin >> n >> s;



    if (n == s) {

        cout << n+1 << endl;

        return 0;

    }



    i64 ub=sqrt(n);

    i64 b;

    for (b=2; b<=ub; b++)

        if (f(b, n) == s) {

            cout << b << endl;

            return 0;

        }



    i64 p;

    for (p=ub+1; --p;) {

        b = (n-s)/p + 1;

        if (b < 2) continue;

        if (f(b, n) == s) {

            cout << b << endl;

            return 0;

        }

    }

    cout << "-1\n";

    return 0;

}
