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

#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)

#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)

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



const int MOD = 1000000007;





namespace geom{

#define X real()

#define Y imag()

#define at(i) ((*this)[i])

#define SELF (*this)

	enum {TRUE = 1, FALSE = 0, BORDER = -1};

	typedef int BOOL;

	typedef double R;

	const R INF = 1e8;

	const R EPS = 1e-8;

	inline int sig(const R &x) { return (abs(x) < EPS ? 0 : x > 0 ? 1 : -1); }

	inline BOOL less(const R &x, const R &y) {return sig(x-y) ? x < y : BORDER;}

	typedef complex<R> P;

	istream& operator>>(istream &is, P &p) {

		R x, y;

		is >> x >> y;

		p = P(x, y);

		return is;

	}

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

		friend istream& operator>>(istream &is, L &l) {

			P p1, p2;

			is >> p1 >> p2;

			l = L(p1, p2);

			return is;

		}

		friend inline P proj(const P &s, const L &t){return t[0] + proj(s-t[0], t[1]-t[0]);}

		BOOL online(const P &p)const {return !sig(outp(p-at(0), dir()));}

		R distance(const P &p)const {return abs(outp(dir(), p - at(0))) / abs(dir());}

	};

	struct S : public L{	// segment

		S(const P &p1, const P &p2):L(p1, p2){}

		S(){}

		BOOL online(const P &p)const {

			if(!sig(abs(p - at(0))) || !sig(abs(p - at(1)))) return BORDER;

			return !sig(abs(at(0)-p) + abs(at(1) - p) - abs(at(0) - at(1)));

		}

		R distance(const P &p)const {

			if(inp(p-at(0),  dir()) < EPS) return abs(p - at(0));

			if(inp(p-at(1), -dir()) < EPS) return abs(p - at(1));

			return L::distance(p);

		}

		BOOL intersect(const S &s)const {

//			if(online(s[0]) || online(s[0]) || s.online(at(0)) || s.online(at(1))) return BORDER;

			return (ccw(at(0), at(1),  s[0], 1) * ccw(at(0), at(1),  s[1], 1) <= 0 &&

					ccw( s[0],  s[1], at(0), 1) * ccw( s[0],  s[1], at(1), 1) <= 0);

		}

		BOOL intersect(const L &l)const {

			if(l.online(at(0)) || l.online(at(1))) return BORDER;

			return (sig(outp(l.dir(), at(0)-l[0])) * sig(outp(l.dir(), at(1)-l[0])) <= 0);

		}

		R distance(const L &l)const {

			if(intersect(l)) return .0;

			return min(l.distance(at(0)), l.distance(at(1)));

		}

		R distance(const S &s)const {

			if(intersect(s)) return .0;

			return min(min(s.distance(at(0)), s.distance(at(1))), 

					   min(distance(s[0]), distance(s[1])));

		}

	};

	

	struct C : public P{

		R r;

		friend istream& operator>>(istream &is, C &c) {

			operator>>(is, (P &)c);

			is >> c.r;

			return is;

		}

		BOOL inside(const P& p)const { return less(norm(p-SELF), r*r);}

	};

	inline BOOL cc_intersect(const C &a, const C &b){

		return less(abs(a.r-b.r), abs(a-b)) + less(abs(a-b), a.r+b.r) - 1;

//		if(!sig(abs(a-b) - (a.r+b.r) || !sig(abs(a-b) - abs(a.r - b.r)))) return BORDER;

//		return abs(a-b)<a.r+b.r && abs(a-b)>abs(a.r - b.r);

	}

	inline int cl_intersect(const C &c, const L &l){

		return less(l.distance(c), c.r);

	}

	inline int cs_intersect(const C &c, const S &s){

		int d = less(s.distance(c), c.r);

		if(d != TRUE) return d;

		int p = c.inside(s[0]), q = c.inside(s[1]);

		return (p<0 || q<0) ? BORDER : p&q;

	}

	inline S cc_crosspoint(const C &c1, const C &c2){

		if(!cc_intersect(c1, c2)) return S();

		R d = abs(c1 - c2);

		R x = (c1.r*c1.r - c2.r*c2.r + d*d) / (2*d);

		R h = sqrt(c1.r*c1.r - x*x);

		P u = unit(c2-c1);

		return S(c1 + u*x + u*P(0,1)*h, c1 + u*x + u*P(0,-1)*h);

	}

	struct G : public vector<P>{

		S edge(int i)const {return S(at(i), at(i+1 == size() ? 0 : i+1));}

		BOOL contains(const P &p)const {

			R sum = .0;

			REP(i, size()){

				if(S(at(i), at((i+1)%size())).online(p)) return BORDER;	// online

				sum += arg((at(i) - p) / (at((i+1)%size()) - p));

			}

			return !!sig(sum);

		}

		BOOL contains(const S &s)const {return contains(s[0]) && contains(s[1]);}

		BOOL contains(const L &l)const {return false;}

		BOOL contains(const C &c)const {

			if(!contains((P)c)) return FALSE;

			R sum = .0;

			int res = TRUE;

			REP(i, size()){

				if(c.inside(at(i)) == TRUE || less(edge(i).distance(c), c.r) == TRUE) return FALSE;

				else res |= c.inside(at(i)) | less(edge(i).distance(c), c.r);

			}

			return res;

		}

		template <class T> R distance(const T& t){

			if(contains(t)) return .0;

			R res = INF;

			REP(i, size()){

				res = min(res, edge(i).distance(t));

			}

			return res;

		}

		R area(){

			R sum = 0;

			REP(i, size()) sum += outp(at(i), at((i+1)%size()));

			return abs(sum / 2.);

		}

		

		G convex_hull(bool online = false){

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

};

#undef SELF

#undef at

}



using namespace geom;



namespace std{

	bool operator<(const geom::P &a, const geom::P &b) {

	    if (!geom::sig(a.X-b.X)) return (a.Y < b.Y);

	    return (a.X < b.X);

	}

}



int n, m;



int main(){

	ios::sync_with_stdio(false);

	while(cin >> n, n){

		vector<S> s;

		C prev;

		REP(i, n){

			C c;

			cin >> c;

			if(i == 0) s.emplace_back(c, c);

			else{

				s.push_back(cc_crosspoint(c, prev));

			}

			prev = c;

		}

		s.emplace_back(prev, prev);

		n = s.size() - 1;

		vector<vector<R>> dp(n+1, vector<R>(2, INF));

		dp[0][0] = dp[0][1] = .0;

		REPS(i, n)REP(j, i)REP(ik, 2)REP(jk, 2){

			S t(s[j][jk], s[i][ik]);

			if([&](){

				for(int k=j+1;k<i;k++)

					if(!t.intersect(s[k])) return false;

				return true;

			}() == false) continue;

			dp[i][ik] = min(dp[i][ik], dp[j][jk] + abs(t.dir()));

		}

		printf("%.4f\n", dp[n][0]);

	}

	return 0;

}