#include"stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

typedef long long ll;





int main() {



    string a, b;

    cin >> a >> b;

    string n = a + b;

    int num = atoi(n.c_str());

    for (ll i = 1; i < 1000000; ++i) {

        if (i * i == num) {

            cout << "Yes" << endl;

            return 0;

        }

    }

    cout << "No" << endl;

    return 0;

}