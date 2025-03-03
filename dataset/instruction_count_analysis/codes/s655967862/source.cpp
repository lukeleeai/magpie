#include "stdc++.h"



using namespace std;



typedef long long int LLI;



// #define debug



bool check(LLI k, LLI a, LLI b, LLI x, LLI y) {

    return k*x >= a && k*y >= b;

}





int main() { 

    int n, x, y;

    while (cin >> n) {

        LLI a = 0, b = 0, lo, hi, mi;

        cin >> a >> b;

        for (int i = 1; i < n; ++i) {

            cin >> x >> y;

            lo = 1, hi = min(1e18/x, 1e18/y);

            while (lo < hi) {

                mi = (lo+hi)>>1;

                if (check(mi, a, b, x, y)) hi = mi;

                else lo = mi+1;

            }

            a = x*lo;

            b = y*lo;

#ifdef debug

            cout << a << " " << b << "\n";

#endif

        }

        cout << a+b << "\n";

    }



    return 0;

}
