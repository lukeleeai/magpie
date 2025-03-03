#include <algorithm>

#include <iostream>

#include <iomanip>

#include <cstring>

#include <string>

#include <vector>

#include <queue>

#include <cmath>

#include <stack>

#include <set>

#include <map>

typedef long long ll;

typedef unsigned int uint;

using namespace std;



int main() {

    cin.sync_with_stdio(false);

    cin.tie(0);



    int n, k;

    cin >> n >> k;



    vector<int> kirai;

    for (int i = 0; i < k; i++) {

        int d;

        cin >> d;

        kirai.push_back(d);

    }



    for (int i = 0; i < 100000; i++) {

        int t = i;

        bool valid = true;



        while (t > 0) {

            bool possible = true;

            for (int j = 0; j < kirai.size(); j++) {

                if (t % 10 == kirai[j]) {

                    possible = false;

                }

            }

            if (!possible) valid = false;

            t /= 10;

        }



        if (valid && i >= n) {

            cout << i << endl;

            return 0;

        }

    }

}
