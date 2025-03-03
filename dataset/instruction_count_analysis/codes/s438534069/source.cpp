#include <algorithm>

#include <cmath>

#include <cstdio>

#include <iomanip>

#include <iostream>

#include <map>

#include <queue>

#include <sstream>

#include <string>



using namespace std;



void solve(int D, int N) {

  int d = 1;

  for (int i = 0; i < D; i++) {

    d *= 100;

  }

  if (N == 100) {

    printf("%d\n", 101 * d);

  } else {

    printf("%d\n", N * d);

  }

}



int main() {

  int D, N;

  cin >> D >> N;

  solve(D, N);

  return 0;

}