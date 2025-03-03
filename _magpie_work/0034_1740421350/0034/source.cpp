/**************** Geometrical Library ****************/



#include<cmath>

#include<vector>

#include<algorithm>



#define	EPS	1e-9



enum {CCW=1,CW=-1,ON=0};



#define	mp	make_pair

#define	pb	push_back



using namespace std;



class Point{

public:

	double x,y;

	Point(){}

	Point(double xx,double yy):x(xx),y(yy){}

};



class Line:public vector<Point>{

public:

	Line(const Point &a,const Point &b){

		pb(a),pb(b);

	}

};



class Segment:public Line{

public:

	Segment(const Point &a,const Point &b):Line(a,b){}

};



class Polygon:public vector<Point>{};



class Circle{

public:

	Point c;

	double r;

	Circle(const Point &cc,double rr) : c(cc),r(rr){}

};



Point &operator +=(Point &a,const Point &b){

	a.x+=b.x,a.y+=b.y;

	return a;

}



Point &operator -=(Point &a,const Point &b){

	a.x-=b.x,a.y-=b.y;

	return a;

}



Point &operator *=(Point &a,double c){

	a.x*=c,a.y*=c;

	return a;

}



Point &operator /=(Point &a,double c){

	a.x/=c,a.y/=c;

	return a;

}



Point operator +(const Point &a,const Point &b){

	Point c=a;

	return c+=b;

}



Point operator -(const Point &a,const Point &b){

	Point c=a;

	return c-=b;

}



Point operator *(double c,const Point &a){

	Point b=a;

	return b*=c;

}



Point operator /(const Point &a,double c){

	Point b=a;

	return b/=c;

}



bool operator <(const Point &a,const Point &b){

	return (a.x==b.x)?(a.y<b.y):(a.x<b.x);

}



bool operator >(const Point &a,const Point &b){

	return b<a;

}



double dot(const Point &a,const Point &b){

	return a.x*b.x+a.y*b.y;

}



double cross(const Point &a,const Point &b){

	return a.x*b.y-a.y*b.x;

}



double dis2(const Point &a,const Point &b){

	return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);

}



int ccw(const Point &a,Point b,Point c){

	b-=a,c-=a;

	double rotdir=cross(b,c);

	if(rotdir>EPS)		return CCW;

	if(rotdir<-EPS)		return CW;

	return ON;

}



Polygon ConvexHull(vector<Point> ps){

	int n=ps.size();

	sort(ps.begin(),ps.end());



	vector<Point> ch_u(n);

	int n_u=0;

	for(int i=n-1;i>=0;i--){

		ch_u[n_u++]=ps[i];

		while(n_u>=3 && ccw(ch_u[n_u-3],ch_u[n_u-2],ch_u[n_u-1])!=CCW){

			ch_u[n_u-2]=ch_u[n_u-1];

			n_u--;

		}

	}



	vector<Point> ch_l(n);

	int n_l=0;

	for(int i=0;i<n;i++){

		ch_l[n_l++]=ps[i];

		while(n_l>=3 && ccw(ch_l[n_l-3],ch_l[n_l-2],ch_l[n_l-1])!=CCW){

			ch_l[n_l-2]=ch_l[n_l-1];

			n_l--;

		}

	}



	Polygon ch;

	for(int i=0;i<n_u-1;i++)	ch.pb(ch_u[i]);

	for(int i=0;i<n_l-1;i++)	ch.pb(ch_l[i]);

	return ch;

}

/*

bool parallel(const Line &l,const Line &m){

	return abs(cross(l[1]-l[0],m[1]-m[0]))<EPS;

}



bool orthogonal(const Line &l,const Line &m){

	return abs(dot(l[1]-l[0],m[1]-m[0]))<EPS;

}

*/

inline void calc_abc(const Line &l,double &a,double &b,double &c){	// l : ax+by+c=0

	a=l[0].y-l[1].y;

	b=l[1].x-l[0].x;

	c=l[0].x*l[1].y-l[1].x*l[0].y;

}



bool intersect(const Line &l,const Line &m,Point *p=NULL){

	// this routine also returns true in case "M is on L", "M sessuru L", etc,.

	if(abs(cross(l[1]-l[0],m[1]-m[0]))>EPS

	|| abs(cross(l[1]-l[0],m[0]-l[0]))<EPS){

		if(p){

			double a1,b1,c1,a2,b2,c2;

			calc_abc(l,a1,b1,c1);

			calc_abc(m,a2,b2,c2);

			double det=a1*b2-a2*b1;

			if(abs(det)<EPS)	*p=l[0];	// l == m

			else{

				p->x=(b1*c2-b2*c1)/det;

				p->y=(a2*c1-a1*c2)/det;

			}

		}

		return true;

	}

	return false;

}



bool intersect(const Segment &s,const Segment &t,Point *p=NULL){

	if(max(s[0].x,s[1].x)<min(t[0].x,t[1].x)

	|| max(t[0].x,t[1].x)<min(s[0].x,s[1].x)

	|| max(s[0].y,s[1].y)<min(t[0].y,t[1].y)

	|| max(t[0].y,t[1].y)<min(s[0].y,s[1].y))	return false;



	if(ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1])<=0

	&& ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1])<=0){

		if(p){

			double a1,b1,c1,a2,b2,c2;

			calc_abc(s,a1,b1,c1);

			calc_abc(t,a2,b2,c2);

			double det=a1*b2-a2*b1;

			if(abs(det)<EPS){	// s is parallel to t

				Point q[3]={s[0],s[1],t[0]};

				for(int i=0;i<3;i++){

					if(dot(q[i]-s[0],q[i]-s[1])<EPS && dot(q[i]-t[0],q[i]-t[1])<EPS){

						*p=q[i];

						break;

					}

				}

			}

			else{

				p->x=(b1*c2-b2*c1)/det;

				p->y=(a2*c1-a1*c2)/det;

			}

		}

		return true;

	}

	return false;

}



Point perp_foot(const Point &p,const Line &l){

	double a,b,c;

	calc_abc(l,a,b,c);

	return p-(a*p.x+b*p.y+c)/(a*a+b*b)*Point(a,b);

}



Line perp_bisector(const Point &a,const Point &b){

	return Line(Point((a.x+a.y+b.x-b.y)/2,(b.x+b.y-a.x+a.y)/2),

				Point((b.x+b.y+a.x-a.y)/2,(a.x+a.y-b.x+b.y)/2));

}

/*

double area(const Point &a,const Point &b,const Point &c){

	return abs(cross(b-a,c-a))/2;

}

*/

double area(const Polygon &pl){

	int n=pl.size();

	double a=0;

	for(int i=0;i<n;i++)	a+=cross(pl[i],pl[(i+1)%n]);

	return abs(a)/2;

}



/**************** Library END ****************/



#include<cstdio>



int main(){

	int n;	scanf("%d",&n);

	while(n--){

		Point a,b,c,star[2];

		scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",

			&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&star[0].x,&star[0].y,&star[1].x,&star[1].y);

		bool in[2];

		for(int i=0;i<2;i++){

			int cnt=0;

			cnt+=ccw(a,b,star[i]);

			cnt+=ccw(b,c,star[i]);

			cnt+=ccw(c,a,star[i]);

			in[i]=(cnt==3*CCW || cnt==3*CW);

		}

		puts(in[0]==in[1]?"NG":"OK");

	}

	return 0;

}