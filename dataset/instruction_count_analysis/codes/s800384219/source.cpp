#include <iostream>

#include <vector>

#include <string>

#include <algorithm>

#include <cstdio>

#include <cstring>

#include <cmath>

using namespace std;



int main() {

    ios::sync_with_stdio(false);

    cin.tie(0);



    string s;

    cin >> s;



    s.push_back('T');

    int n = s.size();



    int x, y;

    cin >> x >> y;



    vector<int> a[2];

    int c = 0, d = 0, f = 0;

    for (int i = 0; i < n; i++) {

        if (s[i] == 'F') {

            c++;

        } else {

            if (f == 0) {

                x -= c;

                f = 1;

            } else {

                a[d].push_back(c);

            }

            c = 0;

            d ^= 1;

        }

    }



    int b = 0;

    for (int d = 0; d < 2; d++) {

        vector<int> dp(20000), h(20000);

        dp[10000] = 1;



        int m = a[d].size();

        for (int i = 0; i < m; i++) {

            int a1 = a[d][i];

            for (int j = 0; j < 20000; j++) {

                h[j] = 0;

            }

            for (int j = 0; j < 20000; j++) {

                if (dp[j]) {

                    h[j - a1] = 1;

                    h[j + a1] = 1;

                }

            }

            for (int j = 0; j < 20000; j++) {

                dp[j] = h[j];

            }

        }



        int z = d == 0 ? x : y;

        if (dp[z + 10000]) b++;

    }



    cout << (b == 2 ? "Yes" : "No") << endl;



    return 0;

}