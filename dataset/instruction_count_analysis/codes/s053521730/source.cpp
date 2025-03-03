#include <iostream>

#include <deque>

#include <string>

#include <cstdio>

#include <vector>

#include <algorithm>

#include <string>

#include <cmath>

#include <complex>



#define loop(i,a,b) for(int i=a; i<int(b); i++)

#define rep(i,n) loop(i,0,n)



using namespace std;

typedef complex<double> vec;



double const pi = acos(-1);

double const eps = 1e-6;



int main(){

    int n;

    while (cin >> n && n){

        vector<vec> v(n);

        rep(i, n){

            double x, y; cin >> x >> y;

            vec p(x, y);

            v[i] = p;

        }



        if (n == 1) {

            puts("1");

            continue;

        }

        int ans = 1;

        rep(i, n)rep(j, n)if (i != j){

            double d = abs(v[i] - v[j]);

            if (d > 2) continue;

            ans = max(ans, 2);

            double h = sqrt(1 - d*d / 4);

            vec c1 = polar(h, arg(v[i] - v[j]) + pi / 2) + (v[i] + v[j]) / 2.;

            vec c2 = polar(h, arg(v[i] - v[j]) - pi / 2) + (v[i] + v[j]) / 2.;

            int a1 = 0, a2 = 0;

            rep(k, n){

                if (abs(c1 - v[k]) <= 1) a1++;

                if (abs(c2 - v[k]) <= 1) a2++;

            }

            ans = max(ans, a1);

            ans = max(ans, a2);

        }

        cout << ans << endl;

    }

}