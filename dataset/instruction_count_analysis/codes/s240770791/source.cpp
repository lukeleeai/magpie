#include <iostream>

#include <vector>

#include <string>

#include <algorithm>

#include <cstdio>

#include <cstring>

#include <cmath>

using namespace std;

using ll = long long;



char s[300][301];

char t[300][301];

int n;

int k = 0;



int f() {

    //for (int i = 0; i < n; i++) {

    //    for (int j = 0; j < n; j++) {

    //        cout << s[i][j];

    //    }

    //    cout << endl;

    //}

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < i; j++) {

            if (s[i][j] != s[j][i]) {

                return 0;

            }

        }

    }

    return 1;

}



int main() {

    ios::sync_with_stdio(false);

    cin.tie(0);



    cin >> n;



    for (int i = 0; i < n; i++) {

        cin >> s[i];

    }



    int r = 0;

    for (int i = 0; i < n; i++) {

        memcpy(t, s, sizeof(s));

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                int i1 = i - 1; if (i1 < 0) i1 += n;

                s[i][j] = t[i1][j];

            }

        }

        r += f() * n;

        k++;

    }



    cout << r << endl;



    return 0;

}