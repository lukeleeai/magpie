#include <iostream>

#include <vector>

#include <queue>

#include <map>

#include <set>

#include <list>

#include <deque>

#include <string>

#include <algorithm>

#include <cmath>

#include <ctype.h>

using namespace std;

#define dump(a) cout << (a) << '\n';

typedef long long Int;

Int mod = 1e9+7;

Int MOD = 998244353;



int main() {

    ios::sync_with_stdio(false);

    Int n, m, d;

    cin >> n >> m >> d;

    double res = 0.0;

    for (Int i = 0; i < m - 1; i++) {

        res += (double)(n - d) * 2.0 / (double)(n * n);

    }

    if (d == 0) res /= 2.0;

    printf("%.12lf\n", res);

    return 0;  

}    