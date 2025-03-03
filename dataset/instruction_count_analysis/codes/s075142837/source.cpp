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



const ll N_MAX = 202020;



struct RAQSB{

	ll N;

	ll sN;

	ll data[N_MAX];

	ll bucket[N_MAX];



	RAQSB(ll n){

		sN = (ll)sqrt(n) + 1;

		N = sN * sN;

		REP(i, N_MAX){

			data[i] = 0;

			bucket[i] = 0;

		}

	}



	void add(ll s, ll t, ll x){

		ll ss = s/sN;

		ll tt = t/sN;

		if(ss==tt){

			for(int i=s;i<t;i++){

				data[i] += x;

			}

		}else{

			for(int i=s;i<(ss+1)*sN;i++){

				data[i] += x;

			}

			for(int i=tt*sN;i<t;i++){

				data[i] += x;

			}

			for(int i=ss+1;i<tt;i++){

				bucket[i] += x;

			}

		}

	}



	ll get_val(ll i){

		return data[i] + bucket[i/sN];

	}

};



int main(){

	ll n, q;

	cin >> n >> q;

	RAQSB raqsb(n);

	REP(i, q){

		ll a, b, c, d;

		cin >> a;

		if(a==0){

			cin >> b >> c >> d;

			b--;c--;

			raqsb.add(b, c+1, d);

		}else{

			cin >> b;

			b--;

			cout << raqsb.get_val(b) << endl;

		}

	}

    return 0;

}
