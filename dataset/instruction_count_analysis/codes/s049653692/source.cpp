#include"stdc++.h"

using namespace std;

typedef complex<double> point;

point p[5], q[5];

const double eps=1.0e-8;

namespace std{

    bool operator == (const point& a, const point& b) {

        return abs(a-b)<eps;

    }

}

struct line : public vector<point> {

    line() {}

    line(const point& a, const point& b) { push_back(a); push_back(b); }

};

struct Circle{

    point center;

    double radius;

    Circle(const point& c, const double& r):center(c),radius(r) {}

};

point unit(const point& v) { return v/abs(v);}

point ortho(const point& v) { return v*point(0,1);}

point spin(const point& v, const double &angle) {return v*point(cos(angle),sin(angle));}

inline point vec(const line& l) { return l[1]-l[0];}

inline double dot  (const point& a, const point& b) { return (a*conj(b)).real();}

inline double cross(const point& a, const point& b) { return (conj(a)*b).imag();}

point crosspoint(const line& l, const line& m) {

    double A = cross(vec(l), vec(m));

    double B = cross(vec(l), l[1]-m[0]);

    if(abs(A)<eps) {    /// parallel

        return m[0];    /// sameline

    }

    return m[0] + B/A*vec(m);

}

point O;

int cmp(const point& a, const point& b){

    return arg(a-O)<arg(b-O);

}

point solve(const point& x, const double& R, const double& angle, const line& p){

    double l=0, r=1, mid;

    point ret;

    while(l+eps<r){

        mid=(l+r)/2.0;

        double radius=abs(vec(p))*mid*sin(angle);

        point X=p[0]+abs(vec(p))*mid*unit(vec(p));

        if(abs(X-x)>R+radius) l=mid;

        else r=mid;

        ret=X;

    }

//    printf("mid=%f\n",mid);

    return ret;

}

int main(){

    point A, B, C;

    int ax, ay, bx, by, cx, cy;

    while(cin>>ax>>ay>>bx>>by>>cx>>cy&&(ax||ay||bx||by||cx||cy)){

        A=point(ax,ay); B=point(bx,by); C=point(cx,cy);

        O=(A+B+C)/(double)3.0;

        p[0]=A; p[1]=B; p[2]=C;

        q[0]=A; q[1]=B; q[2]=C;

        sort(p,p+3,cmp);

        A=p[0], B=p[1], C=p[2];

        line AB(A,B), BA(B,A), BC(B,C), CB(C,B), CA(C,A), AC(A,C); ///sides

        double a, b, c; ///angle

        double sa, sb, sc; ///side lengths

        sa=abs(B-C), sb=abs(A-C), sc=abs(A-B);

        a=acos((sb*sb+sc*sc-sa*sa)/(2*sb*sc));

        b=acos((sa*sa+sc*sc-sb*sb)/(2*sa*sc));

        c=acos((sb*sb+sa*sa-sc*sc)/(2*sb*sa));

        line AP(A,A+spin(vec(AB),a/2)), BP(B,B+spin(vec(BC),b/2)), CP(C,C+spin(vec(CA),c/2));

        point P=crosspoint(AP,BP); ///intersection

        AP=line(A,P); BP=line(B,P); CP=line(C,P);

        point lap=vec(AP);

        double l, r, mid;

        double ansx, ansy, ansz;

        double ans[5], ret[5];

        l=0, r=1;

        double vy, vz;

        while(l+eps<r){

            mid=(l+r)/2.0;

            point X=A+abs(lap)*mid*unit(lap);

            double radiusX=abs(lap)*mid*sin(a/2);

            Circle CX=Circle(X,radiusX);

            point Y, Z, Z2;

            Y=solve(X,radiusX,b/2,BP);

            Z=solve(X,radiusX,c/2,CP);

            double radiusY=abs(B-Y)*sin(b/2);

            Z2=solve(Y,radiusY,c/2,CP);

            if(abs(Z2-C)<abs(Z-C)){

                Z=Z2;

                l=mid;

            }

            else{

                r=mid;

            }

            double radiusZ=abs(C-Z)*sin(c/2);

            ansx=radiusX;

            ansy=radiusY;

            ansz=radiusZ;

        }

        ans[0]=ansx, ans[1]=ansy, ans[2]=ansz;

        for(int i=0; i<3; i++){

            if(p[i]==q[0]){

                ret[0]=ans[i];

            }

            else if(p[i]==q[1]){

                ret[1]=ans[i];

            }

            else if(p[i]==q[2]){

                ret[2]=ans[i];

            }

        }

        printf("%f %f %f\n",ret[0],ret[1],ret[2]);

    }

    return 0;

}