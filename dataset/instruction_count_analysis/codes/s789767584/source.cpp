#include"stdc++.h"

#define f first

#define s second

#define mp make_pair

#define pi M_PI

#define inf 1<<30

#define eps (1e-5)

#define equals(a,b) (fabs((a)-(b))<eps)

using namespace std;



class Point{

public:

  double x,y;

  Point(double x=0,double y=0):x(x),y(y){}



  Point operator+(Point p){ return Point(x+p.x,y+p.y);}

  Point operator-(Point p){ return Point(x-p.x,y-p.y);}

  Point operator*(double k){ return Point(x*k,y*k);}

  Point operator/(double k){ return Point(x/k,y/k);}

  bool operator<(Point p)const{ return (x!=p.x ? x<p.x : y<p.y);}

  bool operator==(Point p)const{ return fabs(x-p.x)<eps && fabs(y-p.y)<eps;}



  double abs(){ return sqrt(norm());}

  double norm(){ return (x*x+y*y);}

};

typedef Point Vector;

typedef vector<Point> Polygon;



class Segment{

public:

  Point p1,p2;

  Segment(Point p1,Point p2):p1(p1),p2(p2){}

};

typedef Segment Line;



class Circle{

public:

  Point c;

  double r;

  Circle(Point c=Point(),double r=0.0):c(c),r(r){}

};



double norm(Vector a){ return (a.x*a.x+a.y*a.y);}

double abs(Vector a){ return sqrt(norm(a));}

double dot(Vector a,Vector b){ return (a.x*b.x+a.y*b.y);}

double cross(Vector a,Vector b){ return (a.x*b.y-a.y*b.x);}



Point rotationPoint(Point base,Point a,double r){

  Point b=a-base;

  a.x=b.x*cos((r/180)*M_PI)-b.y*sin((r/180)*M_PI);

  a.y=b.x*sin((r/180)*M_PI)+b.y*cos((r/180)*M_PI);

  a=a+base;

  return a;

}



double getDistanceLP(Line l,Point p){

  return abs(cross(l.p2-l.p1,p-l.p1)/abs(l.p2-l.p1));

}



bool iscrossCL1(Circle c,Line l){

  if((getDistanceLP(l,c.c)-c.r)<-eps)return true;

  return false;

}

bool iscrossCL2(Circle c,Line l){

  if((getDistanceLP(l,c.c)-c.r)<eps)return true;

  return false;

}



vector<Line> getLines(Circle a,Circle b){

  vector<Line> V;

  double d=abs(b.c-a.c);

  Vector v=(b.c-a.c)/d,v1=v*a.r,v2=v*b.r;

  double c,s;

  Point p1,p2;



  c=sqrt(d*d-(a.r-b.r)*(a.r-b.r));

  s=(180*asin(c/d))/pi;



  p1=rotationPoint(a.c,a.c+v1,s);

  p2=rotationPoint(b.c,b.c-v2,180+s);

  V.push_back(Line(p1,p2));

  p1=rotationPoint(a.c,a.c+v1,360-s);

  p2=rotationPoint(b.c,b.c-v2,180-s);

  V.push_back(Line(p1,p2));



  c=sqrt(d*d-(a.r+b.r)*(a.r+b.r));

  s=(180*asin(c/d))/pi;



  p1=rotationPoint(a.c,a.c+v1,s);

  p2=rotationPoint(b.c,b.c-v2,s);

  V.push_back(Line(p1,p2));

  p1=rotationPoint(a.c,a.c+v1,360-s);

  p2=rotationPoint(b.c,b.c-v2,360-s);

  V.push_back(Line(p1,p2));



  return V;

}



int main()

{

  int n,a,b,c,d;



  while(1){

    cin>>n;

    if(n==0)break;

    vector<pair<Circle,Circle> > v;

    for(int i=0;i<n;i++){

      cin>>a>>b>>c>>d;

      v.push_back(mp(Circle(Point(a,b),c),Circle(Point(a,b),c+d)));

    }

    int ans=1;

    for(int i=0;i<n;i++){

      for(int j=0;j<n;j++){

	vector<Line> V;

	vector<Line> v1=getLines(v[i].f,v[j].f);

	vector<Line> v2=getLines(v[i].f,v[j].s);

	vector<Line> v3=getLines(v[i].s,v[j].f);

	vector<Line> v4=getLines(v[i].s,v[j].s);

	V.insert(V.begin(),v1.begin(),v1.end());

	V.insert(V.begin(),v2.begin(),v2.end());

	V.insert(V.begin(),v3.begin(),v3.end());

	V.insert(V.begin(),v4.begin(),v4.end());

	for(int k=0;k<V.size();k++){

	  int sum=0;

	  for(int z=0;z<n;z++){

	    if(!iscrossCL1(v[z].f,V[k]) && iscrossCL2(v[z].s,V[k]))sum++;

	  }

	  ans=max(ans,sum);

	}

      }

    }

    cout<<ans<<endl;

  }

  return 0;

}