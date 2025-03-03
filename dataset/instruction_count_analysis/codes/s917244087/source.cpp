#include "stdc++.h"

#define x real()

#define y imag()

using namespace std;

typedef complex<double> point;



double dot(point a,point b){return a.x*b.x+a.y*b.y;}

double cross(point a,point b){return a.x*b.y-a.y*b.x;}

int ccw(point a,point b,point c){

  point d = b-a,e = c-a;

  if(cross(d,e)>0) return 1;//"COUNTER_CLOCKWISE"

  if(cross(d,e)<0) return -1;//"CLOCKWISE"

  if(dot(d,e)<0) return 2;//"ONLINE_BACK"

  if(abs(d) < abs(e)) return -2;//"ONLINE_FRONT"

  return 0;//"ON_SEGMENT"

}



point crosspoint(point a,point b,point c,point d){

  a-=d;b-=d;c-=d;

  return d+a+(b-a)*imag(a/c)/imag(a/c-b/c);

}



vector<point> ConvexCut(vector<point> &polygon,point a,point b){

  vector <point> res;

  for(int i=0;i<polygon.size();i++){

    point A=polygon[i],B=polygon[(i+1)%polygon.size()];

    if(ccw(a,b,A)!=-1)res.push_back(A);

    if(ccw(a,b,A)*ccw(a,b,B)==-1)res.push_back(crosspoint(a,b,A,B));

  }

  return res;

}



double get_area(vector <point> &polygon){

  if(polygon.size()<3)return 0;

  double res=0;

  for(int i=0;i<polygon.size();i++)

    res+=cross(polygon[i],polygon[(i+1)%polygon.size()])/2;

  return res;

}



int main(){

  while(1){

    int n,d;

    double V;

    vector <point> pl;

    cin>>n>>d>>V;

    if(!n&&!d&&!V) break;

    for(int i=0,a,b;i<n;i++) cin>>a>>b,pl.push_back(point(a,b));

    V=min(get_area(pl)*d,V);



    double ans=0;

    for(int i=0;i<n;i++){

      double L=0,M,R=2010;

      int I=100;

      while(I--){

	M=(L+R)/2;

	point h=pl[(i+1)%n]-pl[i],b=h;

	h=(point(0,M)*h/abs(h))+pl[i];

	vector<point> a=ConvexCut(pl,h+b,h);

	if(get_area(a)*d>=V)R=M;

	else L=M+0.00000001;

      }

      ans=max(ans,L);

    }

    printf("%.8f\n",ans);

  }

  return 0;

}