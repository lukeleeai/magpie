#include <iostream>

#include <iomanip>

#include <string>

#include <vector>

#include <algorithm>

#include <map>

#include <cmath>

#include <queue>

#include <set>

#include <cassert>

#include <random>



#define rep(i, n) for (int i = 0; i < (n); i++)



using namespace std;

typedef long long int ll;

const ll INF = 1000000000;

const double PI = acos(-1);

const int mod = 1000000007;



int main()

{

    int x;

    cin >> x;



    for (int n = 1; n <= 1000; n++) {

        for (int i = 100 * n; i <= 105 * n; i++) {

            if (i == x) {

                cout << 1 << endl;

                return 0;

            }

        }

    }

    cout << 0 << endl;

    return 0;

}
