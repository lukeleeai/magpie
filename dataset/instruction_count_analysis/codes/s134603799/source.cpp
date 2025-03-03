#include <cstdio>

#include <cstring>



const int MaxN = 50;

const int Mod = 1000000007;



int N;

long long K;



inline int add(int x, int y) { return (x += y) >= Mod ? x - Mod : x; }

inline int sub(int x, int y) { return (x -= y) < 0 ? x + Mod : x; }

inline int mul(int x, int y) { return 1LL * x * y % Mod; }



struct Matrix {

  int mat[MaxN][MaxN];



  Matrix() {

    memset(mat, 0, sizeof mat);

  }



  inline friend Matrix operator + (const Matrix &a, const Matrix &b) {

    Matrix c;

    for (int i = 0; i < N; ++i)

      for (int j = 0; j < N; ++j)

        c.mat[i][j] = add(a.mat[i][j], b.mat[i][j]);

    return c;

  }



  inline friend Matrix operator * (const Matrix &a, const Matrix &b) {

    Matrix c;

    for (int i = 0; i < N; ++i)

      for (int j = 0; j < N; ++j) {

        int x = 0;

        for (int k = 0; k < N; ++k)

          x = add(x, mul(a.mat[i][k], b.mat[k][j]));

        c.mat[i][j] = x;

      }

    return c;

  }



  inline friend Matrix operator ^ (Matrix low, long long high) {

    Matrix res;

    for (int i = 0; i < N; ++i) res.mat[i][i] = 1;

    while (high) {

      if (high & 1) res = res * low;

      high >>= 1;

      low = low * low;

    }

    return res;

  }

};

Matrix G;



void init() {

  scanf("%d %lld", &N, &K);

  for (int i = 0; i < N; ++i)

    for (int j = 0; j < N; ++j)

      scanf("%d", &G.mat[i][j]);

}



void solve() {

  G = G ^ K;

  int ans = 0;

  for (int i = 0; i < N; ++i)

    for (int j = 0; j < N; ++j)

      ans = add(ans, G.mat[i][j]);

  printf("%d\n", ans);

}



int main() {

  init();

  solve();

  return 0;

}