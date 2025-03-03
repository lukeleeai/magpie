#include<iostream>

#include<cmath>

#include<vector>

#include<algorithm>

#include<cstdio>

#include<cassert>

#include<climits>



#define REP(i,s,n) for(int i=s;i<n;i++)

#define rep(i,n) REP(i,0,n)

#define IINF (INT_MAX)

#define MAX 40000

#define EPS (1e-6)

#define COUNTER_CLOCKWISE 1

#define CLOCKWISE -1 

#define ONLINE_BACK 2

#define ONLINE_FRONT -2

#define ON_SEGMENT 0

#define equals(a,b) (fabs((a)-(b)) < EPS)



using namespace std;



// Library - template - begin



class Point

{

  public:

  double x,y;



  Point(double x = -IINF,double y = -IINF): x(x),y(y){}



  Point operator + (Point p){return Point(x+p.x,y+p.y);}

  Point operator - (Point p){return Point(x-p.x,y-p.y);}

  Point operator * (double a){return Point(a*x,a*y);}

  Point operator / (double a){return Point(x/a,y/a);}

  Point operator * (Point a){ return Point(x * a.x - y * a.y, x * a.y + y * a.x); }



  bool operator < (const Point& p) const

  {

    return !equals(y,p.y)?y<p.y:x<p.x;

  }



  bool operator == (const Point& p)const

  {

    return fabs(x-p.x) < EPS && fabs(y-p.y) < EPS;

  }



};



struct Segment

{

  Point p1,p2;

  Segment(Point p1 = Point(),Point p2 = Point()):p1(p1),p2(p2){}

  bool operator == (const Segment& p)const

  {

    return p.p1 == p1 && p.p2 == p2;

  }

};



typedef Point Vector;

typedef Segment Line;

typedef vector<Point> Polygon;



ostream& operator << (ostream& os,const Point& a)

{

  os << "(" << a.x << "," << a.y << ")";

}



ostream& operator << (ostream& os,const Segment& a)

{

  os << "( " << a.p1 << " , " << a.p2 << " )";

}



double dot(Point a,Point b){ return a.x*b.x + a.y*b.y; }



double cross(Point a,Point b){ return a.x*b.y - a.y*b.x; }



double norm(Point a){ return a.x*a.x+a.y*a.y; }



double abs(Point a){ return sqrt(norm(a)); }



//rad は角度をラジアンで持たせること

Point rotate(Point a,double rad){ return Point(cos(rad)*a.x - sin(rad)*a.y,sin(rad)*a.x + cos(rad)*a.y); }



// 度をラジアンに変換

double toRad(double agl){ return agl*M_PI/180.0; }



// Library - template - end



// Library - ccw - begin



int ccw(Point p0,Point p1,Point p2){

  Point a = p1-p0;

  Point b = p2-p0;

  if(cross(a,b) > EPS)return COUNTER_CLOCKWISE;

  if(cross(a,b) < -EPS)return CLOCKWISE;

  if(dot(a,b) < -EPS)return ONLINE_BACK;

  if(norm(a) < norm(b))return ONLINE_FRONT;

  return ON_SEGMENT;

}



// Library - ccw - end



// Library - inPolygon - begin



//cross product of pq and pr

double cross3p(Point p,Point q,Point r)

{

  return (r.x-q.x) * (p.y -q.y) - (r.y - q.y) * (p.x - q.x);

}

  

//returns true if point r is on the same line as the line pq

bool collinear(Point p,Point q,Point r)

{

  return fabs(cross3p(p,q,r)) < EPS;

}

  

//returns true if point t is on the left side of line pq

bool ccwtest(Point p,Point q,Point r)

{

  return cross3p(p,q,r) > 0;//can be modified to accept collinear points

}

 

bool onSegment(Point p,Point q,Point r)

{

  return collinear(p,q,r) && equals(sqrt(pow(p.x-r.x,2)+pow(p.y-r.y,2)) + sqrt(pow(r.x-q.x,2) + pow(r.y-q.y,2) ),sqrt(pow(p.x-q.x,2)+pow(p.y-q.y,2)) ) ;

}

  



bool isConvex(vector<Point> p)

{

  int sz = (int)p.size();

  

  if(sz < 3)return false;//boundary case, we treat a point or a line as not convex

  

  bool isLeft = ccwtest(p[0],p[1],p[2]);

  

  for(int i=1; i<(int)p.size();i++)

    if(ccwtest(p[i],p[(i+1)%sz],p[(i+2)%sz]) != isLeft)

      return false;

  

  return true;

}





