#include <iostream>

#include <vector>

#include <string>

#include <algorithm>

#include <map>

#include <cstdio>

#include <cstring>

#include <cmath>

using namespace std;

using ll = long long;



int main() {

    ios::sync_with_stdio(false);

    cin.tie(0);



    int n;

    cin >> n;



    char s[300][600];

    for (int i = 0; i < n; i++) {

        cin >> s[i];

        memcpy(&s[i][n], &s[i][0], n);

    }



    int r = 0;

    for (int x = 0; x < n; x++) {

        for (int i = 0; i < n; i++) {

            for (int j = i + 1; j < n; j++) {

                if (s[i][j + x] != s[j][i + x]) goto chigau;

            }

        }

        r++;

        continue;

    chigau:

        continue;

    }



    cout << r * n << endl;



    return 0;

}