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

	ll x = -3;

	REP(i, 101010){

		if(i*(i-1)==2*N) x = i;

	}

	if(x==-3){

		cout << "No" << endl;

		return 0;

	}else{

		vector<ll> res[x];

		ll tmp = 0;

		REP(i, x)REP(j, x){

			if(i>=j) continue;

			res[i].push_back(tmp);

			res[j].push_back(tmp);

			tmp++;

		}

		cout << "Yes" << endl;

		cout << x << endl;

		REP(i, x){

			cout << res[i].size() << " ";

			REP(j, res[i].size()){

				cout << res[i][j]+1 << " ";

			}

			cout << endl;

		}

	}

    return 0;

}