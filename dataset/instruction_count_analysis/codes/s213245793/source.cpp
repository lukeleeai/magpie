#include "stdc++.h"

using namespace std;

#define int long long   // <-----!!!!!!!!!!!!!!!!!!!



#define rep(i,n) for (int i=0;i<(n);++i)

#define rep2(i,a,b) for (int i=(a);i<(b);++i)

#define rrep(i,n) for (int i=(n)-1;i>=0;--i)

#define rrep2(i,a,b) for (int i=(a)-1;i>=b;--i)

#define chmin(a,b) (a)=min((a),(b));

#define chmax(a,b) (a)=max((a),(b));

#define all(a) (a).begin(),(a).end()

#define rall(a) (a).rbegin(),(a).rend()

#define printV(v) cout<<(#v)<<":";for(auto(x):(v)){cout<<" "<<(x);}cout<<endl;

#define printVS(vs) cout<<(#vs)<<":"<<endl;for(auto(s):(vs)){cout<<(s)<< endl;}

#define printVV(vv) cout<<(#vv)<<":"<<endl;for(auto(v):(vv)){for(auto(x):(v)){cout<<" "<<(x);}cout<<endl;}

#define printP(p) cout<<(#p)<<(p).first<<" "<<(p).second<<endl;

#define printVP(vp) cout<<(#vp)<<":"<<endl;for(auto(p):(vp)){cout<<(p).first<<" "<<(p).second<<endl;}



inline void output(){ cout << endl; }

template<typename First, typename... Rest>

inline void output(const First& first, const Rest&... rest) {

    cout << first << " "; output(rest...);

}



using ll = long long;

using Pii = pair<int, int>;

using TUPLE = tuple<int, int, int>;

using vi = vector<int>;

using vvi = vector<vi>;

using vvvi = vector<vvi>;

const int inf = 1e9;

const int mod = 1e9 + 7;

using Graph = vector<vector<int>>;



typedef complex<double> P;

typedef vector<P> G;

#define here(g, i) g[i]

#define next(g, i) g[(i + 1) % g.size()]

#define prev(g, i) g[(i - 1 + g.size()) % g.size()]

const double EPS = 1e-10;

const double INF = 1e12;

const double PI = acos(-1);



P readP() {

    double x, y;

    cin >> x >> y;

    return P(x, y);

}



struct L {

    P a, b, v, h;

    L(){}

    L(P _a, P _b) : a(_a), b(_b), v(b - a), h(v / abs(v) * P(0, 1)) {}

    // L(double _ax, double _ay, double _bx, double _by) : L(P(_ax, _ay), P(_bx, _by)) {}

    void trans(double d) {

        a += d * h;

        b += d * h;

    }

};



double cross(P a, P b) {

    return imag(conj(a) * b);

}



double dot(P a, P b) {

    return real(conj(a) * b);

}



int ccw(P p0, P p1, P p2) {

    p1 -= p0; p2 -= p0;

    if (cross(p1, p2) > 0) return +1;       // counter-clockwise

    if (cross(p1, p2) < 0) return -1;       // clockwise

    if (dot(p1, p2) < 0) return +2;         // p2 -- p0 -- p1

    if (norm(p1) < norm(p2)) return -2;     // p0 -- p1 -- p2

    return 0;                               // p0 -- p2 -- p1

}



P crosspointLL(L l1, L l2) {

    return l1.a + l1.v * cross(l2.v, l2.a - l1.a) / cross(l2.v, l1.v);

}



G convex_cut(G g, L l) {

    G h;

    rep(i, (int)g.size()) {

        P p = here(g, i), q = next(g, i);

        if (ccw(p, q, l.a) == 0 && ccw(p, q, l.b) == 0) {

            if (ccw(p, l.b, l.a) == 0) return g;    // p -- l.a -- l.b -- q

            else return G{};                        // p -- l.b -- l.a -- q

        }

        if (ccw(l.a, l.b, p) != -1) h.emplace_back(p);

        if (ccw(l.a, l.b, p) * ccw(l.a, l.b, q) < 0)

            h.emplace_back(crosspointLL(L(p, q), l));

    }

    return h;

}



bool check(double d, G g, vector<L> l) {

    int n = g.size();

    rep(i, n) {

        l[i].trans(d);

        g = convex_cut(g, l[i]);

    }

    return (int)g.size() >= 3;

}



main() {

    std::ios::sync_with_stdio(false);

    std::cin.tie(0);



    int testcase = 0;

    int n;

    while (cin >> n, n) {

        G g;

        rep(i, n) g.emplace_back(readP());

        vector<L> l;

        rep(i, n) {

            l.emplace_back(here(g, i), next(g, i));

        }



        double lb = 0, ub = 1e10;

        rep(_, 100) {

            double mid = (lb + ub) / 2;

            (check(mid, g, l) ? lb : ub) = mid;

        }



        cout << fixed << setprecision(10) << lb << endl;

    }

}