#include "stdc++.h"

using namespace std;



typedef unsigned long long ull;

typedef long long ll;

typedef pair<int, int> pii;

typedef pair<ll, ll> pll;

typedef pair<double, double> pdd;

const ull mod = 1e9 + 7;

#define REP(i,n) for(int i=0;i<(int)n;++i)



//debug

#define dump(x)  cerr << #x << " = " << (x) << endl;

#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;



template < typename T >

void vprint(T &v){

	REP(i, v.size()){

		cout << v[i] << " ";

	}

	cout << endl;

}



int main(){

	ll N, A, B;

	cin >> N >> A >> B;

	vector<ll> h(N);

	REP(i, N) cin >> h[i];



	ll l = 0;

	ll u = 1e10;

	while(u-l>1){

		ll m = (l+u)/2;

		ll tmp = 0;

		REP(i, N){

			ll resid = h[i] - B*m;

			if(resid>0) tmp += ((resid+A-B-1)/(A-B));

		}

		if(tmp<=m) u = m;

		else l = m;

	}

	cout << u << endl;

    return 0;

}