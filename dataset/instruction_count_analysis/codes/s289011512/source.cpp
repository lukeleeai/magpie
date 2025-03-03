#include <iostream>

#include <vector>

#include <string>

#include <algorithm>

#include <bitset>

#include <cstdio>

#include <cstring>

#include <cmath>

using namespace std;



void dfs(vector<bitset<8000>>& dp, const vector<int>& a, int i, int z) {

    if (dp[i][z]) return; else dp[i][z] = true;

    if (--i >= 0) {

        dfs(dp, a, i, abs(z - a[i]));

        dfs(dp, a, i, z + a[i]);

    }

}



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

        int m = a[d].size();

        vector<bitset<8000>> dp(m + 1);

        dfs(dp, a[d], m, 0);



        if (dp[0][abs(d == 0 ? x : y)]) b++;

    }



    cout << (b == 2 ? "Yes" : "No") << endl;



    return 0;

}