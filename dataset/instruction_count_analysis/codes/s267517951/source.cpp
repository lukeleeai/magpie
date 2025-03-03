#include "stdc++.h"

using namespace std;



const double PI = acos(-1.0);

int main() {

    double A, B, H, M;

    cin >> A >> B >> H >> M;

    double alpha = (H * 60 + M) / 720 * (PI * 2);

    double beta = M / 60 * (PI * 2);

    double theta = alpha - beta;

    double res = sqrt(A*A + B*B - 2.0*A*B*cos(theta));

    cout << fixed << setprecision(10) << res << endl;

}