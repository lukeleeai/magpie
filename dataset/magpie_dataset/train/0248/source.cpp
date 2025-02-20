#include"stdc++.h"



#define REP(i,s,n) for(int i=s;i<n;i++)

#define rep(i,n) REP(i,0,n)

#define IINF (INT_MAX)

#define EPS (1e-7)

#define COUNTER_CLOCKWISE 1

#define CLOCKWISE -1 

#define ONLINE_BACK 2

#define ONLINE_FRONT -2

#define ON_SEGMENT 0

#define equals(a,b) (fabs((a)-(b)) < EPS)



using namespace std;



// Library - template - begin



class Point{

public:

  double x,y;



  Point(double x = -IINF,double y = -IINF): x(x),y(y){}



  Point operator + (Point p){return Point(x+p.x,y+p.y);}

  Point operator - (Point p){return Point(x-p.x,y-p.y);}

  Point operator * (double a){return Point(a*x,a*y);}

  Point operator / (double a){return Point(x/a,y/a);}

  Point operator * (Point a){ return Point(x * a.x - y * a.y, x * a.y + y * a.x); }



  bool operator < (const Point& p) const{ return !equals(x,p.x)?x<p.x:y<p.y; }



  bool operator == (const Point& p)const{ return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS; }



};



struct Segment{

  Point p1,p2;

  Segment(Point p1 = Point(),Point p2 = Point()):p1(p1),p2(p2){}

  bool operator == (const Segment& p)const { return p.p1 == p1 && p.p2 == p2; }

};



typedef Point Vector;

typedef Segment Line;

typedef vector<Point> Polygon;



ostream& operator << (ostream& os,const Point& a){ os << "(" << a.x << "," << a.y << ")"; }



ostream& operator << (ostream& os,const Segment& a){ os << "( " << a.p1 << " , " << a.p2 << " )"; }



double dot(Point a,Point b){ return a.x*b.x + a.y*b.y; }



double cross(Point a,Point b){ return a.x*b.y - a.y*b.x; }



double norm(Point a){ return a.x*a.x+a.y*a.y; }



double abs(Point a){ return sqrt(norm(a)); }



Point rotate(Point a,double rad){ return Point(cos(rad)*a.x - sin(rad)*a.y,sin(rad)*a.x + cos(rad)*a.y); }



double toRad(double agl){ return agl*M_PI/180.0; }



// Library - template - end



// Library - CCW - begin



int ccw(Point p0,Point p1,Point p2){

  Point a = p1-p0;

  Point b = p2-p0;

  if(cross(a,b) > EPS)return COUNTER_CLOCKWISE;

  if(cross(a,b) < -EPS)return CLOCKWISE;

  if(dot(a,b) < -EPS)return ONLINE_BACK;

  if(norm(a) < norm(b))return ONLINE_FRONT;

  return ON_SEGMENT;

}



// Library - CCW - end



// Library - intersect - begin





bool intersectLL(Line l, Line m) {

  return abs(cross(l.p2-l.p1, m.p2-m.p1)) > EPS || // non-parallel

         abs(cross(l.p2-l.p1, m.p1-l.p1)) < EPS;   // same line

}

bool intersectLS(Line l, Line s) {

  return cross(l.p2-l.p1, s.p1-l.p1)*       // s[0] is left of l

         cross(l.p2-l.p1, s.p2-l.p1) < EPS; // s[1] is right of l

}

bool intersectLP(Line l,Point p) {

  return abs(cross(l.p2-p, l.p1-p)) < EPS;

}

bool intersectSS(Line s, Line t) {

  return ccw(s.p1,s.p2,t.p1)*ccw(s.p1,s.p2,t.p2) <= 0 &&

         ccw(t.p1,t.p2,s.p1)*ccw(t.p1,t.p2,s.p2) <= 0;

}

bool intersectSP(Line s, Point p) {

  return abs(s.p1-p)+abs(s.p2-p)-abs(s.p2-s.p1) < EPS; // triangle inequality

}



Point projection(Line l,Point p) {

  double t = dot(p-l.p1, l.p1-l.p2) / norm(l.p1-l.p2);

  return l.p1 + (l.p1-l.p2)*t;

}

