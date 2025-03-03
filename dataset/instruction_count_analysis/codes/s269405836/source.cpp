#include <iostream> // cout, endl, cin

#include <string> // string, to_string, stoi

#include <vector> // vector

#include <algorithm> // min, max, swap, sort, reverse, lower_bound, upper_bound

#include <utility> // pair, make_pair

#include <tuple> // tuple, make_tuple

#include <cstdint> // int64_t, int*_t

#include <cstdio> // printf

#include <map> // map

#include <queue> // queue, priority_queue

#include <set> // set

#include <stack> // stack

#include <deque> // deque

#include <unordered_map> // unordered_map

#include <unordered_set> // unordered_set

#include <bitset> // bitset

#include <cctype> // isupper, islower, isdigit, toupper, tolower

#include <cmath>

#include <complex>

using namespace std;

const double pi = 3.14159265358979323846264338;

long long easy_factor(long long n){

  if (n == 1){

    return 1;

  }

  else{

    long long p = 2;

    long long f = 2;

    while (n % p != 0){

      p += 1;

      if (n % p == 0){

        f = p;

        break;

      }

      if (p * p > n){

        f = n;

        break;

      }

    }

    return f;

  }

}



template <typename T>

T vecout(T A){

  for (int i=0;i<A.size();i++){

    cout << A[i] << endl;

  }

}



vector<complex<double>> simply_fft(vector<complex<double>> f, long long n){

  if (n == 1){

    return f;

  }

  else if (n == 2){

    return {f[0] + f[1], f[0] - f[1]};

  }

  else{

    long long dn = n / 2;

    vector<complex<double>> fe(dn);

    vector<complex<double>> fo(dn);

    for (long long j=0;j<dn;j++){

      fe[j] = f[2*j+0];

      fo[j] = f[2*j+1];

    }

    fe = simply_fft(fe, dn);

    fo = simply_fft(fo, dn);

    complex<double> grow = 1.0 + 0.0i;

    complex<double> seed = cos((2.0*pi)/n) - 1i*sin((2.0*pi)/n);

    complex<double> right = 0;

    for (long long i=0;i<dn;i++){

      right = fo[i] * grow;

      f[i] = fe[i] + right;

      f[i+dn] = fe[i] - right;

      grow *= seed;

    }

    return f;

  }

}



vector<complex<double>> simply_ifft(vector<complex<double>> f, long long n){

  if (n == 1){

    return f;

  }

  else if (n == 2){

    return {f[0] + f[1], f[0] - f[1]};

  }

  else{

    long long dn = n / 2;

    vector<complex<double>> fe(dn);

    vector<complex<double>> fo(dn);

    for (long long j=0;j<dn;j++){

      fe[j] = f[2*j+0];

      fo[j] = f[2*j+1];

    }

    fe = simply_ifft(fe, dn);

    fo = simply_ifft(fo, dn);

    complex<double> grow = 1.0 + 0.0i;

    complex<double> seed = cos((2.0*pi)/n) + 1i*sin((2.0*pi)/n);

    complex<double> right = 0;

    for (long long i=0;i<dn;i++){

      right = fo[i] * grow;

      f[i] = fe[i] + right;

      f[i+dn] = fe[i] - right;

      grow *= seed;

    }

    return f;

  }

}



long long powlimit(long long x){

  long long y = 1;

  while (y < x){

    y *= 2;

  }

  return y;

}

int main(){

  long long N, M;

  cin >> N >> M;

  long long m = 0;

  vector<long long> A(N);

  for (int i=0;i<N;i++){

    cin >> A[i];

    if (m < A[i]){

      m = A[i];

    }

  }

  long long pl = powlimit(2*m+2);

  vector<complex<double>> X(pl, 0);

  for (int i=0;i<N;i++){

    X[A[i]] += 1.0;

  }

  vector<complex<double>> F = simply_fft(X, pl);

  vector<complex<double>> Y(pl, 0);

  for (int i=0;i<pl;i++){

    Y[i] = F[i] * F[i];

  }

  vector<complex<double>> Z = simply_ifft(Y, pl);

  vector<long long> sol(pl, 0);

  for (long long i=0;i<pl;i++){

    sol[i] = floor(0.5+real(Z[i])/pl);

  }

  long long S = 0, i = pl - 1, pat = 0;

  while (pat < M){

    if (pat + sol[i] > M){

      S += (M - pat) * i;

      pat = M;

    }

    else{

      S += sol[i] * i;

      pat += sol[i];

    }

    i -= 1;

  }

  cout << S << endl;

}