double angle(Point a,Point b,Point c)

{

  double ux = b.x - a.x, uy = b.y - a.y;

  double vx = c.x - a.x, vy = c.y - a.y;

  return acos((ux*vx + uy*vy)/sqrt((ux*ux + uy*uy) * (vx*vx + vy*vy)));

}  

  

//多角形poly内（線分上も含む）に点pが存在するかどうは判定する  

bool inPolygon(Polygon poly,Point p)

{

  if((int)poly.size() == 0)return false;



  rep(i,poly.size())

  if(onSegment(poly[i],poly[(i+1)%poly.size()],p))return true;

  double sum = 0;

  for(int i=0; i < (int)poly.size() ;i++)

    {

      if(cross3p(p,poly[i],poly[(i+1)%poly.size()]) < 0)

	sum -= angle(p,poly[i],poly[(i+1)%poly.size()]);

      else

	sum += angle(p,poly[i],poly[(i+1)%poly.size()]);

    }

  return (fabs(sum - 2*M_PI) < EPS || fabs(sum + 2*M_PI) < EPS);



}  



// Library - inPolygon - end



// Library - area - begin



double getArea(vector<Point> vec)

{

  double sum = 0;

  for(int i=0;i<vec.size();i++)

    sum += cross(vec[i],vec[(i+1)%vec.size()]);

  return fabs(sum)/2.0;

}



// Library - area - end



int n,m,w,h,s;

double S,l[MAX],r[MAX];

Point ps[MAX];

Polygon poly[MAX];

int almond[MAX],talmond[MAX];

double area[MAX],total[MAX];



bool check(int M,int index){

  Polygon npoly;

  int len = poly[M].size();

  npoly.push_back(poly[M][len-2]), npoly.push_back(poly[M][len-1]);

  if(!(npoly[1] == Point(0,0)))npoly.push_back(Point(0,0));

  if(!(npoly[0] == Point(w,0)))npoly.push_back(Point(w,0));

  return inPolygon(npoly,ps[index]);

}





int main(){



  while(cin >> n >> m >> w >> h >> s,n|m|w|h|s){

    S = s;

    Point p1 = Point(0,0);

    Point p2 = Point((double)w,0);

    rep(i,m){

      almond[i] = 0;

      poly[i].clear();

      cin >> l[i] >> r[i];

      if(!(p1 == Point(0,l[i])))

      poly[i].push_back(p1);

      poly[i].push_back(p2);

      if(!(Point(w,r[i]) == p2))poly[i].push_back(Point(w,r[i]));

      poly[i].push_back(Point(0,l[i]));

      p1 = Point(0,l[i]), p2 = Point((double)w,r[i]);

      area[i] = getArea(poly[i]);

      almond[i] = 0;

    }

    rep(i,n) cin >> ps[i].x >> ps[i].y;

    if(s == 0){

      cout << 0 << endl;

      continue;

    }

    rep(i,n){

      int L = 0, R = m,M;

      while(L < R){

	M = (L+R)/2;

	if(inPolygon(poly[M],ps[i])) break;

	else if(check(M,i)) R = M;

	else L = M+1;

      }

      if(inPolygon(poly[M],ps[i]))almond[M]++;

      else if(inPolygon(poly[L],ps[i]))almond[L]++;

      else if(R<m&&inPolygon(poly[R],ps[i]))almond[R]++;

      else assert(false);

    }



    total[0] = area[m-1];

    talmond[0] = almond[m-1];

    REP(i,1,m){

      total[i] = total[i-1] + area[m-1-i];

      talmond[i] = talmond[i-1] + almond[m-1-i];

    }



    int ans = IINF;

    double remain = 0;

    int counter = 0;

    int pos = lower_bound(total,total+m,S) - total;

    ans = min(ans,talmond[pos]);



    rep(i,m){

      double cost = ( (i == m-1) ? 0 : total[m-1-i-1] );

      int cost2 =   ( (i == m-1) ? 0 : talmond[m-1-i-1]);

      remain = total[m-1] - cost;

      counter = talmond[m-1] - cost2;

      if(equals(remain,S) || remain > S){

	ans = min(ans,counter);

	continue;

      }

      pos = lower_bound(total,total+m,(double)(S-remain)) - total;

      if(m-1-pos <= i)continue;

      double fofpwaejfoaw = total[pos] + remain;

      if(equals(fofpwaejfoaw,S) || fofpwaejfoaw > S){

	int add = talmond[pos];

	ans = min(ans,add+counter);

      }

    }

    cout << ans << endl;

  }

  return 0;

}