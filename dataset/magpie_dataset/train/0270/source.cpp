#include "stdc++.h"

using namespace std;



typedef complex<double> C;



int solve(int N, vector<double>& x, vector<double>& y) {

    vector<C> point(N);



    for (int j = 0; j < N; ++j) {

        point[j] = C(x[j], y[j]);

    }



    int ret = 1;



    for (int j = 0; j < N; ++j) {

        for (int k = j+1; k < N; ++k) {

            C mid = (point[j] + point[k]) * 0.5;



            C normal = (point[j] - point[k]) * C(0, 1);

            normal /= abs(point[j] - point[k]);



            double a = sqrt(1 - norm(mid - point[j]));



            C centre1 = mid + a * normal;

            int count = 0;

            for (int l = 0; l < N; ++l) {

                if (abs(centre1 - point[l]) < 1.0 + 1e-9) {

                    ++count;

                }

            }

            ret = max(ret, count);



            C centre2 = mid - a * normal;

            count = 0;

            for (int l = 0; l < N; ++l) {

                if (abs(centre2 - point[l]) < 1.0 + 1e-9) {

                    ++count;

                }

            }

            ret = max(ret, count);



        }

    }



    return ret;

}



int main () {

    int N;

    vector<double> x, y;



    while (true) {

        cin >> N;

        if (N == 0) break;



        x.resize(N);

        y.resize(N);



        for (int j = 0; j < N; ++j) {

            cin >> x[j] >> y[j];

        }



        cout << solve(N, x, y) << endl;

    }



    return 0;

}