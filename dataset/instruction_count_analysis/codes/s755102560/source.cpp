#include <cstdio>

#include <cmath>

#include <cstring>

#include <cstdlib>

#include <climits>

#include <ctime>

#include <queue>

#include <stack>

#include <algorithm>

#include <list>

#include <vector>

#include <set>

#include <map>

#include <iostream>

#include <deque>

#include <complex>

#include <string>

#include <iomanip>

#include <sstream>

#include <bitset>

#include <valarray>

#include <iterator>

#include <assert.h>

using namespace std;

typedef long long int ll;

typedef unsigned int uint;

typedef unsigned char uchar;

typedef unsigned long long ull;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;

typedef vector<int> vi;



#define REP(i,x) for(int i=0;i<(int)(x);i++)

#define REPS(i,x) for(int i=1;i<=(int)(x);i++)

#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)

#define RREPS(i,x) for(int i=((int)(x));i>0;i--)

#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)

#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)

#define ALL(container) (container).begin(), (container).end()

#define RALL(container) (container).rbegin(), (container).rend()

#define SZ(container) ((int)container.size())

#define mp(a,b) make_pair(a, b)

#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );



template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }

template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }

template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {

FOR(it,t) os << *it << endl; return os;

}

template<class T> ostream& operator<<(ostream &os, const set<T> &t) {

os<<"{"; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"}"; return os;

}

template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

template<class S, class T> pair<S,T> operator+(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first+t.first, s.second+t.second);}

template<class S, class T> pair<S,T> operator-(const pair<S,T> &s, const pair<S,T> &t){ return pair<S,T>(s.first-t.first, s.second-t.second);}



namespace geom{

#define X real()

#define Y imag()

#define at(i) ((*this)[i])

#define SELF (*this)

	enum {TRUE = 1, FALSE = 0, BORDER = -1};

	typedef int BOOL;

	typedef double R;

	const R INF = 1e8;

	const R EPS = 1e-12;

	const R PI = 3.1415926535897932384626;

	inline int sig(const R &x) { return (abs(x) < EPS ? 0 : x > 0 ? 1 : -1); }

	inline BOOL less(const R &x, const R &y) {return sig(x-y) ? x < y : BORDER;}

	typedef complex<R> P;

	inline R norm(const P &p){return p.X*p.X+p.Y*p.Y;}

	inline R inp(const P& a, const P& b){return (conj(a)*b).X;}

	inline R outp(const P& a, const P& b){return (conj(a)*b).Y;}

	inline P unit(const P& p){return p/abs(p);}

	inline P proj(const P &s, const P &t){return t*inp(s, t)/norm(t);}

	inline int ccw(const P &s, const P &t, const P &p, int adv=0){

		int res = sig(outp(t-s, p-s));

		if(res || !adv) return res;

		if(sig(inp(t-s, p-s)) < 0) return -2;	// p-s-t

		if(sig(inp(s-t, p-t)) < 0) return 2;	// s-t-p

		return 0;								// s-p-t

	}

	

	

	struct L : public vector<P>{	// line

		L(const P &p1, const P &p2){this->push_back(p1);this->push_back(p2);}

		L(){}

		P dir()const {return at(1) - at(0);}

		BOOL online(const P &p)const {return !sig(outp(p-at(0), dir()));}

	};

	struct S : public L{	// segment

		S(const P &p1, const P &p2):L(p1, p2){}

		S(){}

		BOOL online(const P &p)const {

			if(!sig(norm(p - at(0))) || !sig(norm(p - at(1)))) return BORDER;

			return !sig(abs(at(0)-p) + abs(at(1) - p) - abs(at(0) - at(1)));

		}

	};

	struct C : public P{

		R r;

		BOOL inside(const P& p)const { return less(norm(p-SELF), r*r);}

	};

	P crosspoint(const L &l, const L &m);

	struct G : public vector<P>{

		G(size_type size=0):vector(size){}

		S edge(int i)const {return S(at(i), at(i+1 == size() ? 0 : i+1));}

