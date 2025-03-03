#include "stdc++.h"

using namespace std;



#define dump(x) cout << (x) << '\n'

#define Int int64_t

#define fi first

#define se second

#define all(x) (x).begin(), (x).end()



Int INF = 1e18;

int inf = 1e9;

Int mod = 1e9+7;



int main() {

    double n, m, d;

    cin >> n >> m >> d;

    double x = (n - d) * 2.0;

    if (d == 0) x = n;

    double a = (m - 1.0) / n;

    double b = x / n;

    printf("%.12lf\n", a * b);



    return 0;

}
