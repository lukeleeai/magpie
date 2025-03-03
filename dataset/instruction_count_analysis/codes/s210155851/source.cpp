#include <algorithm>

#include <iostream>

#include <stdio.h>

#include <complex>

#include <math.h>

#include <assert.h>



using namespace std;

typedef complex<double> Complex;



static const double E = 0.000001;



inline bool collide_circle_circle(const Complex p1, const double r1, const Complex p2, const double r2) {

  assert(r1 >= 0.0 && r2 >= 0.0);

  Complex dif = p1 - p2;

  return dif.real() * dif.real() + dif.imag() * dif.imag() <= (r1 + r2) * (r1 + r2) + E;

}



// include circle inside

inline bool collide_circle_point(const Complex p1, const double r1, const Complex p2) {

  return collide_circle_circle(p1, r1, p2, 0.0);

}



inline void intersection_circle_circle(const Complex p1, const double r1, const Complex p2, const double r2, int *size, Complex *ret1, Complex *ret2) {

  assert(p1 != p2);

  assert(ret1 != NULL && ret2 != NULL);

  if (!collide_circle_circle(p1, r1, p2, r2)) {

    if (size != NULL) { *size = 0; }

    *ret1 = *ret2 = Complex(NAN, NAN);

    return;

  }

  Complex center = (p1 * r2 + p2 * r1) / (r1 + r2);

  Complex vect = (center - p1) * Complex(0.0, 1.0);

  if (abs(vect) < E) {

    *ret1 = *ret2 = center;

    if (size != NULL) { *size = 1; }

    return;

  }

  vect *= sqrt(r1 * r1 - norm(vect)) / abs(vect);

  *ret1 = center + vect;

  *ret2 = center + vect * Complex(-1.0, 0.0);

  if (size != NULL) { *size = 2; }

}



Complex point[301];



int main() {

  int n;

  while (scanf("%d", &n), n != 0) {

    for (int i = 0; i < n; i++) {

      double a, b;

      scanf("%lf %lf", &a, &b);

      point[i] = Complex(a, b);

    }

    int max_ans = 1;

    for (int i = 0; i < n; i++) {

      for (int j = 0; j < i; j++) {

        if (!collide_circle_circle(point[i], 1.0, point[j], 1.0)) { continue; }

        int size;

        Complex m[2];

        intersection_circle_circle(point[i], 1.0, point[j], 1.0, &size, &m[0], &m[1]);

        for (int s = 0; s < size; s++) {

          int ans = 0;

          for (int k = 0; k < n; k++) {

            if (collide_circle_point(m[s], 1.0, point[k])) {

              ans++; }

          }

          max_ans = max(max_ans, ans);

        }

      }

    }

    printf("%d\n", max_ans);

  }

}