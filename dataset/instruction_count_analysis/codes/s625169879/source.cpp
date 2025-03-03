#include "stdc++.h"

using namespace std;

#define rep(i,n) for(int i=0;i<n;++i)

#define rep1(i,n) for(int i=1;i<=n;++i)

#define FOR(i,a,b) for(int i=(a);i<(b);++i)

#define all(a) a.begin(),a.end()

#define lb(s,x) lower_bound(all(s),x)-s.begin()

#define debug(x) cout<<#x<<": "<<x<<endl

#define INF 1e9

typedef long long ll;



const double EPS = 1e-9;

#define EQ(n,m) (abs((n)-(m)) < EPS)



typedef complex<double> Point;

typedef pair<Point, Point> Line;

typedef vector<Point> VP;

#define X real()

#define Y imag()



// 2????????????

VP crosspointCC(Point a, double ar, Point b, double br) {

  VP ps;

  Point ab = b-a;

  double d = abs(ab);

  double crL = (norm(ab) + ar*ar - br*br) / (2*d);

  if (EQ(d, 0) || ar < abs(crL)) return ps;



  Point abN = ab * Point(0, sqrt(ar*ar - crL*crL) / d);

  Point cp = a + crL/d * ab;

  ps.push_back(cp + abN);

  ps.push_back(cp - abN);

  return ps;

}



// VP crosspointCC(Point p1, double r1, Point p2, double r2){

//   double d = abs(p2-p1);

//   double t = acos(double((d*d+r1*r1-r2*r2)/(2*d*r1)));

//   return Line(p1+polar(r1,arg(p2-p1)+t), p1+polar(r1,arg(p2-p1)-t));

// }



double dot(Point a, Point b) {

  return a.X*b.X + a.Y*b.Y;

}



// ?????????cross(a,b) = |a||b|sin??

double cross(Point a, Point b) {

  return a.X*b.Y - a.Y*b.X;

}



// ??????????????????

int ccw(Point a, Point b, Point c) {

  b -= a;  c -= a;

  if (cross(b,c) >  EPS) return +1;  // counter clockwise

  if (cross(b,c) < -EPS) return -1;  // clockwise

  if (dot(b,c)   < -EPS) return +2;  // c--a--b on ps

  if (norm(b) < norm(c)) return -2;  // a--b--c on ps or a==b

  return 0;                          // a--c--b on ps or a==c or b==c

}



bool isecSS(Point a1, Point a2, Point b1, Point b2) {

  return ccw(a1, a2, b1)*ccw(a1, a2, b2) <= 0 &&

  ccw(b1, b2, a1)*ccw(b1, b2, a2) <= 0;

}





int main(void){

    int n;

    while(cin>>n, n){

        VP c(n);

        vector<double> r(n);

        rep(i,n){

            double x,y;

            cin>>x>>y>>r[i];

            c[i] = {x,y};

        }



        vector<VP> ps(n+1);

        ps[0] = {c[0],c[0]};

        ps[n] = {c[n-1],c[n-1]};

        rep(i,n-1){

            ps[i+1] = crosspointCC(c[i],r[i],c[i+1],r[i+1]);

        }



        double d[210][210]={};

        rep(i,210)rep(j,210)d[i][j]=1e8;

        rep(i,n) FOR(j,i+1,n+1) rep(i2,2) rep(j2,2) {

            bool connect=true;

            FOR(k,i+1,j) {

                connect &= isecSS(ps[i][i2],ps[j][j2],ps[k][0],ps[k][1]);

            }

            if(connect){

                d[i*2+i2][j*2+j2] = abs(ps[i][i2]-ps[j][j2]);

            }



        }



        rep(k,n*2+2)rep(i,n*2+2)rep(j,n*2+2)

            d[i][j] = min(d[i][j], d[i][k]+d[k][j]);



        printf("%.9f\n",d[0][n*2]);

    }

    return 0;

}