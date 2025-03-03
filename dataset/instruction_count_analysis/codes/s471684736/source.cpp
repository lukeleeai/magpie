#include "stdc++.h"

#define ll long long

#define INF 1000000005

#define MOD 1000000007

#define EPS 1e-10

#define rep(i,n) for(int i=0;i<n;++i)



using namespace std;



typedef complex<double> C;



namespace std

{

    bool operator < (const C& a, const C& b) {

        return real(a) != real(b) ? real(a) < real(b) : imag(a) < imag(b);

    }

}



struct L : public vector<C>

{

    L(const C &a, const C &b) {

        push_back(a); push_back(b);

    }

};



//??????

double cross(const C& a, const C& b)

{

    return imag(conj(a)*b);

}

//??????

double dot(const C& a, const C& b)

{

    return real(conj(a)*b);

}





int ccw(C a, C b, C c)

{

    b -= a; c -= a;

    if (cross(b, c) > 0)   return +1;       // counter clockwise

    if (cross(b, c) < 0)   return -1;       // clockwise

    if (dot(b, c) < 0)     return +2;       // c--a--b on line

    if (norm(b) < norm(c)) return -2;       // a--b--c on line

    return 0;

}

//??´???????????????????????????(????????´??????True)

bool intersectLL(const L &l, const L &m)

{

    return abs(cross(l[1]-l[0], m[1]-m[0])) > EPS || abs(cross(l[1]-l[0], m[0]-l[0])) < EPS;

}

//??´?????¨?????????????????????(????????±??????????????¨??????)

bool intersectLS(const L &l, const L &s)

{

    return cross(l[1]-l[0], s[0]-l[0]) * cross(l[1]-l[0], s[1]-l[0]) < EPS;

}

//??´?????¨????????????(??±???)??????

bool intersectLP(const L &l, const C &p)

{

    return abs(cross(l[1]-p, l[0]-p)) < EPS;

}

//??????????????????????????????(????????±??????????????¨??????)

bool intersectSS(const L &s, const L &t)

{

    return ccw(s[0],s[1],t[0])*ccw(s[0],s[1],t[1]) <= 0 && ccw(t[0],t[1],s[0])*ccw(t[0],t[1],s[1]) <= 0;

}

//????????¨????????????(??±???)??????

bool intersectSP(const L &s, const C &p)

{

    return abs(s[0]-p)+abs(s[1]-p)-abs(s[1]-s[0]) < EPS;

}

//???p?????´???l???????°???±

C projection(const L &l, const C &p)

{

    double t = dot(p-l[0], l[0]-l[1]) / norm(l[0]-l[1]);

    return l[0] + t*(l[0]-l[1]);

}

//???p?????´???l????????¨??????????§°?§????

C reflection(const L &l, const C &p)

{

    return p + (projection(l, p) - p)*2.0;

}

//?????¨??´???????????¢

double distanceLP(const L &l, const C &p)

{

    return abs(p - projection(l, p));

}

//??´?????¨??´???????????¢

double distanceLL(const L &l, const L &m)

{

    return intersectLL(l, m) ? 0 : distanceLP(l, m[0]);

}

//??´?????¨??????????????¢

double distanceLS(const L &l, const L &s)

{

    if (intersectLS(l, s)) return 0;

    return min(distanceLP(l, s[0]), distanceLP(l, s[1]));

}

//????????¨???????????¢

double distanceSP(const L &s, const C &p)

{

    const C r = projection(s, p);

    if (intersectSP(s, r)) return abs(r - p);

    return min(abs(s[0] - p), abs(s[1] - p));

}

//????????¨??????????????¢

double distanceSS(const L &s, const L &t)

{

    if (intersectSS(s, t)) return 0;

    return min(min(distanceSP(s, t[0]), distanceSP(s, t[1])),min(distanceSP(t, s[0]), distanceSP(t, s[1])));

}

//??´???????????????????????????

C crosspoint(const L &l, const L &m)

{

    double A = cross(l[1] - l[0], m[1] - m[0]);

    double B = cross(l[1] - l[0], l[1] - m[0]);

    //????????´????????¨???

    if(abs(A) < EPS && abs(B) < EPS){

        return m[0];

    }

    return m[0] + B / A * (m[1] - m[0]);

}

//?????????????????????

L crosspointSS(C &p1,int r1,C &p2,int r2)

