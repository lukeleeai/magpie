#include <algorithm>

#include <complex>

#include <cstdio>

#include <iostream>

#include <utility>

#include <vector>

using namespace std;

#define X real()

#define Y imag()

#define EPS (1e-10)

#define INF (1e9)

typedef complex<double> P;

typedef pair<P, P> L;



namespace std{

  bool operator<(const P& a, const P& b){

    return a.X != b.X ? a.X < b.X : a.Y < b.Y;

  }

}



double dot(P a, P b){

  return a.X*b.X + a.Y*b.Y;

}



double cross(P a, P b){

  return a.X*b.Y - a.Y*b.X;

}



int ccw(P a, P b, P c){

  if(cross(b-a,c-a) > EPS) return 1;

  if(cross(b-a,c-a) < -EPS) return -1;

  if(dot(b-a,c-a) < EPS) return 2;

  if(abs(b-a) + EPS < abs(c-a)) return -2;

  return 0;

}



bool is_cross(L a, L b){

  if(ccw(a.first,a.second,b.first)*ccw(a.first,a.second,b.second) <= 0 &&

     ccw(b.first,b.second,a.first)*ccw(b.first,b.second,a.second) <= 0) return true;

  return false;

}



double p_to_s_dist(P a, L s){

  if(dot(s.second-s.first,a-s.first) >= 0 && dot(s.first-s.second,a-s.second) >= 0){

    return abs(cross(s.first-s.second,a-s.second))/abs(s.first-s.second);

  }

  return min(abs(a-s.first), abs(a-s.second));

}



double s_to_s_dist(L a, L b){

  if(is_cross(a,b)) return 0;

  return min(min(p_to_s_dist(a.first,b),p_to_s_dist(a.second,b)),

	     min(p_to_s_dist(b.first,a),p_to_s_dist(b.second,a)));

}



int main(){

  int N;

  double h, d, x[2], y[2];

  while(cin >> N, N){

    vector<P> V;

    cin >> x[0] >> y[0] >> x[1] >> y[1];

    P s = P(x[0],y[0]), e = P(x[1],y[1]);

    L c = L(s,e);

    for(int i = 0; i < N; ++i){

      cin >> x[0] >> y[0] >> x[1] >> y[1] >> h;

      L edge[4];

      for(int j = 0; j < 4; ++j){

	edge[j] = L(P(x[j/2],y[j%2]),P(x[((j+1)/2)%2],y[(j+1)%2]));

      }

      d = 100000;

      for(int j = 0; j < 4; ++j){

	d = min(d, s_to_s_dist(c, edge[j]));

      }

      V.push_back(P(d,h));

    }

    sort(V.begin(), V.end());

    double ub = 100000, lb = 0, r = ub/2;

    for(int t = 0; t < 10000; ++t){

      r = (ub+lb)/2;

      bool f = true;

      for(int i = 0; i < N; ++i){

	if((V[i].X < EPS) || ((r > norm(V[i])/2/V[i].Y || V[i].Y > r) && (r > V[i].X))){

	  f = false;

	  break;

	}

      }

      if(f) lb = r;

      else ub = r;

    }

    printf("%.4lf\n", r);

  }

  return 0;

}