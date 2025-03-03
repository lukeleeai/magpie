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

    cout << A.at(i) << endl;

  }

}



vector<complex<long double>> simply_fft(vector<complex<long double>> f, long long n){

  if (n == 1){

    return f;

  }

  else{

    long long dn = n / 2;

    vector<complex<long double>> fe(dn);

    vector<complex<long double>> fo(dn);

    for (long long j=0;j<dn;j++){

      fe.at(j) = f.at(2*j+0);

      fo.at(j) = f.at(2*j+1);

    }

    vector<complex<long double>> tmp0 = simply_fft(fe, dn);

    vector<complex<long double>> tmp1 = simply_fft(fo, dn);

    complex<long double> grow = 1.0 + 0.0i;

    complex<long double> seed = cos((2.0*pi)/n) - 1i*sin((2.0*pi)/n);

    complex<long double> right = 0;

    for (long long i=0;i<dn;i++){

      right = tmp1.at(i) * grow;

      f.at(i) = tmp0.at(i) + right;

      f.at(i+dn) = tmp0.at(i) - right;

      grow *= seed;

    }

    return f;

  }

}



vector<complex<long double>> simply_ifft(vector<complex<long double>> f, long long n){

  if (n == 1){

    return f;

  }

  else{

    long long dn = n / 2;

    vector<complex<long double>> fe(dn);

    vector<complex<long double>> fo(dn);

    for (long long j=0;j<dn;j++){

      fe.at(j) = f.at(2*j+0);

      fo.at(j) = f.at(2*j+1);

    }

    vector<complex<long double>> tmp0 = simply_ifft(fe, dn);

    vector<complex<long double>> tmp1 = simply_ifft(fo, dn);

    complex<long double> grow = 1.0 + 0.0i;

    complex<long double> seed = cos((2.0*pi)/n) + 1i*sin((2.0*pi)/n);

    complex<long double> right = 0;

    for (long long i=0;i<dn;i++){

      right = tmp1.at(i) * grow;

      f.at(i) = tmp0.at(i) + right;

      f.at(i+dn) = tmp0.at(i) - right;

      grow *= seed;

    }

    return f;

  }

}

vector<long long> vecmachine(){

  vector<long long> A(100000);

  for (int i=0;i<100000;i++){

    A.at(i) = 100000;

  }

  return A;

}

long long powlimit(long long x){

  long long y = 1;

  while (y < x){

    y *= 2;

  }

  return y;

}



// ------------------------------------------



int main(){

  long long N, M;

  cin >> N >> M;

  long long m = 0;

  vector<long long> A(N);

  for (int i=0;i<N;i++){

    cin >> A.at(i);

    if (m < A.at(i)){

      m = A.at(i);

    }

  }

  long long pl = powlimit(2*m+2);

  vector<complex<long double>> X(pl, 0);

  for (int i=0;i<N;i++){

    X.at(A.at(i)) += 1.0;

  }

  vector<complex<long double>> F = simply_fft(X, pl);

  vector<complex<long double>> Y(pl, 0);

  for (int i=0;i<pl;i++){

    Y.at(i) = F.at(i) * F.at(i);

  }

  vector<complex<long double>> Z = simply_ifft(Y, pl);

  vector<long long> sol(pl, 0);

  for (long long i=0;i<pl;i++){

    sol.at(i) = floor(0.5+real(Z.at(i))/pl);

  }

  long long S = 0, i = pl - 1, pat = 0;

  while (pat < M){

    if (pat + sol.at(i) > M){

      S += (M - pat) * i;

      pat = M;

    }

    else{

      S += sol.at(i) * i;

      pat += sol.at(i);

    }

    i -= 1;

    if (i < 0){

      break;

    }

  }

  cout << S << endl;

}
