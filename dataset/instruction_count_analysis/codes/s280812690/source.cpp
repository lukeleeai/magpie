#include <complex>

#include <cstdio>

#include <string>

#include <iostream>

#include <vector>

using namespace std;



#define loop(i,a,b) for(int i=(a);i<int(b);i++)

#define rep(i,b) loop(i,0,b)



typedef double R;



const R eps = 1e-8;

const R inf = 1e12;

typedef complex<R> P;

namespace std {

    bool operator < (const P& a, const P& b) {

        return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);

    }

}

R cross(const P& a, const P& b) {

    return imag(conj(a)*b);

}

R dot(const P& a, const P& b) {

    return real(conj(a)*b);

}



struct L : public vector<P> {

    L(const P &a = P(), const P &b = P()) {

        push_back(a); push_back(b);

    }

    // ax+by+c=0

    L(R a, R b, R c){

        if(fabs(a) < eps) *this = L(P(0,-c/b),P(1,-c/b));

        else if(fabs(b) < eps) *this = L(P(-c/a,0),P(-c/a,1));

        else *this = L(P(-c/a,0), P(0,-c/b));

    }

};



typedef vector<P> G;



struct C {

    P p; R r;

    C(const P &p, R r) : p(p), r(r) { }

    C(){}

};



// CCW

int ccw(P a, P b, P c) {

    b -= a; c -= a;

    if (cross(b, c) > 0)   return +1; // a->b->c 反時計回り

    if (cross(b, c) < 0)   return -1; // a->b->c 時計回り

    if (dot(b, c) < 0)     return +2; // c--a--b 直線上

    if (norm(b) < norm(c)) return -2; // a--b--c 直線上

    return 0; // 2点以上が重なっている

}



// 交差判定

bool isiLL(const L &l, const L &m) {

    return

        abs(cross(l[1]-l[0], m[1]-m[0])) > eps || // non-parallel

        abs(cross(l[1]-l[0], m[0]-l[0])) < eps;   // same line

}



bool isiLS(const L &l, const L &s) {

    return

        cross(l[1]-l[0], s[0]-l[0])*       // s[0] is left of l

        cross(l[1]-l[0], s[1]-l[0]) < eps; // s[1] is right of l

}



bool isiLP(const L &l, const P &p) {

    return abs(cross(l[1]-p, l[0]-p)) < eps;

}



bool isiSS(const L &s, const L &t) {

    return

        ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 &&

        ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;

}



bool isiSP(const L &s, const P &p) {

    return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < eps; // triangle inequality

}



bool isiCP(const C &c, const P &p) {

    // 境界または内部

    return abs(c.p - p) <= c.r + eps;

}



int isiCC(const C& c1, const C& c2){

    double d = abs(c1.p - c2.p), r1 = c1.r, r2 = c2.r;

    if(abs(d - r1 - r2) < eps) return  1; // 接する

    if(d > r1 + r2)       return  0; // 共通部分を持たない

    if(d < r1 - r2)       return +3; // c1 が c2 の中にある

    if(d < r2 - r1)       return -3; // c2 が c1 の中にある

    return 2; // 2つの交点を持つ

}



// 射影

P proj(const L &l, const P &p) {

    double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);

    return l[0] + t*(l[0]-l[1]);

}



// 反射

P refl(const L &l, const P &p) {

    return p + 2. * (proj(l, p) - p);

}



// 距離

R dLP(const L &l, const P &p) {

    return abs(p - proj(l, p));

}



R dLL(const L &l, const L &m) {

    return isiLL(l, m) ? 0 : dLP(l, m[0]);

}



R dLS(const L &l, const L &s) {

    if (isiLS(l, s)) return 0;

    return min(dLP(l, s[0]), dLP(l, s[1]));

}



R dSP(const L &s, const P &p) {

    const P r = proj(s, p);

    if (isiSP(s, r)) return abs(r - p);

    return min(abs(s[0] - p), abs(s[1] - p));

}



R dSS(const L &s, const L &t) {

    if (isiSS(s, t)) return 0;

    return min(min(dSP(s, t[0]), dSP(s, t[1])),

               min(dSP(t, s[0]), dSP(t, s[1])));

}



R dCP(const C &c, const P &p) {

    return max(0. , abs(c.p - p));

}



// 交点

vector<P> iLL(const L &l, const L &m) {

    R A = cross(l[1] - l[0], m[1] - m[0]);

    R B = cross(l[1] - l[0], l[1] - m[0]);

    if (abs(A) < eps && abs(B) < eps) return {m[0]}; // same line

    if (abs(A) < eps) throw "PRECONDITION NOT SATISFIED!!!";

    return {m[0] + B / A * (m[1] - m[0])};

}



vector<P> iSS(const L& s, const L& t) {

    if(isiSS(s,t)) return iLL(s,t);

    else return {};

}



