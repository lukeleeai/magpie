#include "stdc++.h"

using namespace std;



int base_conversion(int number, int base)

{

    int t = 1, out = 0, r, a, count = 0;

    a = number;

    while (a != 0)

    {

        r = a % base;

        a = a / base;

        out = out + r * t;

        t = t * 10;

        count++;

    }

    return count;

}



int main()

{

    int n, k;

    cin >> n >> k;

    cout << base_conversion(n, k);

    return 0;

}