		BOOL contains(const P &p)const {

			R sum = .0;

			REP(i, size()){

				if(S(at(i), at((i+1)%size())).online(p)) return BORDER;	// online

				sum += arg((at(i) - p) / (at((i+1)%size()) - p));

			}

			return !!sig(sum);

		}

		R area()const {

			R sum = 0;

			REP(i, size()) sum += outp(at(i), at((i+1)%size()));

			return abs(sum / 2.);

		}

		

		G convex_hull(bool online = false) {

			if(size() < 2) return *this;

			sort(ALL(*this));

			G r;

			r.resize((int)size()*2);

			int k=0;

			for(int i=0;i<size();r[k++]=at(i++))

				while(k>1 && ccw(r[k-2], r[k-1], at(i)) < 1-online) k--;

			int t = k;

			for(int i=(int)size()-1;i>=0;r[k++]=at(i--))

				while(k>t && ccw(r[k-2], r[k-1], at(i)) < 1-online) k--;

			r.resize(k-1);

			return r;

		}

		G cut(const L &l)const {

			G g;

			REP(i, size()){

				const S &s = edge(i);

				if(ccw(l[0], l[1], s[0], 0) >= 0) g.push_back(s[0]);

				if(ccw(l[0], l[1], s[0], 0) * ccw(l[0], l[1], s[1], 0) < 0)

					g.push_back(crosspoint(s, l));

			}

			return g;

		}

		G Voronoi(const vector<P> &p, const int t)const {

			G g = *this;

			REP(i, p.size())if(i!=t){

				const P m = (p[t]+p[i])*0.5;

				g = g.cut(L(m, m+(p[i]-p[t])*P(0, 1)));

			}

			return g;

		}

	};



	inline P proj(const P &s, const L &t){return t[0] + proj(s-t[0], t[1]-t[0]);}

	BOOL intersect(const S &s, const S &t){

		const int p = ccw(t[0], t[1], s[0], 1) * ccw(t[0], t[1], s[1], 1);

		const int q = ccw(s[0], s[1], t[0], 1) * ccw(s[0], s[1], t[1], 1);

		return (p>0||q>0) ? FALSE : (!p||!q) ? BORDER : TRUE;

	}

	BOOL intersect(const S &s, const L &l){

		if(l.online(s[0]) || l.online(s[1])) return BORDER;

		return (sig(outp(l.dir(), s[0]-l[0])) * sig(outp(l.dir(), s[1]-l[0])) <= 0);

	}

	R dist2(const L &l, const P &p){return norm(outp(l.dir(), p - l[0])) / norm(l.dir());}

	R dist2(const S &s, const P &p){

		if(inp(p-s[0],  s.dir()) < EPS) return norm(p - s[0]);

		if(inp(p-s[1], -s.dir()) < EPS) return norm(p - s[1]);

		return dist2((const L &)s, p);

	}

	R dist2(const S &s, const L &l){

		return intersect(s, l) ? .0 : min(dist2(l, s[0]), dist2(l, s[1]));

	}

	R dist2(const S &s, const S &t){

		return intersect(s, t) ? .0 : min(min(dist2(s, t[0]), dist2(t, s[0])), 

									   	  min(dist2(s, t[1]), dist2(t, s[1])));

	}

	template <class T> R dist2(const G &g, const T& t){ // todo: 内部に完全に含まれる場合

		R res = INF;

		REP(i, g.size()) res = min(res, dist2(g.edge(i), t));

		return res;

	}

	template<class S, class T> R dist(const S& s, const T& t){return sqrt(dist2(s, t));}

	inline BOOL intersect(const C &a, const C &b){

		return less((a.r-b.r)*(a.r-b.r), norm(a-b)) + less(norm(a-b), (a.r+b.r)*(a.r+b.r)) - 1;

	}

	inline BOOL intersect(const C &c, const L &l){

		return less(dist2(l, c), c.r*c.r);

	}

	inline BOOL intersect(const C &c, const S &s){

		int d = less(dist2(s, c), c.r*c.r);

		if(d != TRUE) return d;

		int p = c.inside(s[0]), q = c.inside(s[1]);

		return (p<0 || q<0) ? BORDER : p&q;

	}

