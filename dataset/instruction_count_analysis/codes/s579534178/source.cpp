#include <set>

#include <cstdio>

#include <algorithm>

#include <queue>

#include <cstdlib>

#include <complex>



#define REP(i,n) for(int i=0; i<(int)(n); i++)

inline int getInt(){ int s; scanf("%d", &s); return s; }



using namespace std;



typedef complex<double> P;



int main(){

  while(const int n = getInt()){

    vector<P>   pos(n);

    vector<double> v(n);



    REP(i,n){

      const int x = getInt();

      const int y = getInt();

      v[i] = getInt();

      pos[i] = P(x, y);

    }



    const double r = 0.98;

    P p(0, 0);



    auto calc = [&](P p){

      auto mx = make_pair(0.0, 0);

      REP(i,n) mx = max(mx, make_pair(abs(p - pos[i]) / v[i], i));

      return mx;

    };



    for(double d = 1000; d > 1e-8; d *= r){

      auto mx = calc(p).second;

      p += (pos[mx] - p) / abs(pos[mx] - p) * d;

    }



    printf("%.8f\n", calc(p).first);

  }



  return 0;

}