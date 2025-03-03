#include <iostream>

#include <iomanip>

#include <cmath>

#include <random>

using namespace std;

random_device rd;

mt19937 mt(rd());



int n;

double x[111], y[111];



int main() {

  cin >> n;

  for(int i = 0; i < n; ++i) cin >> x[i] >> y[i];



  double ans = 0.0;

  uniform_real_distribution<> rand(-1.0, 1.0);

  for(int a = 0; a < 10000; ++a) {

    x[n] = rand(mt), y[n] = rand(mt);



    double px = 0.0, py = 0.0;

    for(int i = 0; i < n; ++i) {

      if(x[i]*x[n] + y[i]*y[n] >= 0) px += x[i], py += y[i];

    }

    ans = max(ans, px*px + py*py);

  }

  cout << fixed << setprecision(15) << sqrt(ans);

  return 0;

}