Point reflection(Line l,Point p) {

  return p + (projection(l, p) - p) * 2;

}

double distanceLP(Line l, Point p) {

  return abs(p - projection(l, p));

}

double distanceLL(Line l, Line m) {

  return intersectLL(l, m) ? 0 : distanceLP(l, m.p1);

}



double distanceLS(Line l, Line s) {

  if (intersectLS(l, s)) return 0;

  return min(distanceLP(l, s.p1), distanceLP(l, s.p2));

}

double distanceSP(Line s, Point p) {

  Point r = projection(s, p);

  if (intersectSP(s, r)) return abs(r - p);

  return min(abs(s.p1 - p), abs(s.p2 - p));

}



double distanceSS(Line s, Line t) {

  if (intersectSS(s, t)) return 0;

  return min(min(distanceSP(s, t.p1), distanceSP(s, t.p2)),

             min(distanceSP(t, s.p1), distanceSP(t, s.p2)));

}



Point crosspoint(Line l,Line m){

  double A = cross(l.p2-l.p1,m.p2-m.p1);

  double B = cross(l.p2-l.p1,l.p2-m.p1);

  if(abs(A) < EPS && abs(B) < EPS){

    vector<Point> vec;

    vec.push_back(l.p1),vec.push_back(l.p2),vec.push_back(m.p1),vec.push_back(m.p2);

    sort(vec.begin(),vec.end());

    assert(vec[1] == vec[2]);

    return vec[1];

  }

  if(abs(A) < EPS)assert(false);

  return m.p1 + (m.p2-m.p1)*(B/A);

}



// Library - intersect - end



// Library - area - begin



double getArea(const vector<Point>& vec){

  double sum = 0;

  rep(i,vec.size())sum += cross(vec[i],vec[(i+1)%vec.size()]);

  return fabs(sum)/2.0;

}



// Library - area - end



// Library - PolygonCut - begin



Point getCrossPointLines( Line s1, Line s2){

    Point a = s1.p2 - s1.p1;

    Point base = Point(s2.p2.x - s2.p1.x,s2.p2.y - s2.p1.y);

    return s1.p1 + a * (cross(base, s2.p1 - s1.p1)/cross(base, a));

}



Polygon cutPolygon( Polygon P, Line l ){

    Polygon u;

    for ( int i = 0; i < P.size(); i++ ){

        Point a = P[i], b = P[(i+1)%P.size()];

        if ( ccw(l.p1, l.p2, a) != CLOCKWISE ) u.push_back(a);

        if ( ccw(l.p1, l.p2, a) * ccw(l.p1, l.p2, b) == -1 ){

      u.push_back(getCrossPointLines(Segment(a, b), l));

        }

    }

    return u;

}



// Library - PolygonCut - end



int N;

Polygon poly;

Vector o,e;

double area;



inline bool check(double rad){ // if left polygon's area < right polygon's area return true

  Vector v = rotate(e,rad);

  double tmp_L = getArea(cutPolygon(poly,Line(o,v)));

  double tmp_R = area - tmp_L;

  return !equals(tmp_L,tmp_R) && tmp_L < tmp_R;

}



int main(){

  o = Vector(0,0);

  e = Vector(1,0);

  while(cin >> N,N){

    poly.resize(N);

    rep(i,N)cin >> poly[i].x >> poly[i].y;



    area = getArea(poly);



    double L = 0, R = toRad(180.5), M = IINF;



    double tmp_T = getArea(cutPolygon(poly,Line(Point(0,0),e)));

    double tmp_B = area - tmp_T;



    if( !equals(tmp_B,tmp_T) && tmp_B > tmp_T ) swap(L,R);



    rep(_,220){

      M = ( L + R ) * 0.5;

      if(check(M)) R = M;

      else         L = M;

    }

    Point ans = rotate(e,L);

    printf("%.15f %.15f\n",ans.x,ans.y);

    //double AREA = getArea(cutPolygon(poly,Line(o,ans)));

    //cout << AREA << " " << area - AREA << endl;

  }

  return 0;

}