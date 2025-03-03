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

#include <unordered_map>

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

os<<"["; FOR(it,t) {if(it!=t.begin()) os<<","; os<<*it;} os<<"]"; return os;

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

	R EPS = 1e-8;

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

			// 座標の二乗とEPSの差が大きすぎないように注意

			return !sig(outp(p-at(0), dir())) && inp(p-at(0), dir()) > EPS && inp(p-at(1), -dir()) > -EPS;

			//return !sig(abs(at(0)-p) + abs(at(1) - p) - abs(at(0) - at(1)));

		}

	};

	struct C : public P{

		C(){}

		C(const P& p, const R r):P(p), r(r){}

		R r;

		BOOL inside(const P& p)const { return less(norm(p-SELF), r*r);}

	};

	struct F : public C{

		R s, t;

		F(const C &c, R ss, R tt):C(c), s(ss), t(tt){

			if(PI < s) s -= 2*PI;

			if(PI < t) t -= 2*PI;

		}

		BOOL inside(const P& p)const {

			P v = p - SELF;

			if(!sig(norm(v))) return BORDER;

			R a = arg(v);

			if(t < s){

				if((!less(s, a) && !less(a, t)) || !less(norm(v), r*r)) return FALSE;

				return less(s, a) | less(a, t) | less(norm(v), r*r);

			}else{

				if(!less(s, a) || !less(a, t) || !less(norm(v), r*r)) return FALSE;

				return less(s, a) | less(a, t) | less(norm(v), r*r);

			}

		}

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

		P gp()const {

			P r(.0, .0);

			REP(i, size()){

				const S &s = edge(i);

				r += (s[0]+s[1])*outp(s[0], s[1]);

			}

			return r / (6*area());

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

				const P m = (p[t]+p[i])*(R)0.5;

				g = g.cut(L(m, m+(p[i]-p[t])*P(0, 1)));

			}

			return g;

		}

	};



	inline P proj(const P &s, const L &t){return t[0] + proj(s-t[0], t[1]-t[0]);}

	inline P reflect(const P &s, const L &t){return (R)2.*proj(s, t) - s;}

	inline S reflect(const S &s, const L &t){return S(reflect(s[0], t), reflect(s[1], t));}

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

	inline P crosspoint(const L &l, const L &m){

		R A = outp(l.dir(), m.dir()), B = outp(l.dir(), l[1] - m[0]);

		if(!sig(abs(A)) && !sig(abs(B))) return m[0]; // same line

		if(abs(A) < EPS) assert(false); // !!!PRECONDITION NOT SATISFIED!!!

		return m[0] + B / A * (m[1] - m[0]);

	}



#undef SELF

#undef at

}



using namespace geom;



int f = 0;

namespace std{

	bool operator<(const P &a, const P &b){return sig(a.X-b.X) ? a.X < b.X : a.Y+EPS < b.Y;}

	bool operator==(const P &a, const P &b){return abs(a-b) < EPS;}

	istream& operator>>(istream &is, P &p){R x,y;is>>x>>y;p=P(x, y);return is;}

	istream& operator>>(istream &is, L &l){l.resize(2);return is >> l[0] >> l[1];}

	istream& operator>>(istream &is, C &c){return is >> (P &)c >> c.r;}

	const R B = 200;

	const R Z = .5;

	ostream& operator<<(ostream &os, const C &c){return os << "circle("<<B+Z*(c.X)<<", "<<1000-B-Z*(c.Y)<<", "<<Z*(c.r)<<")";}

	ostream& operator<<(ostream &os, const P &p){return os << C(p, 2./Z);}

	ostream& operator<<(ostream &os, const S &s){return os << "line("<<B+Z*(s[0].X)<<", "<<1000-B-Z*(s[0].Y)<<", "<<B+Z*(s[1].X)<<", "<<1000-B-Z*(s[1].Y)<<")";}

	ostream& operator<<(ostream &os, const G &g){REP(i, g.size()) os << g.edge(i) << endl;return os;}



}



int n, m;



vi path(S root, const vector<P>& pin){

	vi res;

	if(!sig(root.dir().X)) return res;

	REPS(i, n){

		P cp = crosspoint(root, L(pin[i], pin[i]+P(0, 1)));

		if(root.online(cp) == FALSE) continue;

		if(abs(root[0].X - cp.X) < EPS || abs(root[1].X - cp.X) < EPS) continue;

		res.push_back(pin[i].Y < cp.Y ? i : -i);

	}

	sort(ALL(res), [&](int i, int j){

		return abs(root[0].X - pin[abs(i)].X) < abs(root[0].X - pin[abs(j)].X);

	});

	return res;

}



int main(int argc, char *argv[]){

	ios::sync_with_stdio(false);

	int T = 1;

	while(cin >> m >> n, n){

		vector<P> root(m), pin(n+1);

		REP(i, m){

			cin >> root[i];

			root[i] *= polar((R)1, (R)1);

		}

		pin[0] = root[0];

		REPS(i, n){

			cin >> pin[i];

			pin[i] *= polar((R)1, (R)1);

		}

		sort(pin.begin()+1, pin.end());

		pin.push_back(root.back());

		vector<int> st;

		st.push_back(0);

		REP(i, m-1){

			S s(root[i], root[i+1]);

			vi isc = path(s, pin);

			FOR(it, isc){

				if(st.back() == *it) st.pop_back();

				else st.push_back(*it);

			}

		}

		st.push_back(n+1);

		

		vector<R> dp(st.size(), INF);

		vi prev(st.size());

		dp[0] = .0;

		int save = 0;

		REP(i, st.size()){

			if(i && st[i] == -st[i-1]){

				save = i;

				dp[i] = dp[i-1];

				prev[i] = prev[i-1];

				continue;

			}

			for(int j=save;j<i;j++){

				S r(pin[abs(st[j])], pin[abs(st[i])]);

				vi pt = path(r, pin);

				if([&](){

					for(int k=1;k<=pt.size()&&j+k<i;k++) if(pt[k-1] != st[j+k]) return 0;

					return 1;

				}()){

					if(chmin(dp[i], dp[j] + abs(r.dir()))){

						prev[i] = j;

					}

				}

			}

		}

		printf("%.10f\n", (double)dp.back());

	}

	return 0;

}