{

    double d = norm(p2-p1);

    double t = r2*r2 - r1*r1 - d;

    double aa = d,bb = t*(real(p2)-real(p1)),cc = t*t / 4.0 - (imag(p2) - imag(p1))*(imag(p2) - imag(p1))*r1*r1;

    double x1 = (-bb - sqrt(bb*bb - 4*aa*cc))/(2*aa),x2 = (-bb + sqrt(bb*bb - 4*aa*cc))/(2*aa);

    double y1,y2;

    if(imag(p1) == imag(p2)){

        y1 = -sqrt(r1*r1 - x1*x1);

        y2 = -y1;

    }else{

        y1 = (t+2*(real(p2)-real(p1))*x1)/(-2*(imag(p2)-imag(p1)));

        y2 = (t+2*(real(p2)-real(p1))*x2)/(-2*(imag(p2)-imag(p1)));

    }

    L ln = L(C(x1+real(p1),y1+imag(p1)),C(x2+real(p1),y2+imag(p1)));

    return ln;

}

//??????????±???????

vector<C> convex_hull(vector<C> ps)

{

    int n = ps.size(), k = 0;

    sort(ps.begin(), ps.end());

    vector<C> ch(2*n);

    for (int i = 0; i < n; ch[k++] = ps[i++]){

        while (k >= 2 && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) k--;

    }

    for (int i = n-2, t = k+1; i >= 0; ch[k++] = ps[i--]){

        while (k >= t && ccw(ch[k-2], ch[k-1], ps[i]) <= 0) k--;

    }

    ch.resize(k-1);

    return ch;

}

//?????§??????

bool isconvex(const vector<C> &ps)

{

    rep(i,ps.size()){

        if (ccw(ps[(i+ps.size()-1) % ps.size()],ps[i],ps[(i+1) % ps.size()])) return false;

    }

    return true;

}

//????§???¢?????¢???

double area(const vector<C> &ps)

{

    double A = 0;

    rep(i,ps.size()){

        A += cross(ps[i],ps[(i+1) % ps.size()]);

    }

    return A / 2.0;

}

//???????§???¢?????´?????§???????????????????????´????????¢

vector<C> convex_cut(const vector<C> &ps, const L &l)

{

    vector<C> Q;

    rep(i,ps.size()){

        C A = ps[i], B = ps[(i+1)%ps.size()];

        if (ccw(l[0], l[1], A) != -1) Q.push_back(A);

        if (ccw(l[0], l[1], A)*ccw(l[0], l[1], B) < 0)

            Q.push_back(crosspoint(L(A, B), l));

    }

    return Q;

}

//??????????§???¢???????????????????????????(0??????????????????,1?????????,2???????????????)

int contains(const vector<C>& ps, const C& p)

{

    bool flag = false;

    rep(i,ps.size()) {

        C a = ps[i] - p, b = ps[(i+1)%ps.size()] - p;

        if (imag(a) > imag(b)) swap(a, b);

        if (imag(a) <= 0 && 0 < imag(b)){

            if (cross(a, b) < 0) flag = !flag;

        }

        if (cross(a, b) == 0 && dot(a, b) <= 0) return 1;

  }

  return flag ? 2 : 0;

}

//???????§???¢?????´???????±???????(?????£????????????)

//maxi,maxj?????????????????¨??????

double convex_diameter(const vector<C> &ps)

{

    const int n = ps.size();

    int is = 0, js = 0;

    for (int i = 1; i < n; ++i) {

        if (imag(ps[i]) > imag(ps[is])) is = i;

        if (imag(ps[i]) < imag(ps[js])) js = i;

    }

    double maxd = abs(ps[is]-ps[js]);

    int i, maxi, j, maxj;

    i = maxi = is;

    j = maxj = js;

    do{

        if (cross(ps[(i+1)%ps.size()]-ps[i],ps[(j+1)%ps.size()]-ps[j]) >= 0) j = (j+1) % n;

        else i = (i+1) % n;

        if (abs(ps[i]-ps[j]) > maxd) {

            maxd = abs(ps[i]-ps[j]);

            maxi = i; maxj = j;

        }

    } while (i != is || j != js);

    return maxd;

}



double closest_pair(C *a, int n){

    if(n<=1) return INF;

    int m=n/2;

    double x=a[m].real();

    double d=min(closest_pair(a,m),closest_pair(a+m,n-m));

    inplace_merge(a,a+m,a+n,[](C c1,C c2){return c1.imag() != c2.imag() ? c1.imag() < c2.imag() : c1.real() < c2.real();});

    vector<C> b;

    rep(i,n){

        if(abs(x-a[i].real())>=d) continue;

        rep(j,b.size()){

            C dp=a[i]-b[b.size()-1-j];

            if(dp.imag()>=d) break;

            d=min(d,abs(dp));

        }

        b.push_back(a[i]);

    }

    return d;

}

double compute_shortest(C *a,int n){

    sort(a,a+n);

    return closest_pair(a,n);

}



int main()

{

    int n;

    cin >> n;

    C p[100005];

    rep(i,n){

        double x,y;

        cin >> x >> y;

        p[i] = C(x,y);

    }

    printf("%.10f\n",compute_shortest(p,n));

}