#include<complex>

#include<vector>

#include<iostream>

#include<stack>

#include<cstdlib>

#include<fstream>

#include<cmath>

#include<map>

#include<cassert>

#include<iomanip>



enum CCW{FRONT=0x01,RIGHT=0x02,BACK=0x04,LEFT=0x08,OVER=0x10};

#define sc second

#define fr first



#define REP(i,n) for(int i = 0; i < (int)(n); ++i)



using namespace std;



typedef long double elem;

typedef complex<elem> point, vec;

typedef pair<point, point> line, hline, seg, pp;



const elem infty = 1e40;

const elem eps = 1.0e-8;

const elem pi = acos(-1.0);

point base(0,0);

inline elem Round(elem a)

{

  return (elem)floor(eps+round(a));

}

inline bool eq(elem a, elem b){ return abs(a-b) < eps; }

inline elem dot(vec a, vec b){ return (a.real() * b.real() + a.imag() * b.imag() ); }

inline elem cross(vec a, vec b){ return ( a.real() * b.imag() - a.imag() * b.real() ); }

inline elem dist(point a, point b){ return abs(a-b); }

inline elem dist_l(line l, point x){ return abs(cross(l.sc-l.fr,x-l.fr)) / abs(l.sc-l.fr); }

inline elem dist_seg(seg s, point x)

{

  if( dot(s.sc-s.fr,x-s.fr)<0 ) return abs(x-s.fr);

  if( dot(s.fr-s.sc,x-s.sc)<0 ) return abs(x-s.sc);

  return dist_l(s,x);

}

inline vec uvec(vec a){ return a / abs(a); }



inline int ccw(const point &a, point b, point x){

  b -= a;

  x -= a;

  if( eq(cross(b,x),0.0) && dot(b,x) < 0 ) return BACK;

  if( eq(cross(b,x),0.0) && abs(b) < abs(x) ) return FRONT;

  if( eq(cross(b,x),0.0) ) return OVER;

  if( cross(b,x) > 0 ) return LEFT;

  if( cross(b,x) < 0 ) return RIGHT;

}



inline bool intersectedSS(const seg &a, const seg &b)

{

  int cwaf=ccw(a.fr,a.sc,b.fr);

  int cwbf=ccw(b.fr,b.sc,a.fr);

  int cwas=ccw(a.fr,a.sc,b.sc);

  int cwbs=ccw(b.fr,b.sc,a.sc);

  if( cwaf==OVER || cwas==OVER || cwbf==OVER || cwbs==OVER ) return true;

  return ( cwaf | cwas ) == (LEFT|RIGHT) && ( cwbf | cwbs ) == (LEFT|RIGHT);

}



inline bool intersectedLL(line a, line b){ return !eq( cross(a.sc-a.fr,b.sc-b.fr), 0.0 ); }



inline point intersectionSS(seg a, seg b)

{

  elem d1 = dist_l(b,a.fr);

  elem d2 = dist_l(b,a.sc);

  return a.fr + ( d1 / (d1 + d2 ) ) * (a.sc-a.fr);

}



inline point intersectionLL(line a, line b)

{

  vec va = a.sc - a.fr;

  vec vb = b.sc - b.fr;

  return a.fr + va * ( cross(vb, b.fr - a.fr) / cross(vb,va) );

}



inline bool intersectionLL(line a, line b, point &ret){

  return intersectedLL( a, b ) ? ret = intersectionLL( a, b ), true : false;

}



inline bool intersectionLS(line l, seg s, point &ret){

  point tmp;

  return intersectionLL(l,s,tmp) ? ( ccw(s.fr,s.sc,tmp)&OVER ? ret=tmp, true : false ) : false;

}



struct triangle{

  vector<point> p;

  triangle():p(3,point(0,0)){}

  triangle(point a,point b,point c){p.push_back(a);p.push_back(b);p.push_back(c);}

  bool contains(point t)const{

    int ccw01=ccw(p[0],p[1],t),ccw02=ccw(p[1],p[2],t),ccw03=ccw(p[2],p[0],t);

    return ccw01==ccw02&&ccw02==ccw03;

  }

};



point getHasMaximumDot(point base1, point base2, const vector<point> &vp)

