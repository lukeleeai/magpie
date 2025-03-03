#include <iostream>

#include <cstdio>

#include <cstring>

using namespace std;



typedef long long llt;



const int MaxN = 50 + 5;

const llt Mod = 1e9 + 7;



struct Matrix {

  llt mat[MaxN][MaxN];

  Matrix() {

    memset(mat, 0, sizeof mat);

  }

};



int N; llt K;

Matrix G;



inline Matrix operator * (Matrix A, Matrix B) {

  Matrix C;

  for (int i = 1; i <= N; ++i)

    for (int j = 1; j <= N; ++j) {

      for (int k = 1; k <= N; ++k)

        C.mat[i][j] = (C.mat[i][j] + A.mat[i][k] * B.mat[k][j]) % Mod;

    }

  return C;

}



inline Matrix operator ^ (Matrix low, llt high) {

  Matrix res;

  for (int i = 1; i <= N; ++i) res.mat[i][i] = 1;

  while (high) {

    if (high & 1) res = res * low;

    high >>= 1;

    low = low * low;

  }

  return res;

}



void init() {

  scanf("%d %lld", &N, &K);

  for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j)

    scanf("%lld", &G.mat[i][j]);

}



void solve() {

  G = G ^ K;

  llt res = 0;

  for (int i = 1; i <= N; ++i) for (int j = 1; j <= N; ++j)

    res = (res + G.mat[i][j]) % Mod;

  cout << res << endl;

}



int main() {

  init();

  solve();

  return 0;

}