#include <cstdio>

#include <cmath>

#include <algorithm>

#include <vector>

#include <iostream>

#include <complex>

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

#define RFOR(i,c) for(__typeof((c).rbegin())i=(c).rbegin();i!=(c).rend();i++)

#define ALL(container) (container).begin(), (container).end()

#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );



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

	inline int sig(const R &x) { return (abs(x) < EPS ? 0 : x > 0 ? 1 : -1); }

	inline BOOL less(const R &x, const R &y) {return sig(x-y) ? x < y : BORDER;}

	typedef complex<R> P;

	inline R norm(const P &p){return p.X*p.X+p.Y*p.Y;}

	inline R inp(const P& a, const P& b){return (conj(a)*b).X;}

	inline R outp(const P& a, const P& b){return (conj(a)*b).Y;}

	

	struct L : public vector<P>{	// line

		L(const P &p1, const P &p2){this->push_back(p1);this->push_back(p2);}

		L(){}

		P dir()const {return at(1) - at(0);}

		BOOL online(const P &p)const {return !sig(outp(p-at(0), dir()));}

	};

	struct S : public L{

		S(const P &p1, const P &p2):L(p1, p2){}

		S(){}

		BOOL online(const P &p)const {

			return inp(p-at(0), dir()) > EPS && inp(p-at(1), -dir()) > -EPS;

		}

	};

	inline P crosspoint(const L &l, const L &m){

		R A = outp(l.dir(), m.dir()), B = outp(l.dir(), l[1] - m[0]);

		if(!sig(abs(A)) && !sig(abs(B))) return m[0];

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

		dp[0] = .0;

		int save = 0;

		REP(i, st.size()){

			if(i && st[i] == -st[i-1]){

				save = i;

				dp[i] = dp[i-1];

				continue;

			}

			for(int j=save;j<i;j++){

				S r(pin[abs(st[j])], pin[abs(st[i])]);

				if(dp[i] < dp[j] + abs(r.dir())+EPS) continue;

				vi pt = path(r, pin);

				if([&](){

					for(int k=1;k<=pt.size()&&j+k<i;k++) if(pt[k-1] != st[j+k]) return 0;

					return 1;

				}()) dp[i] = dp[j] + abs(r.dir());

			}

		}

		printf("%.10f\n", (double)dp.back());

	}

	return 0;

}