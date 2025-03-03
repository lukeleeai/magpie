#include "stdc++.h"

#include <iostream>

using namespace std;



int cnt(int x) {

    int c = 0;

    for (int i = 1; i <= x; i++) {

        if (x % i == 0) {

            c++;

        }

    }

    return c;

}



int main() {

    int n;

    cin >> n;



    int c = 0;

    for (int i = 1; i <= n; i+=2) {

        if (cnt(i) == 8) {

            c++;

        }

    }



    cout << c << endl;

}


