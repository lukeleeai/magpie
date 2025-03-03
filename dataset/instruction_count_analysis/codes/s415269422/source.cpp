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

	ll N;

	cin >> N;

	REP(i, 3500)REP(j, 3500){

		ll h = i+1;

		ll n = j+1;

		ll x = N*h*n;

		ll y = 4*h*n - N*n - N*h;

		if(y<=0||x<y||x<=0) continue;

		if(x%y==0){

			printf("%d %d %d\n", h, n, x/y);

			return 0;

		}

	}

    return 0;

}