	inline S crosspoint(const C &c1, const C &c2){

		if(!intersect(c1, c2)) return S();

		R d = abs(c1 - c2);

		R x = (c1.r*c1.r - c2.r*c2.r + d*d) / (2*d);

		R h = sqrt(c1.r*c1.r - x*x);

		P u = unit(c2-c1);

		return S(c1 + u*x + u*P(0,1)*h, c1 + u*x + u*P(0,-1)*h);

	}

	inline P crosspoint(const L &l, const L &m){

		R A = outp(l.dir(), m.dir()), B = outp(l.dir(), l[1] - m[0]);

		if(!sig(abs(A)) && !sig(abs(B))) return m[0]; // same line

		if(abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!

		return m[0] + B / A * (m[1] - m[0]);

	}

	inline R commonarea(const C &a, const C &b){

		if(less(norm(a-b), (a.r-b.r)*(a.r-b.r)) == TRUE) return min(a.r*a.r, b.r*b.r)*PI;

		if(less((a.r+b.r)*(a.r+b.r), norm(a-b)) == TRUE) return .0;

		double d = abs(a-b);

		double rc = (d*d + a.r*a.r - b.r*b.r) / (2*d);

		double theta = acos(rc / a.r);

		double phi = acos((d - rc) / b.r);

		return a.r*a.r*theta + b.r*b.r*phi - d*a.r*sin(theta);

	}

	struct Arrangement{

		struct AEdge{

			int u, v, t;

			R cost;

			AEdge(int u=0, int v=0, int t=0, R cost=0)

				:u(u), v(v), t(t), cost(cost){}

		};

		typedef vector<vector<AEdge>> AGraph;

		vector<P> p;

		AGraph g;

		Arrangement(){}

		Arrangement(vector<S> seg){

			int m = seg.size();

			REP(i, m){

				p.push_back(seg[i][0]);

				p.push_back(seg[i][1]);

				REP(j, i) if(sig(outp(seg[i].dir(), seg[j].dir())) && intersect(seg[i], seg[j]) == TRUE)

					p.push_back(crosspoint(seg[i], seg[j]));

			}

			sort(ALL(p)); UNIQUE(p);

			int n=p.size();

			g.resize(n);

			REP(i, m){

				S &s = seg[i];

				vector<pair<R, int>> ps;

				REP(j, n) if(s.online(p[j])) ps.emplace_back(norm(p[j] - s[0]), j);

				sort(ALL(ps));

				REP(j, (int)ps.size()-1){

					const int u=ps[j].second;

					const int v=ps[j+1].second;

					g[u].emplace_back(u, v, 0, abs(p[u] - p[v]));

					g[v].emplace_back(v, u, 0, abs(p[u] - p[v]));

				}

			}

		}

		

		int getIdx(P q){

			auto it = lower_bound(ALL(p), q);

			if(it == p.end() || *it != q) return -1;

			return it - p.begin();

		}

	};

#undef SELF

#undef at

}



using namespace geom;



namespace std{

	bool operator<(const P &a, const P &b){return sig(a.X-b.X) ? a.X < b.X : a.Y < b.Y;}

	istream& operator>>(istream &is, P &p){R x,y;is>>x>>y;p=P(x, y);return is;}

	istream& operator>>(istream &is, L &l){l.resize(2);return is >> l[0] >> l[1];}

	istream& operator>>(istream &is, C &c){return is >> (P &)c >> c.r;}

}



int n, m;

main(){

	while(cin >> n, n){

		G g(n);

		REP(i, n) cin >> g[i];

		R l=0, r=100000;

		REP(itr, 80){

			R m = (l+r)*.5;

			if([&](){

				G gg = g;

				REP(i, n){

					S s=g.edge(i);

					P d = unit(s.dir())*P(0, 1)*m;

					s[0] += d; s[1] += d;

					gg = gg.cut(s);

				}

				return gg.size();

			}()) l=m;

			else r=m;

		}

		printf("%.9f\n", r);

	}

	return 0;

}