{

  vec u = uvec(base2 - base1);

  int i0 = -1;

  elem maximumDot = -10;

  for(int i = 0; i < (int)vp.size(); ++i){

    vec v = uvec(vp[i] - base1);

    elem d = dot(u,v);

    if( d >= maximumDot){

      maximumDot = d;

      i0 = i;

    }

  }

  return vp[i0];

}



struct StringP{

  point p;

  bool fixed;

  vector<char> state;

  StringP(){}

  StringP(point ip, bool ifixed, vector<char> istate):p(ip),fixed(ifixed),state(istate.begin(),istate.end()){}

};



int tightenUp(vector<StringP> &V)

{

  if(V.size()<=2)return -1;

  for(int i = 1; i < (int)V.size()-1; ++i){

    StringP &a = V[i-1];

    StringP &b = V[i];

    StringP &c = V[i+1];



    int cw = ccw(a.p,b.p,c.p);

    

    if( cw == RIGHT && b.state.size() == 1 && b.state.front()=='R' ){

      b.fixed = false;

      return i;

    }

    if( cw == LEFT && b.state.size() == 1 &&  b.state.front()=='L' ){

      b.fixed = false;

      return i;

    }

  }

  return -1;

}



bool fixNext(vector<StringP> &str,

	     int &now,

	     const vector<point> &pins)

{ 

  //if(now<=0||now>=(int)str.size()-1||(int)str.size()<=2){++now;return false;}

  if( str[now].fixed ){

    ++now;

    return false;

  }



  point sa = str[now-1].p;

  point sb = str[now].p;

  point sc = str[now+1].p;

  

  if(ccw(sa,sb,sc)&(OVER|FRONT|BACK)){

    now=0;

    return false;

  }

  triangle tri(sa,sb,sc);

  vector<point> in;

  for(int i = 0; i < (int)pins.size(); ++i){

    if(tri.contains( pins[i] )){

      in.push_back(pins[i]);

    }

  }



  if( in.size() == 0 ){

    str.erase(str.begin()+now);

    return true;

  }else{

    point nextFixed = getHasMaximumDot( sa, sb, in );

    int cw = ccw(sa,nextFixed,sb);

    line l(sa,nextFixed);

    seg s(sb,sc);

    point is;



    intersectionLS(l,s,is);

    str[now]=StringP(is,false,vector<char>(0));



    if( cw == RIGHT ){

      str.insert( str.begin()+now, StringP(nextFixed,true,vector<char>(1,'R')));

    }else if( cw == LEFT ){

      str.insert( str.begin()+now, StringP(nextFixed,true,vector<char>(1,'L')));

    }

    return true;

  }

}



point roundPoint(point p){

  return point(Round(p.real()),Round(p.imag()));

}



elem getLength(const vector<StringP> &V){

  elem ret = 0;

  for(int i = 0; i < (int)V.size()-1; ++i){

    ret += abs(roundPoint(V[i].p)-roundPoint(V[i+1].p));

  }

  return ret;

}



int main(){

  while(true){

    int m,n;

    vector<point> pins;

    vector<StringP> str;



    cin >> m >> n;

    if(m==0&&n==0)break;

    for(int i = 0; i < m; ++i){

      elem x,y;

      scanf("%Lf%Lf", &x, &y);

      str.push_back(StringP(point(x,y),false,vector<char>(0)));

    }

    for(int j = 0; j < n; ++j){

      elem x,y;

      scanf("%Lf%Lf", &x, &y);

      //pins.push_back(point(x+0.0017,y+0.0022));

      //pins.push_back(point(x-0.0011,y+0.0035));

      pins.push_back(point(x+0.0019,y-0.0043));

      pins.push_back(point(x-0.0023,y-0.0027));

    }

    str.front().fixed = true;

    str.back().fixed = true;

    str.front().state.push_back('X');

    str.back().state.push_back('X');



    int now = 0;

    int next;

    while(now<(int)str.size()){

      fixNext(str,now,pins);

      next= tightenUp(str);

      if( next >= 0 ) now = next;

    }

    printf("%.12Lf\n", getLength(str));

  }

  return 0;

}