vector<P> iLS(const L& l, const L& s){

    if(isiLS(l,s)) return iLL(l,s);

    else return {};

}



// !!! not verified !!!

vector<P> iCL(const C& c, const L& l){

    R d = dLP(l,c.p);

    // 接する

    if(abs(d-c.r) < eps) return { proj(l, c.p) };

    // 共有点を持たない

    if(d > c.r) return {};

    P h = proj(l, c.p);

    P v = h - c.p;

    P u = v * P(0,1) * sqrt(c.r*c.r - d*d) / abs(v);

    return {h+u, h-u};

}



// !!! not verified !!!

vector<P> iCC(const C& c1, const C& c2){

    int i = isiCC(c1,c2);

    // 共通部分なし || 内部

    if(i==0 || abs(i)==3) return {};

    R r1 = c1.r, r2 = c2.r, d = abs(c1.p - c2.p);

    // 接する

    if(i==1) return { c1.p + (c2.p - c1.p) * r1/d };

    // 2つの交点

    P p = c1.p - c2.p;

    R A = -2. * p.real(), B = -2. * p.imag();

    R C = norm(c1.p) - norm(c2.p) - r1*r1 + r2*r2;

    return iCL(c1, L(A,B,C));

}



int main(){

    int n;

    int cnt = 1;

    while(cin>>n && n){

        vector<C> cs(n);

        rep(i,n){

            int x,y,r;

            cin>>x>>y>>r;

            cs[i] = C(P(x,y),r);

        }

        vector<L> ls(n-1);

        rep(i,n-1){

            auto l = iCC(cs[i],cs[i+1]);

            ls[i] = L(l[0],l[1]);

        }



        int N=n*2;

        double d[N][N];

        rep(i,N)rep(j,N){

            if(i==j)d[i][j]=0;

            else d[i][j]=inf;

        }



        L st(cs[0].p,cs[n-1].p);

        bool okst = true;

        for(int i=0;i<n-1;i++){

            auto &ps = ls[i];

            P &p1=ps[0], &p2=ps[1];

            d[i*2][i*2+1] = abs(p1-p2);

            if(!isiSS(st,{p1,p2})) okst=false;

            for(int j=i+1;j<n-1;j++){

                auto &qs = ls[j];

                P &q1=qs[0], &q2=qs[1];

                L s11(p1,q1), s12(p1,q2), s21(p2,q1), s22(p2,q2);

                bool ok11 = true, ok12 = true, ok21 = true, ok22 = true;

                for(int k=i+1;k<=j-1;k++){

                    auto &rs = ls[k];

                    L s(rs[0],rs[1]);

                    if(!isiSS(s,s11))ok11=false;

                    if(!isiSS(s,s12))ok12=false;

                    if(!isiSS(s,s21))ok21=false;

                    if(!isiSS(s,s22))ok22=false;

                }

                if(ok11)d[i*2][j*2] = d[j*2][i*2] = abs(p1-q1);

                if(ok12)d[i*2][j*2+1] = d[j*2+1][i*2] = abs(p1-q2);

                if(ok21)d[i*2+1][j*2] = d[j*2][i*2+1] = abs(p2-q1);

                if(ok22)d[i*2+1][j*2+1] = d[j*2+1][i*2+1] = abs(p2-q2);

            }

            L s1(ps[0],cs[0].p);

            L s2(ps[1],cs[0].p);

            bool oks1 = true, oks2 = true;

            for(int j=0;j<i;j++){

                auto &t = ls[j];

                L s(t[0],t[1]);

                if(!isiSS(s,s1)) oks1 = false;

                if(!isiSS(s,s2)) oks2 = false;

            }

            if(oks1)d[N-1][i*2] = d[i*2][N-1] = abs(s1[0]-s1[1]);

            if(oks2)d[N-1][i*2+1] = d[i*2+1][N-1] = abs(s2[0]-s2[1]);

            L t1(ps[0],cs[n-1].p);

            L t2(ps[1],cs[n-1].p);

            bool okt1 = true, okt2 = true;

            for(int j=i+1;j<n-1;j++){

                auto t = ls[j];

                L s(t[0],t[1]);

                if(!isiSS(s,t1)) okt1 = false;

                if(!isiSS(s,t2)) okt2 = false;

            }

            if(okt1)d[N-2][i*2] = d[i*2][N-2] = abs(t1[0]-t1[1]);

            if(okt2)d[N-2][i*2+1] = d[i*2+1][N-2] = abs(t2[0]-t2[1]);

        }

        if(okst)d[N-1][N-2] = d[N-2][N-1] = abs(st[0]-st[1]);

        rep(k,N)rep(i,N)rep(j,N)d[i][j] = min(d[i][j],d[i][k]+d[k][j]);

        printf("%.4lf\n",d[N-1][N-2]);



        string name = "pCase" + to_string(cnt++) + ".png";

    }

}